#pragma once

#if defined(PFM_WIN)
#include <Windows.h>
#endif

#include "GL/GL.h"
#include "vendor/glext.h"

// @Note: Lets cast some X macro spells...

#define FOR_GL_FUNCTIONS(DO) \
    DO(PFNGLDEBUGMESSAGECALLBACKPROC,      glDebugMessageCallback)      \
    DO(PFNGLCREATESHADERPROC,              glCreateShader)              \
    DO(PFNGLDELETESHADERPROC,              glDeleteShader)              \
    DO(PFNGLSHADERSOURCEPROC,              glShaderSource)              \
    DO(PFNGLCOMPILESHADERPROC,             glCompileShader)             \
    DO(PFNGLGETSHADERIVPROC,               glGetShaderiv)               \
    DO(PFNGLGETSHADERINFOLOGPROC,          glGetShaderInfoLog)          \
    DO(PFNGLCREATEPROGRAMPROC,             glCreateProgram)             \
    DO(PFNGLDELETEPROGRAMPROC,             glDeleteProgram)             \
    DO(PFNGLATTACHSHADERPROC,              glAttachShader)              \
    DO(PFNGLLINKPROGRAMPROC,               glLinkProgram)               \
    DO(PFNGLGETPROGRAMIVPROC,              glGetProgramiv)              \
    DO(PFNGLGETPROGRAMINFOLOGPROC,         glGetProgramInfoLog)         \
    DO(PFNGLUSEPROGRAMPROC,                glUseProgram)                \
    DO(PFNGLGETUNIFORMLOCATIONPROC,        glGetUniformLocation)        \
    DO(PFNGLUNIFORM1IVPROC,                glUniform1iv)                \
    DO(PFNGLCREATEBUFFERSPROC,             glCreateBuffers)             \
    DO(PFNGLDELETEBUFFERSPROC,             glDeleteBuffers)             \
    DO(PFNGLNAMEDBUFFERDATAPROC,           glNamedBufferData)           \
    DO(PFNGLNAMEDBUFFERSUBDATAPROC,        glNamedBufferSubData)        \
    DO(PFNGLCREATEVERTEXARRAYSPROC,        glCreateVertexArrays)        \
    DO(PFNGLDELETEVERTEXARRAYSPROC,        glDeleteVertexArrays)        \
    DO(PFNGLVERTEXARRAYELEMENTBUFFERPROC,  glVertexArrayElementBuffer)  \
    DO(PFNGLVERTEXARRAYVERTEXBUFFERPROC,   glVertexArrayVertexBuffer)   \
    DO(PFNGLENABLEVERTEXARRAYATTRIBPROC,   glEnableVertexArrayAttrib)   \
    DO(PFNGLVERTEXARRAYATTRIBFORMATPROC,   glVertexArrayAttribFormat)   \
    DO(PFNGLVERTEXARRAYATTRIBIFORMATPROC,  glVertexArrayAttribIFormat)  \
    DO(PFNGLVERTEXARRAYATTRIBBINDINGPROC,  glVertexArrayAttribBinding)  \
    DO(PFNGLVERTEXARRAYBINDINGDIVISORPROC, glVertexArrayBindingDivisor) \
    DO(PFNGLBINDVERTEXARRAYPROC,           glBindVertexArray)           \
    DO(PFNGLBINDBUFFERBASEPROC,            glBindBufferBase)            \
    DO(PFNGLCREATETEXTURESPROC,            glCreateTextures)            \
    DO(PFNGLTEXTURESTORAGE2DPROC,          glTextureStorage2D)          \
    DO(PFNGLTEXTURESUBIMAGE2DPROC,         glTextureSubImage2D)         \
    DO(PFNGLTEXTUREPARAMETERIPROC,         glTextureParameteri)         \
    DO(PFNGLBINDTEXTUREUNITPROC,           glBindTextureUnit)           \

// @Note: We define GL_PROCS_NO_EXTERN just in one translation unit (gl_context.cpp)
// So that the compiler knows that which is the impl file, and which ones are just declaration files.

#ifndef GL_PROCS_NO_EXTERN
    #define DO_DECLARATIONS(_SIGNATURE, _NAME) \
        extern _SIGNATURE _NAME;
#else
    #define DO_DECLARATIONS(_SIGNATURE, _NAME) \
        _SIGNATURE _NAME = nullptr; 
#endif

FOR_GL_FUNCTIONS(DO_DECLARATIONS)

// @Note: Helper functions

inline fn glCompileShaderWithPrefix(std::string_view source, std::string_view prefix, GLenum type) -> GLuint
{
    GLuint shader = glCreateShader(type);

    cstring sources[2];
    i32 lenghts[2];

    sources[0] = prefix.data();
    lenghts[0] = static_cast<i32>(prefix.length());
    
    sources[1] = source.data();
    lenghts[1] = static_cast<i32>(source.length());

    glShaderSource(shader, 2, sources, lenghts);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        // @Pending: Wrap this stuff into a macro.
        internal constexpr GLsizei LOG_BUFFER_SIZE = 512;
        GLchar log_buffer[LOG_BUFFER_SIZE];
        GLsizei log_lenght;
        glGetShaderInfoLog(shader, LOG_BUFFER_SIZE, &log_lenght, log_buffer);
        LOG("Error compiling the program.\n%s", std::string_view(log_buffer, log_lenght).data());
        return 0u;
    }

    return shader;
}

inline fn glCreateProgramFromSource(std::string_view source) -> GLuint
{
    if (source.empty())
    {
        LOG("Error! The shader source cannot be empty!\n");
        return 0u;
    }
    
    internal constexpr cstring vert_prefix =
        "#version 460 core \n"
        "#define VERTEX_SHADER \n";
    
    GLuint vert = glCompileShaderWithPrefix(source, vert_prefix, GL_VERTEX_SHADER);

    if (vert == 0u)
    {
        LOG("Error compiling the vertex shader.\n");
        return 0u;
    }

    internal constexpr cstring frag_prefix =
        "#version 460 core \n"
        "#define FRAGMENT_SHADER \n";

    GLuint frag = glCompileShaderWithPrefix(source, frag_prefix, GL_FRAGMENT_SHADER);

    if (frag == 0u)
    {
        LOG("Error compiling the fragment shader.\n");
        return 0u;
    }
    
    // @Note: From here we create the program and link the shaders.

    GLuint prog = glCreateProgram();

    glAttachShader(prog, vert);
    glAttachShader(prog, frag);

    glLinkProgram(prog);

    glDeleteShader(vert);
    glDeleteShader(frag);
    
    GLint success;
    glGetProgramiv(prog, GL_LINK_STATUS, &success);

    if (success == GL_FALSE)
    {
        internal constexpr GLsizei LOG_BUFFER_SIZE = 512;
        GLchar log_buffer[LOG_BUFFER_SIZE];
        GLsizei log_lenght;
        glGetProgramInfoLog(prog, LOG_BUFFER_SIZE, &log_lenght, log_buffer);
        LOG("Error linking the program.\n%s", std::string_view(log_buffer, log_lenght).data());
        return 0u;
    }
    
    return prog;
}

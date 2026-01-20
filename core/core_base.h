#pragma once

using cstring = const char*;
using cwstring = const wchar_t*;

using i8 = signed char;
using i16 = short;
using i32 = int;
using i64 = long long;

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

using f32 = float;
using f64 = double;

namespace Limits
{
    inline constexpr i8  I8_Min = -127i8 - 1;
    inline constexpr i16 I16_Min = -32767i16 - 1;
    inline constexpr i32 I32_Min = -2147483647i32 - 1;
    inline constexpr i64 I64_Min = -9223372036854775807i64 - 1;

    inline constexpr i8  I8_Max = 127i8;
    inline constexpr i16 I16_Max = 32767i16;
    inline constexpr i32 I32_Max = 2147483647i32;
    inline constexpr i64 I64_Max = 9223372036854775807i64;

    inline constexpr u8  U8_Max = 0xffui8;
    inline constexpr u16 U16_Max = 0xffffui16;
    inline constexpr u32 U32_Max = 0xffffffffui32;
    inline constexpr u64 U64_Max = 0xffffffffffffffffui64;

    inline constexpr f32 F32_Max = 3.40282347e+38f;
    inline constexpr f32 F32_Min = -3.40282347e+38f;

    inline constexpr f64 F64_Max = 1.7976931348623157e+308;
    inline constexpr f64 F64_Min = -1.7976931348623157e+308;
}

#ifdef _WIN32
	#ifdef _WIN64
        #define CORE_WIN
	#else
        #error "x86 Builds are not supported!"
    #endif
#else
    #error "Unsupported OS!"
#endif

#if defined (CORE_DEBUG) || defined(CORE_RELEASE)
    #if defined(CORE_WIN)
        #define core_debug_break() __debugbreak()
    #else
        #define core_debug_break()
    #endif
    #define core_log(...) core_internal_log(__VA_ARGS__)
    #define core_ensure(X, ...) (core_internal_ensure(X, __VA_ARGS__))
    #define core_check(X, ...) (core_internal_check(X, __VA_ARGS__))
    
    auto core_internal_log(cstring fmt, ...) -> void;

    template<typename T, typename... TArgs>
    auto core_internal_check(T&& expr, cstring fmt, TArgs&&... args)
    {
        if (!expr)
        {
            core_internal_log(fmt, std::forward<TArgs>(args)...);
            core_debug_break();
        }
    }

    template<typename T, typename... TArgs>
    auto core_internal_ensure(T&& expr, cstring fmt, TArgs&&... args) -> T&&
    {
        core_internal_check(std::forward<T>(expr), fmt, std::forward<T>(args)...);
        return std::forward<T>(expr);
    }

#else
    #define core_check(X, ...)
    #define core_debug_break()
    #define core_ensure(X, ...) (X)
    #define core_log(...) 
#endif

auto core_read_entire_file(std::string_view filename) -> std::string;
// @Note: This is relative to the exe path. Ex: "\\..\\..\\assets" would set the wdir two folders up the exe, inside the assets dir.
auto core_working_dir_set(const std::string& path) -> void;
auto core_time() -> f64;
auto core_trim(std::string text) -> std::string;

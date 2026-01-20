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
    #define core_log(...) Core::log(__VA_ARGS__)
    #define core_ensure(X, ...) (Core::ensure(X, __VA_ARGS__))
    #define core_check(X, ...) (Core::check(X, __VA_ARGS__))
    
namespace Core
{
    auto log(cstring fmt, ...) -> void;

    template<typename T, typename... TArgs>
    auto check(T&& expr, cstring fmt, TArgs&&... args)
    {
        if (!expr)
        {
            log(fmt, std::forward<TArgs>(args)...);
            core_debug_break();
        }
    }

    template<typename T, typename... TArgs>
    auto ensure(T&& expr, cstring fmt, TArgs&&... args) -> T&&
    {
        check(std::forward<T>(expr), fmt, std::forward<T>(args)...);
        return std::forward<T>(expr);
    }
}

#else
    #define core_check(X, ...)
    #define core_debug_break()
    #define core_ensure(X, ...) (X)
    #define core_log(...) 
#endif
namespace Core
{
    auto read_entire_file(std::string_view filename) -> std::string;
    // @Note: This is relative to the exe path. Ex: "\\..\\..\\assets" would set the wdir two folders up the exe, inside the assets dir.
    auto set_working_dir(const std::string& path) -> void;
    auto get_time() -> f64;
    auto trim(std::string text)->std::string;
}

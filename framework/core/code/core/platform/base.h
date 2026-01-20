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
        #define PFM_WIN
	#else
        #error "x86 Builds are not supported!"
    #endif
#else
    #error "Unsupported OS!"
#endif

#if defined (CFG_DEBUG) || defined(CFG_RELEASE)
    #if defined(PFM_WIN)
        #define DEBUGBREAK() __debugbreak()
    #else
        #define DEBUGBREAK()
    #endif
    #define LOG(...) Core::log(__VA_ARGS__)
    #define ENSURE(X, ...) (Core::ensure(X, __VA_ARGS__))
    #define CHECK(X, ...) (Core::check(X, __VA_ARGS__))
    
namespace Core
{
    auto log(cstring fmt, ...) -> void;

    template<typename T, typename... TArgs>
    auto check(T&& expr, cstring fmt, TArgs&&... args)
    {
        if (!expr)
        {
            log(fmt, std::forward<TArgs>(args)...);
            DEBUGBREAK();
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
    #define CHECK(X, ...)
    #define DEBUGBREAK()
    #define ENSURE(X, ...) (X)
    #define LOG(...) 
#endif
namespace Core
{
    auto read_entire_file(std::string_view filename) -> std::string;
    // @Note: This is relative to the exe path. Ex: "\\..\\..\\assets" would set the wdir two folders up the exe, inside the assets dir.
    auto set_working_dir(const std::string& path) -> void;
    auto get_time() -> f64;
    auto trim(std::string text)->std::string;
}

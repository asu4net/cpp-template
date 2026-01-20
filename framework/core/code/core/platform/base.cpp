#include "base.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef CORE_WIN
#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#endif

auto Core::log(cstring fmt, ...) -> void
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

auto Core::read_entire_file(std::string_view filename) -> std::string
{
    std::ifstream file;
    file.open(filename);
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string buf = buffer.str();

    return buf;
}

auto Core::set_working_dir(const std::string& path) -> void
{
    if (path.empty())
    return;

#if defined (CORE_WIN)
    std::wostringstream conv;
    conv << path.c_str();
    std::wstring working_dir(conv.str());

    wchar_t exe_path[MAX_PATH];
    GetModuleFileName(nullptr, exe_path, MAX_PATH);
    std::wstring exe_w_path(exe_path);
    size_t pos = exe_w_path.find_last_of(L"\\/");
    std::wstring exe_dir = exe_w_path.substr(0, pos);
    std::wstring final_path = exe_dir + working_dir;
    SetCurrentDirectory(final_path.c_str());
#else
    #error "Platform not supported!"
#endif
}

auto Core::get_time() -> f64
{
#if defined(CORE_WIN)
    static LARGE_INTEGER frequency;
    static BOOL initialized = FALSE;

    if (!initialized)
    {
        QueryPerformanceFrequency(&frequency);
        initialized = TRUE;
    }

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    // @Note: Ticks divided by ticks-per-second.
    return (f64) counter.QuadPart / (f64) frequency.QuadPart;
#else
#error "Platform not supported!"
    return 0.0;
#endif
}

auto Core::trim(std::string text) -> std::string
{
    std::string s = text;
    // left Global::trim
    s.erase(s.begin(),
        std::find_if(s.begin(), s.end(),
            [](unsigned char ch) { return !std::isspace(ch); }));

    // right Global::trim
    s.erase(
        std::find_if(s.rbegin(), s.rend(),
            [](unsigned char ch) { return !std::isspace(ch); }).base(),
        s.end());
    return s;
}

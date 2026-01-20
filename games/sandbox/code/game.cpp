#include "core_platform.h"

auto main(i32 argc, cstring* argv) -> i32
{
    core_platform_init();
    core_log("Hellope!");
    return 0;
}
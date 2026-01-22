#include "core_platform.h"

auto main(i32 argc, cstring* argv) -> i32
{
    app_init();
    dbg_log("Hellope!");
    return 0;
}
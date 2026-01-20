#pragma once

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

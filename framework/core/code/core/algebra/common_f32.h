#pragma once

namespace Math
{
    inline constexpr f32 DEGREES_TO_RADIANS_FACTOR = 0.0174533f;
    inline constexpr f32 RADIANS_TO_DEGREES_FACTOR = 57.2958f;
    inline constexpr f32 PI = 3.14159265358979323846f;
    inline constexpr f32 F32_EPSILON = 1.192092896e-07F; // smallest such that 1.0+FLT_EPSILON != 1.0

    inline f32 to_radians(f32 degrees) { return degrees * DEGREES_TO_RADIANS_FACTOR; }
    inline f32 to_degrees(f32 radians) { return radians * RADIANS_TO_DEGREES_FACTOR; }
}

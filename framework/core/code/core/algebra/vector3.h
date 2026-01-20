#pragma once

class Vector3
{
public:    
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static auto dot(const Vector3& a, const Vector3& b) -> f32;
    // @Note: Returns a perpendicular vector to the (a, b) plane.
    static auto cross(const Vector3& a, const Vector3& b) -> Vector3;
    // @Note: Returns the euclidean (real) distance between to points.
    static auto distance(const Vector3& a, const Vector3& b) -> f32;
    // @Note: Same as distance but without the std::sqrt. std::sqrt is a heavy operation, this is useful for comparisons.
    static auto sqrt_distance(const Vector3& a, const Vector3& b) -> f32;
    
    constexpr Vector3() : x(0), y(0), z(0)
    {
    }

    constexpr Vector3(f32 x, f32 y, f32 z) : x(x), y(y), z(z)
    {
    }

    constexpr Vector3(const f32(&b) [3]) : x(b[0]), y(b[1]), z(b[2])
    {
    }

    constexpr Vector3(const f32(&b) [4]) : x(b[0]), y(b[1]), z(b[2])
    {
    }

    auto operator==(const Vector3& b) const -> bool;
    auto operator!=(const Vector3& b) const -> bool;

    auto operator+(const Vector3& b) const -> Vector3;
    auto operator-(const Vector3& b) const -> Vector3;
    
    auto operator+=(const Vector3& b) -> Vector3&;
    auto operator-=(const Vector3& b) -> Vector3&;
    
    auto operator*(const Vector3& b) const -> Vector3;
    auto operator/(const Vector3& b) const -> Vector3;
    
    auto operator*=(const Vector3& b) -> Vector3&;
    auto operator/=(const Vector3& b) -> Vector3&;
    
    auto operator*(f32 b) const -> Vector3;
    auto operator/(f32 b) const -> Vector3;

    auto operator*=(f32 b) -> Vector3&;
    auto operator/=(f32 b) -> Vector3&;
    
    auto lenght() const -> f32;
    auto normalized() const -> Vector3;
    
    auto radians() const -> Vector3;
    auto degrees() const -> Vector3;

    f32 x, y, z;
};

namespace Math
{
    inline static constexpr Vector3 Zero3D   { 0.f, 0.f, 0.f };
    inline static constexpr Vector3 One3D    { 1.f, 1.f, 1.f };
    inline static constexpr Vector3 Right3D  { 1.f, 0.f, 0.f };
    inline static constexpr Vector3 Left3D   {-1.f, 0.f, 0.f };
    inline static constexpr Vector3 Up3D     { 0.f, 1.f, 0.f };
    inline static constexpr Vector3 Down3D   { 0.f,-1.f, 0.f };
    inline static constexpr Vector3 Front3D  { 0.f, 0.f, 1.f };
    inline static constexpr Vector3 Back3D   { 0.f, 0.f,-1.f };
}
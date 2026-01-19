#pragma once

class Matrix4;
class Vector4;
class Vector3;

class Quaternion
{
public:
    // @Note: Rotates n radians in axis direction.
    static fn from_axis_angle(const Vector3& axis, f32 rad) -> Quaternion;
    // @Note: Rotates using a classic vector (it takes radians).
    static fn from_euler_angles(const Vector3& r) -> Quaternion;

    constexpr Quaternion() : x(0), y(0), z(0), w(0)
    {
    }

    constexpr Quaternion(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w)
    {
    }

    fn operator==(const Quaternion& b) const -> bool;
    fn operator!=(const Quaternion& b) const -> bool;

    fn operator*(const Quaternion& b) const -> Quaternion;
    fn operator*=(const Quaternion& b) -> Quaternion&;
    
    fn lenght() const -> f32;
    fn normalized() const -> Quaternion;
    
    // @Note: This represents a normalized dir (x, y, z) and an angle (w) (in radians).
    f32 x, y, z, w;
};

namespace Math
{
    inline static constexpr Quaternion ZeroQ     { 0.f, 0.f, 0.f, 0.f };
    inline static constexpr Quaternion IdentityQ { 0.f, 0.f, 0.f, 1.f };
}
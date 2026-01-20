#include "quaternion.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix4.h"

auto Quaternion::from_axis_angle(const Vector3& axis, f32 rad) -> Quaternion
{
    f32 half = rad * 0.5f;
    f32 s = std::sinf(half);
    
    return {
        axis.x * s,
        axis.y * s,
        axis.z * s,
        std::cosf(half)
    };
}

auto Quaternion::from_euler_angles(const Vector3& r) -> Quaternion
{
    Quaternion qx = from_axis_angle(Math::Right3D, r.x);
    Quaternion qy = from_axis_angle(Math::Up3D, r.y);
    Quaternion qz = from_axis_angle(Math::Front3D, r.z);
    return qz * qy * qx;
}

auto Quaternion::operator==(const Quaternion& b) const -> bool
{
    return (std::abs(x - b.x) <= Math::F32_EPSILON) 
        && (std::abs(y - b.y) <= Math::F32_EPSILON) 
        && (std::abs(z - b.z) <= Math::F32_EPSILON)
        && (std::abs(w - b.w) <= Math::F32_EPSILON);
}

auto Quaternion::operator!=(const Quaternion& b) const -> bool
{
    return !(operator==(b));
}

auto Quaternion::operator*(const Quaternion& b) const -> Quaternion
{
    return {
        w*b.x + x*b.w + y*b.z - z*b.y,
        w*b.y - x*b.z + y*b.w + z*b.x,
        w*b.z + x*b.y - y*b.x + z*b.w,
        w*b.w - x*b.x - y*b.y - z*b.z
    };
}

auto Quaternion::operator*=(const Quaternion& b) -> Quaternion&
{
    return *this = *this * b;
}

auto Quaternion::lenght() const -> f32
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

auto Quaternion::normalized() const -> Quaternion
{
    auto len = lenght();
    return { x / len, y / len, z / len, w / len };
}

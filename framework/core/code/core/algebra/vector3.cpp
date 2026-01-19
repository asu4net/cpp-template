#include "vector3.h"

fn Vector3::dot(const Vector3& a, const Vector3& b) -> f32
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

fn Vector3::cross(const Vector3& a, const Vector3& b) -> Vector3
{
    return 
    {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

fn Vector3::distance(const Vector3& a, const Vector3& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    f32 dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

fn Vector3::sqrt_distance(const Vector3& a, const Vector3& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    f32 dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

fn Vector3::operator==(const Vector3& b) const -> bool
{
    return (std::abs(x - b.x) <= Math::F32_EPSILON) 
        && (std::abs(y - b.y) <= Math::F32_EPSILON) 
        && (std::abs(z - b.z) <= Math::F32_EPSILON);
}

fn Vector3::operator!=(const Vector3& b) const -> bool
{
    return !(operator==(b));
}

fn Vector3::operator+(const Vector3& b) const -> Vector3
{
    return { x + b.x, y + b.y, z + b.z };
}

fn Vector3::operator-(const Vector3& b) const -> Vector3
{
    return { x - b.x, y - b.y, z - b.z };
}

fn Vector3::operator+=(const Vector3& b) -> Vector3&
{
    x += b.x; y += b.y; z += b.z; return *this;
}

fn Vector3::operator-=(const Vector3& b) -> Vector3&
{
    x -= b.x; y -= b.y; z -= b.z; return *this;
}

fn Vector3::operator*(const Vector3& b) const -> Vector3
{
    return { x * b.x, y * b.y, z * b.z };
}

fn Vector3::operator/(const Vector3& b) const -> Vector3
{
    return { x / b.x, y / b.y, z / b.z };
}

fn Vector3::operator*=(const Vector3& b) -> Vector3&
{
    x *= b.x; y *= b.y; z *= b.z; return *this;
}

fn Vector3::operator/=(const Vector3& b) -> Vector3&
{
    x /= b.x; y /= b.y; z /= b.z; return *this;
}

fn Vector3::operator*(f32 b) const -> Vector3
{
    return { x * b, y * b, z * b };
}

fn Vector3::operator/(f32 b) const -> Vector3
{
    return { x / b, y / b, z / b };
}

fn Vector3::operator*=(f32 b) -> Vector3&
{
    x *= b; y *= b; z *= b; return *this;
}

fn Vector3::operator/=(f32 b) -> Vector3&
{
    x /= b; y /= b; z /= b; return *this;
}

fn Vector3::lenght() const -> f32
{
    return std::sqrt(x * x + y * y + z * z);
}

fn Vector3::normalized() const -> Vector3
{
    auto len = lenght();
    return { x / len, y / len, z / len };
}

fn Vector3::radians() const -> Vector3
{
    return { Math::to_radians(x), Math::to_radians(y), Math::to_radians(z)};
}

fn Vector3::degrees() const -> Vector3
{
    return { Math::to_degrees(x), Math::to_degrees(y), Math::to_degrees(z)};
}
#include "vector4.h"
#include "matrix4.h"

auto Vector4::dot(const Vector4& a, const Vector4& b) -> f32
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

auto Vector4::operator==(const Vector4& b) const -> bool
{
    return (std::abs(x - b.x) <= Math::F32_EPSILON) 
        && (std::abs(y - b.y) <= Math::F32_EPSILON) 
        && (std::abs(z - b.z) <= Math::F32_EPSILON)
        && (std::abs(w - b.w) <= Math::F32_EPSILON);
}

auto Vector4::operator!=(const Vector4& b) const -> bool
{
    return !(operator==(b));
}

auto Vector4::operator+(const Vector4& b) const -> Vector4
{
    return { x + b.x, y + b.y, z + b.z, w + b.w };
}

auto Vector4::operator-(const Vector4& b) const -> Vector4
{
    return { x - b.x, y - b.y, z - b.z, w - b.w };
}

auto Vector4::operator+=(const Vector4& b) -> Vector4&
{
    x += b.x; y += b.y; z += b.z; w += b.w;  return *this;
}

auto Vector4::operator-=(const Vector4& b) -> Vector4&
{
    x -= b.x; y -= b.y; z -= b.z; w -= b.w;  return *this;
}

auto Vector4::operator*(const Vector4& b) const -> Vector4
{
    return { x * b.x, y * b.y, z * b.z, w * b.w };
}

auto Vector4::operator*(const Matrix4& m) const -> Vector4
{
    return {
        x * m._11 + y * m._21 + z * m._31 + w * m._41,
        x * m._12 + y * m._22 + z * m._32 + w * m._42,
        x * m._13 + y * m._23 + z * m._33 + w * m._43,
        x * m._14 + y * m._24 + z * m._34 + w * m._44
    };
}

auto Vector4::operator/(const Vector4& b) const -> Vector4
{
    return { x / b.x, y / b.y, z / b.z, w / b.w };
}

auto Vector4::operator*=(const Vector4& b) -> Vector4&
{
    x *= b.x; y *= b.y; z *= b.z; w *= b.w; return *this;
}

auto Vector4::operator/=(const Vector4& b) -> Vector4&
{
    x /= b.x; y /= b.y; z /= b.z; w /= b.w; return *this;
}

auto Vector4::lenght() const -> f32
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

auto Vector4::normalized() const -> Vector4
{
    auto len = lenght();
    return { x / len, y / len, z / len, w / len };
}
#include "vector2.h"

auto Vector2::dot(const Vector2& a, const Vector2& b) -> f32
{
    return a.x * b.x + a.y * b.y;
}

auto Vector2::distance(const Vector2& a, const Vector2& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);

}

auto Vector2::sqrt_distance(const Vector2& a, const Vector2& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    return dx * dx + dy * dy;
}

auto Vector2::operator==(const Vector2& b) const -> bool
{
    return (std::abs(x - b.x) <= Math::F32_EPSILON)
        && (std::abs(y - b.y) <= Math::F32_EPSILON);
}

auto Vector2::operator!=(const Vector2& b) const -> bool
{
    return !(operator==(b));
}

auto Vector2::operator+(const Vector2& b) const -> Vector2
{
    return { x + b.x, y + b.y};
}

auto Vector2::operator-(const Vector2& b) const -> Vector2
{
    return { x - b.x, y - b.y };
}

auto Vector2::operator+=(const Vector2& b) -> Vector2&
{
    x += b.x; y += b.y; return *this;
}

auto Vector2::operator-=(const Vector2& b) -> Vector2&
{
    x -= b.x; y -= b.y; return *this;
}

auto Vector2::operator*(const Vector2& b) const -> Vector2
{
    return { x * b.x, y * b.y };
}

auto Vector2::operator/(const Vector2& b) const -> Vector2
{
    return { x / b.x, y / b.y };
}

auto Vector2::operator*=(const Vector2& b) -> Vector2&
{
    x *= b.x; y *= b.y; return *this;
}

auto Vector2::operator/=(const Vector2& b) -> Vector2&
{
    x /= b.x; y /= b.y; return *this;
}

auto Vector2::operator*(f32 b) const -> Vector2
{
    return { x * b, y * b };
}

auto Vector2::operator/(f32 b) const -> Vector2
{
    return { x / b, y / b };
}

auto Vector2::operator*=(f32 b) -> Vector2&
{
    x *= b; y *= b; return *this;
}

auto Vector2::operator/=(f32 b) -> Vector2&
{
    x /= b; y /= b; return *this;
}

auto Vector2::lenght() const -> f32
{
    return std::sqrt(x * x + y * y);
}

auto Vector2::normalized() const -> Vector2
{
    auto len = lenght();
    return { x / len, y / len };
}

auto Vector2::radians() const -> Vector2
{
    return { Math::to_radians(x), Math::to_radians(y) };
}

auto Vector2::degrees() const -> Vector2
{
    return { Math::to_degrees(x), Math::to_degrees(y) };
}
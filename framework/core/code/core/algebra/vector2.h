#pragma once

class Vector2
{
public:
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static fn dot(const Vector2& a, const Vector2& b) -> f32;
    // @Note: Returns the euclidean (real) distance between to points.
    static fn distance(const Vector2& a, const Vector2& b) -> f32;
    // @Note: Same as distance but without the std::sqrt. std::sqrt is a heavy operation, this is useful for comparisons.
    static fn sqrt_distance(const Vector2& a, const Vector2& b) -> f32;
    
    constexpr Vector2() : x(0), y(0)
    {
    }

    constexpr Vector2(f32 x, f32 y) : x(x), y(y)
    {
    }
    
    fn operator==(const Vector2& b) const -> bool;
    fn operator!=(const Vector2& b) const -> bool;

    fn operator+(const Vector2& b) const -> Vector2;
    fn operator-(const Vector2& b) const -> Vector2;
    
    fn operator+=(const Vector2& b) -> Vector2&;
    fn operator-=(const Vector2& b) -> Vector2&;
    
    fn operator*(const Vector2& b) const -> Vector2;
    fn operator/(const Vector2& b) const -> Vector2;
    
    fn operator*=(const Vector2& b) -> Vector2&;
    fn operator/=(const Vector2& b) -> Vector2&;

    fn operator*(f32 b) const->Vector2;
    fn operator/(f32 b) const->Vector2;

    fn operator*=(f32 b) -> Vector2&;
    fn operator/=(f32 b) -> Vector2&;

    fn lenght() const -> f32;
    fn normalized() const -> Vector2;

    fn radians() const -> Vector2;
    fn degrees() const -> Vector2;
    
    f32 x, y;
};

namespace Math
{
    inline static constexpr Vector2 Zero2D   { 0.f, 0.f };
    inline static constexpr Vector2 One2D    { 1.f, 1.f };
    inline static constexpr Vector2 Right2D  { 1.f, 0.f };
    inline static constexpr Vector2 Left2D   {-1.f, 0.f };
    inline static constexpr Vector2 Up2D     { 0.f, 1.f };
    inline static constexpr Vector2 Down2D   { 0.f,-1.f };
}

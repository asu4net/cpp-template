#pragma once

class Matrix4;

class Vector4
{
public:
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static fn dot(const Vector4& a, const Vector4& b) -> f32;
    
    constexpr Vector4() : x(0), y(0), z(0), w(0)
    {
    }

    constexpr Vector4(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w)
    {
    }

    constexpr Vector4(const f32(&b) [4]) : x(b[0]), y(b[1]), z(b[2]), w(b[3])
    {
    }

    fn operator==(const Vector4& b) const -> bool;
    fn operator!=(const Vector4& b) const -> bool;

    fn operator+(const Vector4& b) const -> Vector4;
    fn operator-(const Vector4& b) const -> Vector4;
    
    fn operator+=(const Vector4& b) -> Vector4&;
    fn operator-=(const Vector4& b) -> Vector4&;
    
    fn operator*(const Vector4& b) const -> Vector4;
    fn operator*(const Matrix4& m) const -> Vector4;
    fn operator/(const Vector4& b) const -> Vector4;
    
    fn operator*=(const Vector4& b) -> Vector4&;
    fn operator/=(const Vector4& b) -> Vector4&;
    
    fn lenght() const -> f32;
    fn normalized() const -> Vector4;
    
    f32 x, y, z, w;
};

namespace Color
{
    inline static constexpr f32 White            [] { 1.f, 1.f, 1.f, 1.f };
    inline static constexpr f32 White_Faded      [] { 1.f, 1.f, 1.f, 0.f };
    inline static constexpr f32 Black            [] { 0.f, 0.f, 0.f, 1.f };
    inline static constexpr f32 Corn_Flower_Blue [] { .388f, .584f, .933f, 1.f };
    inline static constexpr f32 Blue             [] { 0.f, 0.f, 1.f, 1.f };
    inline static constexpr f32 Light_Blue       [] { .3f, .3f, 1.f, 1.f };
    inline static constexpr f32 Cyan             [] { 0.f, 1.f, 1.f, 1.f };
    inline static constexpr f32 Gray             [] { .5f, .5f, .5f, 1.f };
    inline static constexpr f32 Dark_Gray        [] { .2f, .2f, .2f, 1.f };
    inline static constexpr f32 Green            [] { 0.f, 1.f, 0.f, 1.f };
    inline static constexpr f32 Light_Green      [] { .3f, 1.f, .3f, 1.f };
    inline static constexpr f32 Chill_Green      [] {0.0471f, 0.6510f, 0.4078f, 1.f };
    inline static constexpr f32 Magenta          [] { 1.f, 0.f, 1.f, 1.f };
    inline static constexpr f32 Red              [] { 1.f, 0.f, 0.f, 1.f };
    inline static constexpr f32 Light_Red        [] { 1.f, .3f, .3f, 1.f };
    inline static constexpr f32 Yellow           [] { 1.f, .92f, .016f, 1.f };
    inline static constexpr f32 Orange           [] { .97f, .60f, .11f, 1.f };
}

namespace Math
{
    inline static constexpr Vector4 Zero4D  { 0.f, 0.f, 0.f, 0.f };
    inline static constexpr Vector4 One4D   { 1.f, 1.f, 1.f, 1.f };
}

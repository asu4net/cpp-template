#pragma once

class Vector3;
class Vector4;
class Quaternion;

//@Pending: 
// - Matrix4::decompose, 
// - Optimized Vector2 rotation (not using Quaternions & Z axis)
// - Matrix4::screen_to_world
// - Matrix4::world_to_screen

class Matrix4 
{
public:
    static fn from_quaternion(const Quaternion& q) -> Matrix4;

    // @Note: Transformations. 
    static fn translate(const Vector3& t) -> Matrix4;
    static fn scale(const Vector3& s) -> Matrix4;
    static fn rotate(const Quaternion& r) -> Matrix4;
    static fn rotate(const Vector3& r) -> Matrix4;
    static fn transform(const Vector3& t, const Vector3& r = Math::Zero3D, const Vector3& s = Math::One3D) -> Matrix4;

    // @Note: Swap rows & columns.
    static fn transpose(const Matrix4& a) -> Matrix4;
    // @Note: Reverts the operation. Ex: Prev M -> Transformed M | Prev M = Transformed M-1
    static fn inverse(const Matrix4& a) -> Matrix4;
    // @Note: Mesures volume's scale, check mirrored, if returns 0 inverse does not exist.
    static fn determinant(const Matrix4& a) -> f32;
    
    // @Note: RH (Right Handed): Negative Z goes forward. (OpenGL)
    // NO (Negative One to One): Depth values are normalized between -1 and 1.
    // ------------------------
    static fn view(const Vector3& p, const Quaternion& r) -> Matrix4;
    static fn orthographic(f32 l, f32 r, f32 b, f32 t, f32 n, f32 f) -> Matrix4;
    static fn orthographic(f32 aspect, f32 size, f32 n, f32 f) -> Matrix4;
    static fn perspective(f32 fovy, f32 aspect, f32 n, f32 f) -> Matrix4;
    // ------------------------
    // @Pending: Do the LH version.

    constexpr Matrix4()
        : _11(0.f), _12(0.f), _13(0.f), _14(0.f)
        , _21(0.f), _22(0.f), _23(0.f), _24(0.f)
        , _31(0.f), _32(0.f), _33(0.f), _34(0.f)
        , _41(0.f), _42(0.f), _43(0.f), _44(0.f)
    {
    }

    constexpr Matrix4(
          f32 _11, f32 _12, f32 _13, f32 _14
        , f32 _21, f32 _22, f32 _23, f32 _24
        , f32 _31, f32 _32, f32 _33, f32 _34
        , f32 _41, f32 _42, f32 _43, f32 _44
    )
        : _11(_11), _12(_12), _13(_13), _14(_14)
        , _21(_21), _22(_22), _23(_23), _24(_24)
        , _31(_31), _32(_32), _33(_33), _34(_34)
        , _41(_41), _42(_42), _43(_43), _44(_44)
    {
    }

    fn operator==(const Matrix4& b) const -> bool;
    fn operator!=(const Matrix4& b) const -> bool;

    fn operator*(const Matrix4& b) const -> Matrix4;
    fn operator*=(const Matrix4& b) -> Matrix4&;
    
    fn operator*(const Vector4& v) const -> Vector4;

    fn data() -> f32*;
    
    // @Note: Row major matrix. First number is the row, Second is the column. (D3D11)
    f32 _11, _12, _13, _14;
    f32 _21, _22, _23, _24;
    f32 _31, _32, _33, _34;
    f32 _41, _42, _43, _44;
};

namespace Math
{
    inline static constexpr Matrix4 ZeroM4
    {
        0.f, 0.f, 0.f, 0.f, 
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f 
    };

    inline static constexpr Matrix4 IdentityM4
    {
        1.f, 0.f, 0.f, 0.f, 
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f 
    };
}
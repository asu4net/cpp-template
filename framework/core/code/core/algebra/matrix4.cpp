#include "matrix4.h"
#include "vector3.h"
#include "vector4.h"
#include "quaternion.h"

auto Matrix4::from_quaternion(const Quaternion& q) -> Matrix4
{
    Quaternion n = q.normalized();
    
    f32 xx = n.x * n.x;
    f32 yy = n.y * n.y;
    f32 zz = n.z * n.z;

    f32 xy = n.x * n.y;
    f32 xz = n.x * n.z;
    f32 yz = n.y * n.z;
    
    f32 wx = n.w * n.x;
    f32 wy = n.w * n.y;
    f32 wz = n.w * n.z;
    
    Matrix4 m = Math::IdentityM4;

    m._11 = 1.f - 2.f*(yy + zz);
    m._12 =       2.f*(xy - wz);
    m._13 =       2.f*(xz + wy);

    m._21 =       2.f*(xy + wz);
    m._22 = 1.f - 2.f*(xx + zz);
    m._23 =       2.f*(yz - wx);

    m._31 =       2.f*(xz - wy);
    m._32 =       2.f*(yz + wx);
    m._33 = 1.f - 2.f*(xx + yy);
    
    return m;
}

auto Matrix4::translate(const Vector3& t) -> Matrix4
{
    Matrix4 m(Math::IdentityM4);
    m._14 = t.x;
    m._24 = t.y;
    m._34 = t.z;
    return m;
}

auto Matrix4::scale(const Vector3& s) -> Matrix4
{
    Matrix4 m(Math::IdentityM4);
    m._11 = s.x;
    m._22 = s.y;
    m._33 = s.z;
    return m;
}

auto Matrix4::rotate(const Quaternion& r) -> Matrix4
{
    Matrix4 m = from_quaternion(r);
    return m;
}

auto Matrix4::rotate(const Vector3& r) -> Matrix4
{
    Quaternion q = Quaternion::from_euler_angles(r);
    return rotate(q);
}

auto Matrix4::transform(const Vector3& t, const Vector3& r, const Vector3& s) -> Matrix4
{
    // @Note: It applies from right to left: Local scale, local rotation, world translation.
    return translate(t) * rotate(r) * scale(s);
}

auto Matrix4::transpose(const Matrix4& a) -> Matrix4
{
    return {
        a._11,a._21,a._31,a._41,
        a._12,a._22,a._32,a._42,
        a._13,a._23,a._33,a._43,
        a._14,a._24,a._34,a._44
    };
}

auto Matrix4::inverse(const Matrix4& a) -> Matrix4
{
    Matrix4 r(Math::IdentityM4);

    f32 a0 = a._11 * a._22 - a._12 * a._21;
    f32 a1 = a._11 * a._23 - a._13 * a._21;
    f32 a2 = a._11 * a._24 - a._14 * a._21;
    f32 a3 = a._12 * a._23 - a._13 * a._22;
    f32 a4 = a._12 * a._24 - a._14 * a._22;
    f32 a5 = a._13 * a._24 - a._14 * a._23;

    f32 b0 = a._31 * a._42 - a._32 * a._41;
    f32 b1 = a._31 * a._43 - a._33 * a._41;
    f32 b2 = a._31 * a._44 - a._34 * a._41;
    f32 b3 = a._32 * a._43 - a._33 * a._42;
    f32 b4 = a._32 * a._44 - a._34 * a._42;
    f32 b5 = a._33 * a._44 - a._34 * a._43;

    f32 det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    if (std::fabsf(det) < 1e-8f)
    {
        return r;
    }

    f32 inv_det = 1.0f / det;

    r._11 = ( a._22 * b5 - a._23 * b4 + a._24 * b3) * inv_det;
    r._12 = (-a._12 * b5 + a._13 * b4 - a._14 * b3) * inv_det;
    r._13 = ( a._42 * a5 - a._43 * a4 + a._44 * a3) * inv_det;
    r._14 = (-a._32 * a5 + a._33 * a4 - a._34 * a3) * inv_det;

    r._21 = (-a._21 * b5 + a._23 * b2 - a._24 * b1) * inv_det;
    r._22 = ( a._11 * b5 - a._13 * b2 + a._14 * b1) * inv_det;
    r._23 = (-a._41 * a5 + a._43 * a2 - a._44 * a1) * inv_det;
    r._24 = ( a._31 * a5 - a._33 * a2 + a._34 * a1) * inv_det;

    r._31 = ( a._21 * b4 - a._22 * b2 + a._24 * b0) * inv_det;
    r._32 = (-a._11 * b4 + a._12 * b2 - a._14 * b0) * inv_det;
    r._33 = ( a._41 * a4 - a._42 * a2 + a._44 * a0) * inv_det;
    r._34 = (-a._31 * a4 + a._32 * a2 - a._34 * a0) * inv_det;

    r._41 = (-a._21 * b3 + a._22 * b1 - a._23 * b0) * inv_det;
    r._42 = ( a._11 * b3 - a._12 * b1 + a._13 * b0) * inv_det;
    r._43 = (-a._41 * a3 + a._42 * a1 - a._43 * a0) * inv_det;
    r._44 = ( a._31 * a3 - a._32 * a1 + a._33 * a0) * inv_det;

    return r;
}

auto Matrix4::determinant(const Matrix4& a) -> f32 
{
    f32 a0 = a._11 * a._22 - a._12 * a._21;
    f32 a1 = a._11 * a._23 - a._13 * a._21;
    f32 a2 = a._11 * a._24 - a._14 * a._21;
    f32 a3 = a._12 * a._23 - a._13 * a._22;
    f32 a4 = a._12 * a._24 - a._14 * a._22;
    f32 a5 = a._13 * a._24 - a._14 * a._23;

    f32 b0 = a._31 * a._42 - a._32 * a._41;
    f32 b1 = a._31 * a._43 - a._33 * a._41;
    f32 b2 = a._31 * a._44 - a._34 * a._41;
    f32 b3 = a._32 * a._43 - a._33 * a._42;
    f32 b4 = a._32 * a._44 - a._34 * a._42;
    f32 b5 = a._33 * a._44 - a._34 * a._43;

    return a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
}

auto Matrix4::view(const Vector3& p, const Quaternion& r) -> Matrix4
{
    return inverse(rotate(r)) * inverse(translate(p));
}

auto Matrix4::orthographic(f32 l, f32 r, f32 b, f32 t, f32 n, f32 f) -> Matrix4
{
    Matrix4 m(Math::IdentityM4);

    m._11 =  2.0f / (r - l);
    m._22 =  2.0f / (t - b);
    m._33 = -2.0f / (f - n);
    
    m._14 = -(r + l) / (r - l);
    m._24 = -(t + b) / (t - b);
    m._34 = -(f + n) / (f - n); 

    return m;
}

auto Matrix4::orthographic(f32 aspect, f32 size, f32 n, f32 f) -> Matrix4
{
    f32 w = size * aspect;
    f32 h = size;
    return orthographic(-w, w, -h, h, n, f);
}

auto Matrix4::perspective(f32 fovy, f32 aspect, f32 n, f32 f) -> Matrix4
{
    Matrix4 m;
    f32 t = std::tanf(fovy * 0.5f);

    m._11 = 1.f / (aspect * t);
    m._22 = 1.f / t;
    m._33 = - (f + n) / (f - n);
    m._43 = - 1.f;
    m._34 = - (2.f * f * n) / (f - n);
        
    return m;
}

auto Matrix4::operator==(const Matrix4& b) const -> bool
{
    return std::memcmp(this, &b, sizeof(Matrix4)) == 0;
}

auto Matrix4::operator!=(const Matrix4& b) const -> bool
{
    return !(*this == b);
}

auto Matrix4::operator*(const Matrix4& b) const -> Matrix4
{
    Matrix4 r;

    r._11 = _11*b._11 + _12*b._21 + _13*b._31 + _14*b._41;
    r._21 = _21*b._11 + _22*b._21 + _23*b._31 + _24*b._41;
    r._31 = _31*b._11 + _32*b._21 + _33*b._31 + _34*b._41;
    r._41 = _41*b._11 + _42*b._21 + _43*b._31 + _44*b._41;

    r._12 = _11*b._12 + _12*b._22 + _13*b._32 + _14*b._42;
    r._22 = _21*b._12 + _22*b._22 + _23*b._32 + _24*b._42;
    r._32 = _31*b._12 + _32*b._22 + _33*b._32 + _34*b._42;
    r._42 = _41*b._12 + _42*b._22 + _43*b._32 + _44*b._42;

    r._13 = _11*b._13 + _12*b._23 + _13*b._33 + _14*b._43;
    r._23 = _21*b._13 + _22*b._23 + _23*b._33 + _24*b._43;
    r._33 = _31*b._13 + _32*b._23 + _33*b._33 + _34*b._43;
    r._43 = _41*b._13 + _42*b._23 + _43*b._33 + _44*b._43;

    r._14 = _11*b._14 + _12*b._24 + _13*b._34 + _14*b._44;
    r._24 = _21*b._14 + _22*b._24 + _23*b._34 + _24*b._44;
    r._34 = _31*b._14 + _32*b._24 + _33*b._34 + _34*b._44;
    r._44 = _41*b._14 + _42*b._24 + _43*b._34 + _44*b._44;

    return r;
}

auto Matrix4::operator*=(const Matrix4& b) -> Matrix4&
{
    *this = *this * b;
    return *this;
}

auto Matrix4::operator*(const Vector4& v) const -> Vector4
{
    return {
        _11*v.x + _12*v.y + _13*v.z + _14*v.w,
        _21*v.x + _22*v.y + _23*v.z + _24*v.w,
        _31*v.x + _32*v.y + _33*v.z + _34*v.w,
        _41*v.x + _42*v.y + _43*v.z + _44*v.w
    };
}

auto Matrix4::data() -> f32*
{
    return &_11;
}
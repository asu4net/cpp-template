#include "base_math.h"

// =========================================
// @Region: Vector2
// =========================================

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

// =========================================
// @Region: Vector3
// =========================================

auto Vector3::dot(const Vector3& a, const Vector3& b) -> f32
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

auto Vector3::cross(const Vector3& a, const Vector3& b) -> Vector3
{
    return 
    {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

auto Vector3::distance(const Vector3& a, const Vector3& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    f32 dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

auto Vector3::sqrt_distance(const Vector3& a, const Vector3& b) -> f32
{
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    f32 dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

auto Vector3::operator==(const Vector3& b) const -> bool
{
    return (std::abs(x - b.x) <= Math::F32_EPSILON) 
        && (std::abs(y - b.y) <= Math::F32_EPSILON) 
        && (std::abs(z - b.z) <= Math::F32_EPSILON);
}

auto Vector3::operator!=(const Vector3& b) const -> bool
{
    return !(operator==(b));
}

auto Vector3::operator+(const Vector3& b) const -> Vector3
{
    return { x + b.x, y + b.y, z + b.z };
}

auto Vector3::operator-(const Vector3& b) const -> Vector3
{
    return { x - b.x, y - b.y, z - b.z };
}

auto Vector3::operator+=(const Vector3& b) -> Vector3&
{
    x += b.x; y += b.y; z += b.z; return *this;
}

auto Vector3::operator-=(const Vector3& b) -> Vector3&
{
    x -= b.x; y -= b.y; z -= b.z; return *this;
}

auto Vector3::operator*(const Vector3& b) const -> Vector3
{
    return { x * b.x, y * b.y, z * b.z };
}

auto Vector3::operator/(const Vector3& b) const -> Vector3
{
    return { x / b.x, y / b.y, z / b.z };
}

auto Vector3::operator*=(const Vector3& b) -> Vector3&
{
    x *= b.x; y *= b.y; z *= b.z; return *this;
}

auto Vector3::operator/=(const Vector3& b) -> Vector3&
{
    x /= b.x; y /= b.y; z /= b.z; return *this;
}

auto Vector3::operator*(f32 b) const -> Vector3
{
    return { x * b, y * b, z * b };
}

auto Vector3::operator/(f32 b) const -> Vector3
{
    return { x / b, y / b, z / b };
}

auto Vector3::operator*=(f32 b) -> Vector3&
{
    x *= b; y *= b; z *= b; return *this;
}

auto Vector3::operator/=(f32 b) -> Vector3&
{
    x /= b; y /= b; z /= b; return *this;
}

auto Vector3::lenght() const -> f32
{
    return std::sqrt(x * x + y * y + z * z);
}

auto Vector3::normalized() const -> Vector3
{
    auto len = lenght();
    return { x / len, y / len, z / len };
}

auto Vector3::radians() const -> Vector3
{
    return { Math::to_radians(x), Math::to_radians(y), Math::to_radians(z)};
}

auto Vector3::degrees() const -> Vector3
{
    return { Math::to_degrees(x), Math::to_degrees(y), Math::to_degrees(z)};
}

// =========================================
// @Region: Vector4
// =========================================

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

// =========================================
// @Region: Matrix4
// =========================================

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

// =========================================
// @Region: Quaternion
// =========================================

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

// =========================================
// @Region: Camera
// =========================================

auto Free_Look::move_forward(f32 dt)  -> void { m_camera->pos = m_camera->pos + forward() * (speed * dt); }
auto Free_Look::move_backward(f32 dt) -> void { m_camera->pos = m_camera->pos - forward() * (speed * dt); }
auto Free_Look::move_right(f32 dt)    -> void { m_camera->pos = m_camera->pos + right()   * (speed * dt); }
auto Free_Look::move_left(f32 dt)     -> void { m_camera->pos = m_camera->pos - right()   * (speed * dt); }
auto Free_Look::move_up(f32 dt)       -> void { m_camera->pos.y += speed * dt; }
auto Free_Look::move_down(f32 dt)     -> void { m_camera->pos.y -= speed * dt; }

auto Free_Look::rotate(f32 dx, f32 dy) -> void
{
    m_camera->rot.y -= dx * sensivity; 
    m_camera->rot.x -= dy * sensivity;

    if (m_camera->rot.x > CLAMP_ANGLE)  m_camera->rot.x = CLAMP_ANGLE;
    if (m_camera->rot.x < -CLAMP_ANGLE) m_camera->rot.x = -CLAMP_ANGLE;
}

auto Free_Look::forward() const -> Vector3
{
    f32 pitch = Math::to_radians(m_camera->rot.x);
    f32 yaw = Math::to_radians(m_camera->rot.y);

    return Vector3{
        -cos(pitch) * sin(yaw),
         sin(pitch),
        -cos(pitch) * cos(yaw)
    }.normalized();
}

auto Free_Look::right() const -> Vector3
{
    return Vector3::cross(forward(), Vector3 { 0,1,0 }).normalized();
}

auto Camera::update_matrix(i32 viewport_x, i32 viewport_y) -> void
{
    Matrix4 p;
    const f32 aspect = (f32)viewport_x / (f32)viewport_y;

    switch (mode)
    {
    case Camera::Perspective:
        p = Matrix4::perspective(Math::to_radians(fov), aspect, near_plane, far_plane);
        break;
    case Camera::Orthographic:
        p = Matrix4::orthographic(aspect, size, near_plane, far_plane);
        break;
    }
    
    Matrix4 v = Matrix4::view(pos, Quaternion::from_euler_angles(rot.radians()));
    m_matrix = Matrix4::transpose(p * v);
}
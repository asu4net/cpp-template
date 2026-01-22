#pragma once

// =========================================
// @Region: Common f32 stuff.
// =========================================

namespace Math
{
    inline constexpr f32 DEGREES_TO_RADIANS_FACTOR = 0.0174533f;
    inline constexpr f32 RADIANS_TO_DEGREES_FACTOR = 57.2958f;
    inline constexpr f32 PI = 3.14159265358979323846f;
    inline constexpr f32 F32_EPSILON = 1.192092896e-07F; // smallest such that 1.0+FLT_EPSILON != 1.0

    inline f32 to_radians(f32 degrees) { return degrees * DEGREES_TO_RADIANS_FACTOR; }
    inline f32 to_degrees(f32 radians) { return radians * RADIANS_TO_DEGREES_FACTOR; }
}

// =========================================
// @Region: Vector2
// =========================================

class Vector2 {
public:
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static fn dot(const Vector2& a, const Vector2& b) -> f32;
    // @Note: Returns the euclidean (real) distance between to points.
    static fn distance(const Vector2& a, const Vector2& b) -> f32;
    // @Note: Same as distance but without the std::sqrt. std::sqrt is a heavy operation, this is useful for comparisons.
    static fn sqrt_distance(const Vector2& a, const Vector2& b) -> f32;
    
    constexpr Vector2() : x(0), y(0) {}
    constexpr Vector2(f32 x, f32 y) : x(x), y(y) {}
    
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

namespace Math {
    inline static constexpr Vector2 Zero2D   { 0.f, 0.f };
    inline static constexpr Vector2 One2D    { 1.f, 1.f };
    inline static constexpr Vector2 Right2D  { 1.f, 0.f };
    inline static constexpr Vector2 Left2D   {-1.f, 0.f };
    inline static constexpr Vector2 Up2D     { 0.f, 1.f };
    inline static constexpr Vector2 Down2D   { 0.f,-1.f };
}

// =========================================
// @Region: Vector3
// =========================================

class Vector3 {
public:    
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static fn dot(const Vector3& a, const Vector3& b) -> f32;
    // @Note: Returns a perpendicular vector to the (a, b) plane.
    static fn cross(const Vector3& a, const Vector3& b) -> Vector3;
    // @Note: Returns the euclidean (real) distance between to points.
    static fn distance(const Vector3& a, const Vector3& b) -> f32;
    // @Note: Same as distance but without the std::sqrt. std::sqrt is a heavy operation, this is useful for comparisons.
    static fn sqrt_distance(const Vector3& a, const Vector3& b) -> f32;
    
    constexpr Vector3() : x(0), y(0), z(0) {}
    constexpr Vector3(f32 x, f32 y, f32 z) : x(x), y(y), z(z) {}
    constexpr Vector3(const f32(&b) [3]) : x(b[0]), y(b[1]), z(b[2]) {}
    constexpr Vector3(const f32(&b) [4]) : x(b[0]), y(b[1]), z(b[2]) {}

    fn operator==(const Vector3& b) const -> bool;
    fn operator!=(const Vector3& b) const -> bool;

    fn operator+(const Vector3& b) const -> Vector3;
    fn operator-(const Vector3& b) const -> Vector3;
    
    fn operator+=(const Vector3& b) -> Vector3&;
    fn operator-=(const Vector3& b) -> Vector3&;
    
    fn operator*(const Vector3& b) const -> Vector3;
    fn operator/(const Vector3& b) const -> Vector3;
    
    fn operator*=(const Vector3& b) -> Vector3&;
    fn operator/=(const Vector3& b) -> Vector3&;
    
    fn operator*(f32 b) const -> Vector3;
    fn operator/(f32 b) const -> Vector3;

    fn operator*=(f32 b) -> Vector3&;
    fn operator/=(f32 b) -> Vector3&;
    
    fn lenght() const -> f32;
    fn normalized() const -> Vector3;
    
    fn radians() const -> Vector3;
    fn degrees() const -> Vector3;

    f32 x, y, z;
};

namespace Math {
    inline static constexpr Vector3 Zero3D   { 0.f, 0.f, 0.f };
    inline static constexpr Vector3 One3D    { 1.f, 1.f, 1.f };
    inline static constexpr Vector3 Right3D  { 1.f, 0.f, 0.f };
    inline static constexpr Vector3 Left3D   {-1.f, 0.f, 0.f };
    inline static constexpr Vector3 Up3D     { 0.f, 1.f, 0.f };
    inline static constexpr Vector3 Down3D   { 0.f,-1.f, 0.f };
    inline static constexpr Vector3 Front3D  { 0.f, 0.f, 1.f };
    inline static constexpr Vector3 Back3D   { 0.f, 0.f,-1.f };
}

class Matrix4;

// =========================================
// @Region: Vector4
// =========================================

class Vector4 {
public:
    // @Note: Returns how much a goes in the direction of b. (0 -> perpendicular)
    static fn dot(const Vector4& a, const Vector4& b) -> f32;
    
    constexpr Vector4() : x(0), y(0), z(0), w(0) {}
    constexpr Vector4(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w) {}
    constexpr Vector4(const f32(&b) [4]) : x(b[0]), y(b[1]), z(b[2]), w(b[3]) {}

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

namespace Color {
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

namespace Math {
    inline static constexpr Vector4 Zero4D  { 0.f, 0.f, 0.f, 0.f };
    inline static constexpr Vector4 One4D   { 1.f, 1.f, 1.f, 1.f };
}

// =========================================
// @Region: Matrix4
// =========================================

class Vector3;
class Vector4;
class Quaternion;

//@Pending: 
// - Matrix4::decompose, 
// - Optimized Vector2 rotation (not using Quaternions & Z axis)
// - Matrix4::screen_to_world
// - Matrix4::world_to_screen

class Matrix4 {
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

namespace Math {
    inline static constexpr Matrix4 ZeroM4 {
        0.f, 0.f, 0.f, 0.f, 
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f 
    };

    inline static constexpr Matrix4 IdentityM4 {
        1.f, 0.f, 0.f, 0.f, 
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f 
    };
}

// =========================================
// @Region: Quaternion
// =========================================

class Matrix4;
class Vector4;
class Vector3;

class Quaternion {
public:
    // @Note: Rotates n radians in axis direction.
    static fn from_axis_angle(const Vector3& axis, f32 rad) -> Quaternion;
    // @Note: Rotates using a classic vector (it takes radians).
    static fn from_euler_angles(const Vector3& r) -> Quaternion;

    constexpr Quaternion() : x(0), y(0), z(0), w(0) {}
    constexpr Quaternion(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w) {}

    fn operator==(const Quaternion& b) const -> bool;
    fn operator!=(const Quaternion& b) const -> bool;

    fn operator*(const Quaternion& b) const -> Quaternion;
    fn operator*=(const Quaternion& b) -> Quaternion&;
    
    fn lenght() const -> f32;
    fn normalized() const -> Quaternion;
    
    // @Note: This represents a normalized dir (x, y, z) and an angle (w) (in radians).
    f32 x, y, z, w;
};

namespace Math {
    inline static constexpr Quaternion ZeroQ     { 0.f, 0.f, 0.f, 0.f };
    inline static constexpr Quaternion IdentityQ { 0.f, 0.f, 0.f, 1.f };
}



class Camera;

class Free_Look {
public:
    inline static constexpr f32 CLAMP_ANGLE = 89.f;

    Free_Look() = default;
    ~Free_Look() = default;
    
    fn init(Camera* camera) { m_camera = camera; }

    fn move_forward(f32 dt) -> void;
    fn move_backward(f32 dt) -> void;
    fn move_right(f32 dt) -> void;
    fn move_left(f32 dt) -> void;
    fn move_up(f32 dt) -> void;
    fn move_down(f32 dt) -> void;
    fn rotate(f32 dx, f32 dy) -> void;
    fn forward() const -> Vector3;
    fn right() const -> Vector3;
    
    f32 speed = 40.f;
    f32 sensivity = 0.1f;

private:
    Camera* m_camera = nullptr;
};

// =========================================
// @Region: Camera
// =========================================

class Camera {
public:
    enum Mode : u8 {
          None
        , Perspective
        , Orthographic
    };

    Camera(Mode mode)
        : mode(mode) 
    {
        // @Note: Default values for 3D.
        if (mode == Mode::Perspective)
        {
            pos = Math::Front3D * 40.f;
            near_plane = 0.1f;
            far_plane = 100.f;
            fov = 60;
            return;
        }

        // @Note: Default values for 2D.
        if (mode == Mode::Orthographic)
        {
            near_plane = 0.f;
            far_plane = 1.f;
            size = 3;
            return;
        }
    }

    Camera() = default;
    ~Camera() = default;

    fn matrix() const -> Matrix4 { return m_matrix; }
    fn update_matrix(i32 viewport_x, i32 viewport_y) -> void;

    Mode mode = Mode::None;
    Vector3 pos = Math::Zero3D;
    Vector3 rot = Math::Zero3D;
    f32  near_plane = 0.f;
    f32  far_plane = 0.f;
    
    // @Note: 2D Specific
    f32 size = 0.f;

    // @Note: 3D Specific
    f32 fov = 0.f;

private:
    Matrix4 m_matrix;
};
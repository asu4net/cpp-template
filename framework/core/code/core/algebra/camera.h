#pragma once

class Camera;

class Free_Look
{
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

class Camera
{
public:
    enum Mode : u8
    {
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

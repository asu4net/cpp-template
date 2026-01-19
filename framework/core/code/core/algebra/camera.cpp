#include "camera.h"

fn Free_Look::move_forward(f32 dt)  -> void { m_camera->pos = m_camera->pos + forward() * (speed * dt); }
fn Free_Look::move_backward(f32 dt) -> void { m_camera->pos = m_camera->pos - forward() * (speed * dt); }
fn Free_Look::move_right(f32 dt)    -> void { m_camera->pos = m_camera->pos + right()   * (speed * dt); }
fn Free_Look::move_left(f32 dt)     -> void { m_camera->pos = m_camera->pos - right()   * (speed * dt); }
fn Free_Look::move_up(f32 dt)       -> void { m_camera->pos.y += speed * dt; }
fn Free_Look::move_down(f32 dt)     -> void { m_camera->pos.y -= speed * dt; }

fn Free_Look::rotate(f32 dx, f32 dy) -> void
{
    m_camera->rot.y -= dx * sensivity; 
    m_camera->rot.x -= dy * sensivity;

    if (m_camera->rot.x > CLAMP_ANGLE)  m_camera->rot.x = CLAMP_ANGLE;
    if (m_camera->rot.x < -CLAMP_ANGLE) m_camera->rot.x = -CLAMP_ANGLE;
}

fn Free_Look::forward() const -> Vector3
{
    f32 pitch = Math::to_radians(m_camera->rot.x);
    f32 yaw = Math::to_radians(m_camera->rot.y);

    return Vector3{
        -cos(pitch) * sin(yaw),
         sin(pitch),
        -cos(pitch) * cos(yaw)
    }.normalized();
}

fn Free_Look::right() const -> Vector3
{
    return Vector3::cross(forward(), Vector3 { 0,1,0 }).normalized();
}

fn Camera::update_matrix(i32 viewport_x, i32 viewport_y) -> void
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

#pragma once

class Time
{
public:
    inline static constexpr u32 FPS_SAMPLES = 240;
    
    Time() = default;
    ~Time() = default;

    fn step() -> void;
    fn frame_time() const -> f32;
    fn frame_rate() const -> f32;
    fn av_frame_rate() const -> f32;
    fn set_scale(f32 scale) -> void;

private:
    // @Pending: Add setters for this two parameters.
    f64 m_max_frame_time = 0.06;
    f64 m_fixed_frame_time = 0.06;

    f64 m_seconds = -1.f;
    f32 m_frame_time = 0.f;
    u32 m_frame_count = 0u;
    f64 m_acc_fixed_frame_time = 0.f;
    f64 m_last_time = 0.f;
    u32 m_fixed_ticks = 0u;
    f32 m_scale = 1.f;

    f32 m_frame_times[FPS_SAMPLES] = {};
    u32 m_frame_index = 0u;
    f32 m_frame_total = 0.f;
};

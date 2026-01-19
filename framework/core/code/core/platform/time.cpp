#include "time.h"

fn Time::step() -> void
{
    //@Note: Lazy init.
    if (m_seconds < 0) 
    {
        m_last_time = Core::get_time();
        m_acc_fixed_frame_time = m_fixed_frame_time;
        m_seconds = 0;
    }

    f64 current_time = Core::get_time();
    m_frame_count += 1;
    f64 time_between_frames = current_time - m_last_time;
    m_last_time = current_time;
    m_seconds += time_between_frames;
    m_frame_time = (f32) std::clamp(time_between_frames, 0.0, m_max_frame_time) * m_scale;
    m_acc_fixed_frame_time += m_frame_time;

    while (m_acc_fixed_frame_time >= m_fixed_frame_time)
    {
        m_acc_fixed_frame_time -= m_fixed_frame_time;
        m_fixed_ticks += 1;
    }

    m_frame_total -= m_frame_times[m_frame_index];
    m_frame_times[m_frame_index] = m_frame_time;
    m_frame_total += m_frame_time;
    m_frame_index = (m_frame_index + 1) % FPS_SAMPLES;
}

fn Time::frame_time() const -> f32
{
    return m_frame_time;
}

fn Time::frame_rate() const -> f32
{
    f32 av = m_frame_total / FPS_SAMPLES;
    return av > 0.f ? 1.f / av : 0.f;
}

fn Time::av_frame_rate() const -> f32
{
    return (f32) m_frame_count / (f32) m_seconds;
}

fn Time::set_scale(f32 scale) -> void
{
    m_scale = scale;
}

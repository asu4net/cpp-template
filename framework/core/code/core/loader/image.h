#pragma once

// @Note: Helper class for loading images from disk.
// @Pending: Add write implementation.
class Image
{
public:
    static fn white() -> const Image&;

    Image() = default;
    Image(u8* data, i32 width, i32 height, i32 channels);
    Image(std::string_view filename);
    ~Image();
    
    Image(const Image&) = delete;
    Image(Image&&) noexcept = delete;

    fn operator=(const Image&) -> Image& = delete;
    fn operator=(Image&&) noexcept -> Image& = delete;
    
    fn data() const -> const u8* { return m_data; }
    fn width() const -> i32 { return m_width; }
    fn height() const -> i32 { return m_height; }
    fn channels() const -> i32 { return m_channels; }
    fn valid() const -> bool;

private:
    u8* m_data = nullptr;
    i32 m_width = 0;
    i32 m_height = 0;
    i32 m_channels = 0;
    bool m_is_owner = false;
};

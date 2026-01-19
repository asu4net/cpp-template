#pragma once

struct Window_Desc
{
    enum Flags : u8
    {
        NONE = 0,
        SHOW = 1 << 0,
        CONTEXT = 1 << 1,
        MAIN_WINDOW = 1 << 2,
        ALL = SHOW | CONTEXT | MAIN_WINDOW,
    };
    
    std::wstring_view title = L"The Window";
    i32 width  = 1280;
    i32 height = 720;
    Flags flags = ALL;
    Vector3 bg_color = Color::Chill_Green;
};

class IWindow
{
public:
    using Weak_Ptr = std::weak_ptr<IWindow>;
    using Ptr = std::shared_ptr<IWindow>;

    static fn create(const Window_Desc& ds = {})->Ptr;

    virtual ~IWindow() = default;
    
    virtual fn handle() const -> void* = 0;
    virtual fn show() const -> void = 0;
    virtual fn present(bool vsync = true) const -> void = 0;
};

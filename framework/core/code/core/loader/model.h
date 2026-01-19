#pragma once

class Model
{
public:
    struct Vertex
    {
        Vector3 pos;
        Vector2 uv;
        Vector3 normal;
        Vector4 color;
    };
    
    // @Note: Shapes are parts of the model who use different materials.
    struct Shape
    {
        struct 
        {
            std::string ambient;
            std::string diffuse;
        } textures;

        std::string name;
        u32 index_offset = 0;
        u32 index_count = 0;
        u32 material_index = 0;
    };
    
    Model(std::string_view filename, bool normals_as_colors = false);
    ~Model() = default;

    Model(const Model&) = delete;
    Model(Model&&) noexcept = delete;

    fn operator=(const Model&) -> Model& = delete;
    fn operator=(Model&&) noexcept -> Model& = delete;
    
    fn loaded() const -> bool { return m_loaded; }
    fn dirpath() const -> std::string_view { return m_dirpath; }

    // @Note: These are non-constant vector references because we want to steal them later, from the mesh class.
    fn name() const -> const std::string& { return m_name; }
    fn vertices() -> std::vector<Vertex>& { return m_vertices; }
    fn indices() -> std::vector<u32>& { return m_indices; }
    fn shapes() -> std::vector<Shape>& { return m_shapes; }

private:
    bool m_loaded = false;
    std::string m_name;
    std::vector<Vertex> m_vertices;
    std::vector<u32> m_indices;
    std::vector<Shape> m_shapes;
    std::string m_dirpath;
};

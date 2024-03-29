#ifndef SUBMESH_H
#define SUBMESH_H

#include <vector>
#include <glm/glm.hpp>
#include "Texture.hpp"
#include "Shader.hpp"
#include "Material.hpp"

#define MAX_BONE_INFLUENCE 4

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;

    int m_BoneIDs[MAX_BONE_INFLUENCE];
    float m_fWeights[MAX_BONE_INFLUENCE];
};

class SubMesh
{
    public:
        SubMesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture*> _textures, Material *mat);
        ~SubMesh();

        void Render(Shader *);

        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture*> textures;
    private:
        void SetupMesh();

        unsigned int m_UIVAO, m_UIVBO, m_UIEBO;
        Material *material;
};

#endif //SUBMESH_H
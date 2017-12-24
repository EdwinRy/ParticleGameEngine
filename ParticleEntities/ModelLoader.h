#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
using namespace std;

namespace Entity
{
    class FileInputStream;

    struct MeshData
    {
        string name;
        vector<float> positions, textures, normals;
        vector<unsigned int> indices;
    };

    class ModelLoader
    {
    public:
        void loadOBJ(string path);
        MeshData popMesh();
        bool hasNextMesh();
    private:
        void buildFace(FileInputStream *stream);
        void nextMesh(string name);

        vector<MeshData> meshData;
        vector<glm::vec3> positions;
        vector<glm::vec2> textures;
        vector<glm::vec3> normals;
        MeshData currMesh;
        bool isStartOfFile;
    };

}

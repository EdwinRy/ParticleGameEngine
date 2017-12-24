#include "ModelLoader.h"
#include "FileStream.h"
#include <iostream>
using namespace Entity;
using namespace glm;

#define NEXT_INT(i, data) \
    (i) = atoi(data); \
    (data) = strchr(data, '/') + 1

inline void readVertexData(string vertex, int *v, int *t, int *n)
{
    const char *data = vertex.data();
    NEXT_INT(*v, data);
    NEXT_INT(*t, data);
    *n = atoi(data);
}

void ModelLoader::loadOBJ(string path)
{
    // Open file stream and clear buffers
    FileInputStream stream(path);
    positions.clear();
    textures.clear();
    normals.clear();
    isStartOfFile = true;

    while (!stream.isEndOfFile())
    {
        string command = stream.readWord();
        if (command == "v")
            positions.push_back(stream.readVec3());

        else if (command == "vt")
            textures.push_back(stream.readVec2());
        
        else if (command == "vn")
            normals.push_back(stream.readVec3());
        
        // Build face with data
        else if (command == "f")
            buildFace(&stream);
        
        // Next object
        else if (command == "o")
            nextMesh(stream.readWord());
        
        // If unkown or comment, then skip line
        else
            stream.readLine();
    }

    if (!isStartOfFile)
        meshData.push_back(currMesh);
}

void ModelLoader::buildFace(FileInputStream *stream)
{
    int v, t, n;
    for (int i = 0; i < 3; i++)
    {
        // Read vertex data
        string face = stream->readWord();
        readVertexData(face, &v, &t, &n);

        // Push data to mesh
        vec3 position = positions[v - 1];
        currMesh.positions.push_back(position.x);
        currMesh.positions.push_back(position.y);
        currMesh.positions.push_back(position.z);

        vec2 texture = textures[t - 1];
        currMesh.textures.push_back(texture.x);
        currMesh.textures.push_back(texture.y);

        vec3 normal = normals[n - 1];
        currMesh.normals.push_back(normal.x);
        currMesh.normals.push_back(normal.y);
        currMesh.normals.push_back(normal.z);

        // Push next index
        currMesh.indices.push_back(currMesh.indices.size());
    }
}

// Rotate to the next mesh
void ModelLoader::nextMesh(string name)
{
    if (!isStartOfFile)
        meshData.push_back(currMesh);
    currMesh = {name};
    isStartOfFile = false;
}

MeshData ModelLoader::popMesh()
{
    MeshData mesh = meshData[meshData.size()-1];
    meshData.pop_back();
    return mesh;
}

bool ModelLoader::hasNextMesh()
{
    return meshData.size() > 0;
}

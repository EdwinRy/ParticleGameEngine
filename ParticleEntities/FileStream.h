#pragma once
#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
using namespace std;

namespace Entity
{

    class FileInputStream
    {
    public:
        FileInputStream(string path);
        
        string readAll();
        string readLine();
        string readWord();
        float readFloat();
        glm::vec2 readVec2();
        glm::vec3 readVec3();
        char readChar();

        int getLength() { return length; }
        string getPath() { return path; }
        bool isEndOfFile() { return eof; }

        ~FileInputStream();
    private:
        FILE *file;
        string path;
        int length;
        bool eof;
    };

}

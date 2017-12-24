#include "FileStream.h"
#include <vector>
using namespace glm;
using namespace Entity;

FileInputStream::FileInputStream(string path) :
    path(path), eof(false)
{
    // Open file and read length
    file = fopen(path.c_str(), "rb");
    fseek(file, 0L, SEEK_END);
    length = ftell(file);
    rewind(file);
}

string FileInputStream::readAll()
{
    vector<char> buffer(length);
    fread(&buffer[0], sizeof(char), length, file);
    return string(buffer.data());
}

string FileInputStream::readLine()
{
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, file) == -1)
        eof = true;

    return string(line);
}

// Reads text surrounded by white space
string FileInputStream::readWord()
{
    string word;
    char c;

    // Skip white space
    while (isspace(c = readChar()) && !eof)
        continue;

    // Read until next white space
    while (!isspace(c) && !eof)
    {
        word += c;
        c = readChar();
    }
    
    return word;
}

float FileInputStream::readFloat()
{
    string word = readWord();
    return atof(word.c_str());
}

vec2 FileInputStream::readVec2()
{
    return vec2(readFloat(), readFloat());
}

vec3 FileInputStream::readVec3()
{
    return vec3(readVec2(), readFloat());
}

char FileInputStream::readChar()
{
    char c = fgetc(file);
    if (c == EOF)
        eof = true;
    return c;
}

FileInputStream::~FileInputStream()
{
    fclose(file);
}

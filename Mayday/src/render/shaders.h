#ifndef __SHADERS_H__
#define __SHADERS_H__

#include "../include.hpp"

static unsigned int CompileShader(unsigned int type, const char* source)
{
    unsigned int id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        const char* tp = (type == GL_VERTEX_SHADER) ? "vertex" : "fragment";
        printf("Error: Failed to compile %s shader!\n", tp);
        printf("Error-log: %s \n", message);
        glDeleteShader(id);

        return 0;
    }

    return id;
}

static unsigned int CreateShader(const char* vertexShader, const char* fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec2 position;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n"
    "}\n";

const char* fragmentShaderSource = "#version 330 core\n"
        "uniform vec4 color;\n"
        "out vec4 fragColor;\n"
        "void main()\n"
        "{\n"
        "   fragColor = color;\n"
    "}\n";

#endif // __SHADERS_H__
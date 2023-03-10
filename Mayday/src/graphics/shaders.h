#pragma once

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

const char* vertexShader =
	"#version 330 core\n"
	"\n"
	"layout(location = 0) in vec4 position;\n"
	"\n"
	"void main()\n"
	"{\n"
	" gl_Position = position;\n"
	"}\n";

const char* fragmentShader =
	"#version 330 core\n"
	"\n"
	"layout(location = 0) out vec4 color;\n"
	"\n"
	"void main()\n"
	"{\n"
	" color = vec4(1.0, 0.0, 0.0, 1.0);\n"
	"}\n";

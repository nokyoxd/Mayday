#include "include.hpp"
#include "graphics/shaders.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(640, 480, "Mayday", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLEW library */
    if (glewInit() != GLEW_OK)
        return -1;

    printf("Status: Initialized GLFW (%s)\n", glfwGetVersionString());
    printf("Status: Initialized GLEW (%s)\n", glGetString(GL_VERSION));

    float pos[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), pos, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /* Terminate GLFW content */
    glfwTerminate();

    return 0;
}
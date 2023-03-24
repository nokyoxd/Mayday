#include "include.hpp"
#include "graphics/shaders.h"
#include "input/input.h"

static int x = 10;
static int y = 10;

int main(void)
{
    GLFWwindow* window;

    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(1240, 820, "Mayday", NULL, NULL);
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

    /* Position of the element points */
    float vertices[] = {
        0.5f, 0.5f, 0.0f,       // top right
        0.5f, -0.5f, 0.0f,      // bottom right
        -0.5f, -0.5f, 0.0f,     // bottom left
        -0.5f, 0.5f, 0.0f,      // top left
        -0.2f, 0.2f, 0.0f       // bottom left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int VBO, VAO, EBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    /* Create program shader */
    unsigned int iShader = CreateShader(vertexShaderSource, fragmentShaderSource);
    glUseProgram(iShader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Set position of view */
        glViewport(x, y, 200, 200);

        /* Handle user input */
        handle_input(&x, &y);

        // Clear color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Bind VAO
        glBindVertexArray(VAO);

        // Draw the triangle
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Unbind VAO
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /* Terminate GLFW content */
    glfwTerminate();

    return 0;
}
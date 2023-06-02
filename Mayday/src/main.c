#include "include.hpp"
#include "graphics/shaders.h"
#include "input/input_handler.h"
#include "graphics/renderer.h"

int width = 640;
int height = 840;

GLFWwindow* window;
entity_t* ship;

globals_t _G = {
    .m_iState = 0,
};

// Callback function for handling GLFW errors
void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

int init_glfw(void) {
    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(width, height, "Mayday", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Disable window resizing
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GL_FALSE);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    return 0;
}

int init_glew(void) {
    /* Initialize GLEW library */
    if (glewInit() != GLEW_OK)
        return -1;

    // Set the viewport dimensions
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    return 0;
}

int render(void) {

    // Inside the rendering loop
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Clear the screen
    glClearColor(0.0784f, 0.0784f, 0.0784f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    switch (_G.m_iState)
    {
    case 0:
    {

        break;
    }
    case 1:
    {
        // Handle player input
        handle_movement(ship);

        // Render ship triangle
        render_triangle(ship->pos, 25.f, color_new(1.f, 1.f, 1.f, 0.5f));
        break;
    }
    case 2:
    {
        break;
    }
    }

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int clean_up(void) {
    // Clean up resources
    free(ship);
    glfwTerminate();
}

int main(void) {
    assert_fn(init_glfw, 0);
    assert_fn(init_glew, 0);

    ship = entity_new(vec2_new(width, height));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        handle_input(&_G);

        render();

        Sleep(10);
    }

    clean_up();

    return 0;
}
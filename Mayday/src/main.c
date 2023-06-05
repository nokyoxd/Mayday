#include "include.hpp"
#include "input/input_handler.h"
#include "graphics/render_handler.h"

// Callback function for handling GLFW errors
void errorCallback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

int init_glfw(void) {
    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(g.width, g.height, "Mayday", NULL, NULL);
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
    glfwGetFramebufferSize(window, &g.width, &g.height);
    glViewport(0, 0, g.width, g.height);

    return 0;
}

int clean_up(void) {
    // Clean up resources
    free(ship);
    glfwTerminate();

    return 0;
}

int main(void) {
    // Setup libraries
    assert_fn(init_glfw, 0);
    assert_fn(init_glew, 0);

    // Allocate memory for entity
    ship = entity_new(vec2_new(g.width, g.height));

    // Randomize rand() function
    srand(time(NULL));

    // Generate random positions and rotation
    for (int i = 0; i < 40; ++i)
    {
        poses[i] = vec2_new(random_float(1.f, g.width), random_float(1.f, g.height));
        rotate[i] = 0 - (rand() % 720);
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Handle user input
        handle_input();

        // Resolve the sizes
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, g.width, 0, g.height, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Clear the screen
        glClearColor(0.0784f, 0.0784f, 0.0784f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Handle object rendering
        handle_render();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Save some performance
        Sleep(10);
    }

    // Clean up resources
    assert_fn(clean_up, 0);

    return 0;
}
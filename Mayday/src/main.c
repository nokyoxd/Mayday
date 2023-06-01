#include "include.hpp"
#include "graphics/shaders.h"
#include "input/input.h"
#include "graphics/renderer.h"

// Callback function for handling GLFW errors
void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

//void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
//    // Set the desired aspect ratio (e.g., 16:9)
//    float desiredAspectRatio = 9.0f / 16.0f;
//
//    // Calculate the height based on the desired aspect ratio
//    int newHeight = width / desiredAspectRatio;
//
//    // Set the new size of the window
//    glfwSetWindowSize(window, width, newHeight);
//}

int main(void)
{
    GLFWwindow* window;

    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(640, 840, "Mayday", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Set the framebuffer size callback function
    /*glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);*/

    // Disable window resizing
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GL_FALSE);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLEW library */
    if (glewInit() != GLEW_OK)
        return -1;

    printf("Status: Initialized GLFW (%s)\n", glfwGetVersionString());
    printf("Status: Initialized GLEW (%s)\n", glGetString(GL_VERSION));

    /*struct FONScontext* fs = glfonsCreate(512, 512, 1);
    int fontNormal = fonsAddFont(fs, "sans", "DroidSerif-Regular.ttf");
    float dx = 10, dy = 10;
    unsigned int white = glfonsRGBA(255, 255, 255, 255);*/

    entity_t* ship = entity_new();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen
        glClearColor(0.0784f, 0.0784f, 0.0784f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*fonsSetFont(fs, fontNormal);
        fonsSetSize(fs, 124.0f);
        fonsSetColor(fs, white);
        fonsDrawText(fs, dx, dy, "The big ", NULL);*/

        // Handle player input
        handle_input(ship);

        // Ship position
        vec2_t pos = (*ship).pos;

        // Render rectangles
        renderTriangle(pos, 0.08f, color_new(1.f, 1.f, 1.f, 0.5f));

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();

        Sleep(10);
    }

    // Clean up resources
    free(ship);
    glfwTerminate();

    return 0;
}
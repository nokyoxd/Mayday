#include "globals.h"
#include "graphics/shaders.h"
#include "input/input_handler.h"
#include "graphics/renderer.h"

#include <time.h>

GLFWwindow* window;
entity_t* ship;

vec2_t poses[40];
float rotate[40];

// Callback function for handling GLFW errors
void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

int init_glfw(void) {
    /* Initialize GLFW library */
    if (!glfwInit())
        return -1;

    /* Create a window and OpenGL context */
    window = glfwCreateWindow(_G.m_iWidth, _G.m_iHeight, "Mayday", NULL, NULL);
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
    glfwGetFramebufferSize(window, &_G.m_iWidth, &_G.m_iHeight);
    glViewport(0, 0, _G.m_iWidth, _G.m_iHeight);

    return 0;
}

float t = 0.f;
int reverse = 0;
int choise = 3;
float s = 180.f;

int render(void) {

    // Inside the rendering loop
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _G.m_iWidth, 0, _G.m_iHeight, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Clear the screen
    glClearColor(0.0784f, 0.0784f, 0.0784f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    switch (_G.m_iState)
    {
    case 0: // Main stage
    {
        if (reverse == 1)
            t -= 0.2f;
        else
            t += 0.2f;

        for (int i = 0; i < 40; ++i)
            render_triangle(vec2_add(poses[i], vec2_new(t, t)), 25.f, color_new(0.5f, 0.5f, 0.5f, 0.5f), rotate[i]);

        if (t >= 200.f)
            reverse = 1;
        else if (t <= 10.f)
            reverse = 0;

        color_t clr = color_new(0.2f, 0.2f, 0.2f, 0.5f);
        render_rect(vec2_new(s, s), vec2_new(_G.m_iWidth - s, _G.m_iHeight - s), clr);

        for (int i = 1; i <= 3; ++i)
        {
            if (choise == i)
                render_rect(vec2_new(s + 38, s + 8 + (i * 35)), vec2_new(s + 362, s + 32 + (i * 35)), color_new(1.0f, 0.f, 0.f, 0.f));

            render_rect(vec2_new(s + 40, s + 10 + (i * 35)), vec2_new(s + 360, s + 30 + (i * 35)), color_new(0.5f, 0.5f, 0.5f, 0.f));
        }

        handle_selection(&choise);

        break;
    }
    case 1: // Exit stage
    {
        exit(0);

        break;
    }
    case 2: // Settings stage
    {
        color_t clr = color_new(0.2f, 0.2f, 0.2f, 0.5f);
        render_rect(vec2_new(s, s), vec2_new(_G.m_iWidth - s, _G.m_iHeight - s), clr);

        break;
    }
    case 3: // Game stage
    {
        // Handle player input
        handle_movement(ship);

        // Render ship triangle
        render_triangle(ship->pos, 25.f, color_new(1.f, 1.f, 1.f, 0.5f), 0.f);

        break;
    }
    case 4: // Pause stage
    {
        break;
    }
    default: // Invalid stage
        assert(0, "Invalid Input!");
        break;
    }

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int clean_up(void) {
    // Clean up resources
    free(ship);
    glfwTerminate();

    return 0;
}

int main(void) {
    assert_fn(init_glfw, 0);
    assert_fn(init_glew, 0);

    ship = entity_new();

    srand(time(NULL));

    for (int i = 0; i < 40; ++i)
    {
        poses[i] = vec2_new(rand() % (_G.m_iWidth / 2), rand() % (_G.m_iHeight / 2));
        rotate[i] = 0 - (rand() % 720);
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        handle_input();

        render();

        Sleep(10);
    }

    assert_fn(clean_up, 0);

    return 0;
}
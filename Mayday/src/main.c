#include "include.hpp"
#include "input/input_handler.h"
#include "render/render_handler.h"

// Callback function for handling GLFW errors
void errorCallback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

int init_glfw(void) {
    // Initialize glfw  
    if (!glfwInit())
        return -1;

    // OpenGL context 
    window = glfwCreateWindow(g.width, g.height, "Mayday", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Disable window resizing
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GL_FALSE);

    // Windows context current 
    glfwMakeContextCurrent(window);

    return 0;
}

int init_glew(void) {
    // Initialize glew
    if (glewInit() != GLEW_OK)
        return -1;

    // Viewport dimensions
    glfwGetFramebufferSize(window, &g.width, &g.height);
    glViewport(0, 0, g.width, g.height);

    return 0;
}

int clean_up(void) {
    for (int i = 0; i < 100; i++)
        free(bullets[i]);

    for (int i = 0; i < 10; i++)
        free(meteorites[i]);

    // Clean up resources
    free(ship);
    glfwTerminate();

    return 0;
}

int main(void) {
    FILE* file;
    int score, new_score = 0;

    file = fopen("score.txt", "r");
    if (file == NULL) {
        file = fopen("score.txt", "w");
        assert(file != NULL, "File creation error!");
        fclose(file);
    }

    assert(file != NULL, "File open error!");

    int sc = fscanf(file, "%d", &score);
    assert(sc != 1, "File read error!");

    printf("Loaded score: %d\n", score);

    fclose(file);

    // Setup libraries
    assert_fn(init_glfw, 0);
    assert_fn(init_glew, 0);

    // Allocate memory for entity
    ship = entity_new(vec2(g.width, g.height));

    // Randomize rand() function
    srand(time(NULL));

    // Generate random positions and rotation
    for (int i = 0; i < 40; ++i)
    {
        poses[i] = vec2(random_float(1.f, g.width), random_float(1.f, g.height));
        rotate[i] = 0 - (rand() % 720);
    }

    // Main loop
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

        // Handle meteorite render
        handle_meteorites(new_score);

        // Handle bullets movement etc.
        handle_bullets();

        // Handle object rendering
        handle_render();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Save some performance
        Sleep(10);
    }

    // Clean up resources
    clean_up();

    if (new_score > score)
        score = new_score;

    FILE* fl = fopen("score.txt", "w");
    assert(fl != NULL, "File open error! #2");

    fprintf(fl, score);

    fclose(fl);

    return 0;
}
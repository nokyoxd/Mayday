#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shaders.h"
#include "../sdk/datatypes/types.h"
#include "utilities/utilities.h"

void renderTriangle(vec2_t pos, float size, color_t clr)
{
    // Set the color
    glColor4f(clr.r, clr.g, clr.b, clr.a);

    // Calculate vertex positions based on the input parameters
    float halfSize = size / 2.0f;
    float x1 = pos.x - halfSize;
    float y1 = pos.y - halfSize;
    float x2 = pos.x + halfSize;
    float y2 = pos.y - halfSize;
    float x3 = pos.x;
    float y3 = pos.y + halfSize;

    // Render the triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void renderRect(vec2_t pos, vec2_t size, color_t color) {
    // Set the color for rendering
    glColor4f(color.r, color.g, color.b, color.a);

    // Render the rectangle using OpenGL immediate mode
    glBegin(GL_QUADS);
    glVertex2f(pos.x, pos.y);
    glVertex2f(pos.x + size.x, pos.y);
    glVertex2f(pos.x + size.x, pos.y + size.y);
    glVertex2f(pos.x, pos.y + size.y);
    glEnd();
}

void renderMeteor() {
    vec2_t pos;
    pos.x = random_float(-1.f, 1.f);
    pos.y = random_float(-1.f, 1.f);

    vec2_t size;
    size.x = random_float(0.1f, 1.f);
    size.y = random_float(0.1f, 1.f);

    color_t clr = color_new(1.f, 0.f, 0.f, 0.1f);

    renderRect(pos, size, clr);
}
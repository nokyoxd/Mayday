#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shaders.h"
#include "../datatypes/types.h"
#include "utilities/utilities.h"

void render_triangle(vec2_t pos, float size, color_t clr, float rotation)
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

    // Save the current modelview matrix
    glPushMatrix();

    // Translate to the position
    glTranslatef(pos.x, pos.y, 0.0f);

    // Apply rotation
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    // Render the triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    // Restore the previous modelview matrix
    glPopMatrix();
}


void render_rect(vec2_t pos_start, vec2_t size_end, color_t color) {
    // Set the color for rendering
    glColor4f(color.r, color.g, color.b, color.a);

    // Render the rectangle using OpenGL immediate mode
    glBegin(GL_QUADS);
    glVertex2f(pos_start.x, pos_start.y);
    glVertex2f(size_end.x, pos_start.y);
    glVertex2f(size_end.x, size_end.y);
    glVertex2f(pos_start.x, size_end.y);
    glEnd();
}



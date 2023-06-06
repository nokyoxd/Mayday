#include "../include.hpp"

void render_triangle(vec2_t pos, float size, color_t clr, float rotation) {
    // Set the color
    glColor3f(clr.r, clr.g, clr.b);

    // Calculate vertex positions based on the input parameters
    float halfSize = size / 2.0f;
    float x1 = -halfSize;
    float y1 = -halfSize;
    float x2 = halfSize;
    float y2 = -halfSize;
    float x3 = 0.0f;
    float y3 = halfSize;

    // Save the current modelview matrix
    glPushMatrix();

    // Translate to the position
    glTranslatef(pos.x, pos.y, 0.0f);

    // Apply rotation
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    // Translate back to the object's center
    glTranslatef(-pos.x, -pos.y, 0.0f);

    // Render the triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x1 + pos.x, y1 + pos.y);
    glVertex2f(x2 + pos.x, y2 + pos.y);
    glVertex2f(x3 + pos.x, y3 + pos.y);
    glEnd();

    // Restore the previous modelview matrix
    glPopMatrix();
}

void render_rect(vec2_t pos_start, vec2_t size_end, color_t clr) {
    // Set the color for rendering
    glColor3f(clr.r, clr.g, clr.b);

    // Render the rectangle using OpenGL immediate mode
    glBegin(GL_QUADS);
    glVertex2f(pos_start.x, pos_start.y);
    glVertex2f(size_end.x, pos_start.y);
    glVertex2f(size_end.x, size_end.y);
    glVertex2f(pos_start.x, size_end.y);
    glEnd();
}

void render_line(vec2_t start, vec2_t end, color_t clr) {
    // Set the color for rendering
    glColor3f(clr.r, clr.g, clr.b);

    // Render the line using OpenGL immediate mode
    glBegin(GL_LINES);
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
}

void render_meteorite(vec2_t pos, float size, color_t clr) {
    // Set the color of the meteorite
    glColor3f(clr.r, clr.g, clr.b);

    // Generate random sizes for each axis
    float sizeX = size * (0.5 + rand() / (float)RAND_MAX);  // Random size on X-axis
    float sizeY = size * (0.5 + rand() / (float)RAND_MAX);  // Random size on Y-axis
    float sizeZ = size * (0.5 + rand() / (float)RAND_MAX);  // Random size on Z-axis

    // Render the meteorite as a 6-axis rectangle
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);

    // Back face
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);

    // Top face
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);

    // Bottom face
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);

    // Left face
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);

    // Right face
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);

    glEnd();
}




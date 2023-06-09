#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "../include.hpp"
#include "pixel_data.h"

void render_triangle(vec2_t pos, float size, color_t clr, float rotation) {
    glColor3f(clr.r, clr.g, clr.b);

    // Vertex positions 
    const float halfSize = size / 2.0f;
    const float x1 = -halfSize;
    const float y1 = -halfSize;
    const float x2 = halfSize;
    const float y2 = -halfSize;
    const float x3 = 0.0f;
    const float y3 = halfSize;

    // Save the matrix
    glPushMatrix();

    // Translate to the position
    glTranslatef(pos.x, pos.y, 0.0f);

    // Rotation
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    // Translate to the objects center
    glTranslatef(-pos.x, -pos.y, 0.0f);

    glBegin(GL_TRIANGLES);

    // Positions
    glVertex2f(x1 + pos.x, y1 + pos.y);
    glVertex2f(x2 + pos.x, y2 + pos.y);
    glVertex2f(x3 + pos.x, y3 + pos.y);

    glEnd();

    // Restore matrix
    glPopMatrix();
}

void render_rect(vec2_t pos_start, vec2_t size_end, color_t clr) {
    glColor3f(clr.r, clr.g, clr.b);

    glBegin(GL_QUADS);

    // Positions
    glVertex2f(pos_start.x, pos_start.y);
    glVertex2f(size_end.x, pos_start.y);
    glVertex2f(size_end.x, size_end.y);
    glVertex2f(pos_start.x, size_end.y);

    glEnd();
}

void render_line(vec2_t start, vec2_t end, color_t clr) {
    glColor3f(clr.r, clr.g, clr.b);

    glBegin(GL_LINES);

    // Positions
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);

    glEnd();
}

void render_meteorite(vec2_t pos, float size, color_t clr) {
    glColor3f(clr.r, clr.g, clr.b);

    // Random sizes
    const float sizeX = size * (0.5 + rand() / (float)RAND_MAX);  
    const float sizeY = size * (0.5 + rand() / (float)RAND_MAX);
    const float sizeZ = size * (0.5 + rand() / (float)RAND_MAX);

    // 6-axis rectangle
    glBegin(GL_QUADS);

    // Front 
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);

    // Back 
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);

    // Top 
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);

    // Bottom 
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);

    // Left 
    glVertex3f(pos.x - sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x - sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x - sizeX, pos.y - sizeY, -sizeZ);

    // Right 
    glVertex3f(pos.x + sizeX, pos.y - sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, 0);
    glVertex3f(pos.x + sizeX, pos.y + sizeY, -sizeZ);
    glVertex3f(pos.x + sizeX, pos.y - sizeY, -sizeZ);

    glEnd();
}

void render_letter(char letter, vec2_t position, float size, color_t color) {
    const int letterWidth = 5; 
    const int letterHeight = 5; 

    int letterIndex;
    if (letter >= 'A' && letter <= 'Z') {
        letterIndex = letter - 'A';
        for (int row = 0; row < letterHeight; row++) {
            for (int col = 0; col < letterWidth; col++) {
                if (lettersData[letterIndex][row][col] == 1) {
                    vec2_t pixelPosition = {
                        position.x + col * size,
                        position.y - row * size
                    };

                    render_rect(pixelPosition, vec2(pixelPosition.x + size, pixelPosition.y - size), color);
                }
            }
        }
    }
    else if (letter >= '0' && letter <= '9') {
        letterIndex = letter - '0';
        for (int row = 0; row < letterHeight; row++) {
            for (int col = 0; col < letterWidth; col++) {
                if (numbersData[letterIndex][row][col] == 1) {
                    vec2_t pixelPosition = {
                        position.x + col * size,
                        position.y - row * size
                    };

                    render_rect(pixelPosition, vec2(pixelPosition.x + size, pixelPosition.y - size), color);
                }
            }
        }
    }
}

void render_text(const char* str, vec2_t position, float size, color_t color) {
    const int strLength = strlen(str);
    float xOffset = 0.0f;

    for (int i = 0; i < strLength; i++) {
        char letter = toupper(str[i]);
        render_letter(letter, vec2_add(position, vec2(xOffset, 0.0f)), size, color);
        xOffset += size * 6.0f; 
    }
}

#endif // __RENDERER_H__
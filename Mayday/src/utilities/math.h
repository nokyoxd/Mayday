#pragma once

#include <math.h>
#include "../datatypes/data.h"

#define M_PI 3.14159265358979323846

vec2_t new_pos(vec2_t curPos, float rotation, float distance) {
    // Convert the range
    float relative = (rotation + 90.0f) * M_PI / 180.0f;

    // Calculate new position
    vec2_t newPos;
    newPos.x = curPos.x + distance * cos(relative);
    newPos.y = curPos.y + distance * sin(relative);

    // Clamp for the screen size
    newPos.x = fmax(0.f, fmin(newPos.x, 768.f));
    newPos.y = fmax(0.f, fmin(newPos.y, 550.f));

    return newPos;
}

int in_bounds(vec2_t bulletPos, vec2_t meteoritePos, float meteoriteSize) {
    // Calculate meteorite "hitbox"
    float bulletMinX = bulletPos.x - 1.f / 2.0f;
    float bulletMaxX = bulletPos.x + 1.f / 2.0f;
    float bulletMinY = bulletPos.y - 1.f / 2.0f;
    float bulletMaxY = bulletPos.y + 1.f / 2.0f;

    float meteoriteMinX = meteoritePos.x - meteoriteSize / 2.0f;
    float meteoriteMaxX = meteoritePos.x + meteoriteSize / 2.0f;
    float meteoriteMinY = meteoritePos.y - meteoriteSize / 2.0f;
    float meteoriteMaxY = meteoritePos.y + meteoriteSize / 2.0f;

    // Check for penetration
    if (bulletMaxX >= meteoriteMinX && bulletMinX <= meteoriteMaxX &&
        bulletMaxY >= meteoriteMinY && bulletMinY <= meteoriteMaxY) {
        return 1;
    }

    return 0; 
}


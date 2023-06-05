#pragma once

#include <math.h>
#include "../datatypes/types.h"

#define M_PI 3.14159265358979323846

vec2_t new_pos(vec2_t curPos, float rotation, float distance) {
    // Convert the relative rotation from degrees to radians and adjust the orientation
    float relative = (rotation + 90.0f) * M_PI / 180.0f;

    // Calculate the new position using trigonometric functions
    vec2_t newPos;
    newPos.x = curPos.x + distance * cos(relative);
    newPos.y = curPos.y + distance * sin(relative);

    return newPos;
}

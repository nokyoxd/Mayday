#ifndef __MATH_H__
#define __MATH_H__

#include <math.h>
#include "../datatypes/data.h"

#define M_PI 3.14159265358979323846

vec2_t calculate_pos(vec2_t _curPos, float _rotation, float _distance) {
    // Convert the range
    float relative = (_rotation + 90.0f) * M_PI / 180.0f;

    // Calculate new position
    vec2_t newPos;
    newPos.x = _curPos.x + _distance * cos(relative);
    newPos.y = _curPos.y + _distance * sin(relative);

    // Clamp for the screen size
    newPos.x = fmax(0, fmin(newPos.x, 768));
    newPos.y = fmax(0, fmin(newPos.y, 550));

    return newPos;
}

int in_bounds(vec2_t _bulletPos, vec2_t _meteoritePos, float _meteoriteSize) {
    // Calculate meteorite "hitbox"
    float bulletMinX = _bulletPos.x - 1.f / 2.0f;
    float bulletMaxX = _bulletPos.x + 1.f / 2.0f;
    float bulletMinY = _bulletPos.y - 1.f / 2.0f;
    float bulletMaxY = _bulletPos.y + 1.f / 2.0f;

    float meteoriteMinX = _meteoritePos.x - _meteoriteSize / 2.0f;
    float meteoriteMaxX = _meteoritePos.x + _meteoriteSize / 2.0f;
    float meteoriteMinY = _meteoritePos.y - _meteoriteSize / 2.0f;
    float meteoriteMaxY = _meteoritePos.y + _meteoriteSize / 2.0f;

    // Check for penetration
    if (bulletMaxX >= meteoriteMinX && 
        bulletMinX <= meteoriteMaxX &&
        bulletMaxY >= meteoriteMinY && 
        bulletMinY <= meteoriteMaxY) {
        return 1;
    }

    return 0; 
}

#endif // __MATH_H__
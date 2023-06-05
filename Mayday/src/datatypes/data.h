#pragma once

// *********************************************
// section vec2 data type
// *********************************************

typedef struct {
    float x, y;
} vec2_t;

vec2_t vec2_new(float _x, float _y) {
    vec2_t vec;
    vec.x = _x;
    vec.y = _y;

    return vec;
}

vec2_t vec2_add(vec2_t v1, vec2_t v2) {
    vec2_t result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

// *********************************************
// section vec3 data type (useless)
// *********************************************

typedef struct {
    float x, y, z;
} vec3_t;

vec3_t vec3_new(float _x, float _y, float _z) {
    vec3_t vec;
    vec.x = _x;
    vec.y = _y;
    vec.z = _z;

    return vec;
}

vec3_t vec3_add(vec3_t v1, vec3_t v2) {
    vec3_t result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;

    return result;
}

// *********************************************
// section color data type
// *********************************************

typedef struct {
    float r, g, b, a;
} color_t;

color_t color_new(float _r, float _g, float _b) {
    color_t clr;
    clr.r = _r;
    clr.g = _g;
    clr.b = _b;
    clr.a = 1.f;

    return clr;
}

#ifndef __DATA_H__
#define __DATA_H__

// *********************************************
//               VECTOR 2D
// *********************************************

typedef struct {
    float x, y;
} vec2_t;

vec2_t vec2(float _x, float _y) {
    vec2_t vec;
    vec.x = _x;
    vec.y = _y;

    return vec;
}

vec2_t vec2_add(vec2_t _v1, vec2_t _v2) {
    vec2_t result;
    result.x = _v1.x + _v2.x;
    result.y = _v1.y + _v2.y;

    return result;
}

// *********************************************
//              VECTOR 3D
// *********************************************

typedef struct {
    float x, y, z;
} vec3_t;

vec3_t vec3(float _x, float _y, float _z) {
    vec3_t vec;
    vec.x = _x;
    vec.y = _y;
    vec.z = _z;

    return vec;
}

vec3_t vec3_add(vec3_t _v1, vec3_t _v2) {
    vec3_t result;
    result.x = _v1.x + _v2.x;
    result.y = _v1.y + _v2.y;
    result.z = _v1.z + _v2.z;

    return result;
}

// *********************************************
//                  COLOR
// *********************************************

typedef struct {
    float r, g, b, a;
} color_t;

color_t color(float _r, float _g, float _b) {
    color_t clr;
    clr.r = _r;
    clr.g = _g;
    clr.b = _b;
    clr.a = 1.f;

    return clr;
}

// *********************************************
//                  GLOBALS
// *********************************************

typedef enum {
    stage_main = 0,
    stage_exit,
    stage_game,
    stage_end,
} e_stages;

typedef struct {
    e_stages stage;
    int width;
    int height;
} globals_t;

#endif // __DATA_H__

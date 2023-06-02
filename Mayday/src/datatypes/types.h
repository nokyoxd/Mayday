#pragma once
#include "../utilities/utilities.h"

#define new(type) ((type*)malloc(sizeof(type)))

typedef struct {
    float x, y;
} vec2_t;

vec2_t vec2_new(float _x, float _y) {
    vec2_t vec;
    vec.x = _x;
    vec.y = _y;

    return vec;
}

typedef struct {
	float r, g, b, a;
} color_t;

color_t color_new(float _r, float _g, float _b, float _a) {
    color_t clr;
    clr.r = _r;
    clr.g = _g;
    clr.b = _b;
    clr.a = _a;

    return clr;
}

typedef struct {
    vec2_t pos;
    int health;
} entity_t;

entity_t* entity_new(vec2_t size) {
    entity_t* ent = new(entity_t);
    assert(ent != NULL, "Invalid entity pointer");

    ent->pos = vec2_new(size.x / 2, size.y / 5);
    ent->health = 100;

    return ent;
}

typedef struct {
    int m_iState;
} globals_t;


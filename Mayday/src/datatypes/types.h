#pragma once
#include "../include.hpp"
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

vec2_t vec2_add(vec2_t v1, vec2_t v2) {
    vec2_t result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

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

typedef struct {
    vec2_t pos;
    int health;
    float rotation;
} entity_t;

entity_t* entity_new(vec2_t size) {
    entity_t* ent = new(entity_t);
    assert(ent != NULL, "Invalid entity pointer!");

    ent->pos = vec2_new(size.x / 2, size.y / 2);
    ent->health = 100;
    ent->rotation = 0.f;

    return ent;
}

typedef struct {
    vec2_t startPos;
    vec2_t endPos;
} bullet_t;

typedef enum
{
    stage_main = 0,
    stage_exit,
    stage_settings,
    stage_game,
    stage_pause,
} e_stages;

typedef struct {
    e_stages stage;
    int width;
    int height;
} globals_t;


#pragma once

#include "../include.hpp"

// *********************************************
// section entity data type
// *********************************************

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

// *********************************************
// section bullet data type
// *********************************************

typedef struct {
    vec2_t startPos;
    vec2_t endPos;
} bullet_t;

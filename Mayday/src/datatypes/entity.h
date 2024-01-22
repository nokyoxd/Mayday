#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "../include.hpp"

// *********************************************
//              ENTITIES/OBJECTS
// *********************************************

typedef struct {
    vec2_t pos;
    int health;
    float rotation;
} entity_t;

typedef struct {
    vec2_t startPos;
    vec2_t endPos;
    float rotation;
} bullet_t;

// *********************************************
//          ENTITIES/OBJECTS FUNCS
// *********************************************

entity_t* meteorites[10];
bullet_t* bullets[100];

entity_t* entity_new(vec2_t size) {
    entity_t* ent = new(entity_t);
    assert(ent != NULL, "Invalid entity pointer!");

    ent->pos = vec2(size.x / 2, size.y / 2);
    ent->health = 100;
    ent->rotation = 0.f;

    return ent;
}

entity_t* meteorite_new() {
    entity_t* me = new(entity_t);
    assert(me != NULL, "Invalid meteorite pointer!");

    // Random position and rotation
    me->pos.x = random_float(0.f, 768);
    me->pos.y = random_float(0.f, 550);
    me->rotation = random_float(-360.f, 360.f);
    me->health = 100;

    for (int i = 0; i < 10; i++) {
        if (meteorites[i] != NULL)
            continue;

        meteorites[i] = me; 
        break;
    }

    return me;
}

void handle_meteorites(int* _score) {
    for (int i = 0; i < 10; i++) {
        if (meteorites[i] == NULL) {
            meteorite_new();
            return;
        } else {
            for (int x = 0; x < 100; x++) {
                if (bullets[x] == NULL)
                    continue;

                vec2_t bulletPos = bullets[x]->startPos;
                vec2_t mePos = meteorites[i]->pos;

                int is_in_bounds = in_bounds(bulletPos, mePos, 25.f);
                if (is_in_bounds)
                    meteorites[i]->health -= 10.f;
            }

            if (meteorites[i]->health <= 0.f)
            {
                meteorites[i] = NULL;
                (*_score)++;
            }
        }
    }
}

bullet_t* bullet_new(entity_t* ship) {
    bullet_t* bull = new(bullet_t);
    assert(bull != NULL, "Invalid bullet pointer!");

    bull->startPos = ship->pos;
    bull->endPos = ship->pos;
    bull->rotation = ship->rotation;

    for (int i = 0; i < 100; i++) {
        if (bullets[i] != NULL)
            continue;

        bullets[i] = bull;
        break;
    }

    return bull;
}

void handle_bullets() {
    for (int i = 0; i < 100; i++) {
        bullet_t* bullet = bullets[i];
        if (bullet == NULL)
            continue;

        // Update the position
        bullet->startPos = calculate_pos(bullet->startPos, bullet->rotation, 10.f);
        bullet->endPos = calculate_pos(bullet->startPos, bullet->rotation, 10.f);

        // Delete the bullet
        if (bullet->startPos.x > 763.f || bullet->startPos.x < 5.f) 
            bullets[i] = NULL;
          
        // Delete the bullet
        if (bullet->startPos.y > 545.f || bullet->startPos.y < 5.f) 
            bullets[i] = NULL;
    }
}

#endif // __ENTITY_H__
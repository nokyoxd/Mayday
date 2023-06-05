#pragma once

typedef enum {
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


#pragma once
#include "../include.hpp"
#include "renderer.h"

float t = 0.f;
int reverse = 0;
float s = 180.f;

int handle_render(void) {

    switch (g.stage)
    {
    case stage_main: 
    {
        if (reverse == 1)
            t -= 0.2f;
        else
            t += 0.2f;

        for (int i = 0; i < 40; ++i)
            render_triangle(vec2_add(poses[i], vec2_new(t, t)), 25.f, color_new(0.5f, 0.5f, 0.5f), rotate[i]);

        if (t >= 200.f)
            reverse = 1;
        else if (t <= 10.f)
            reverse = 0;

        color_t clr = color_new(0.2f, 0.2f, 0.2f);
        render_rect(vec2_new(s, s), vec2_new(g.width - s, g.height - s), clr);

        for (int i = 1; i <= 3; ++i)
        {
            if (choise == i)
                render_rect(vec2_new(s + 38, s + 8 + (i * 35)), vec2_new(s + 362, s + 32 + (i * 35)), color_new(1.0f, 0.f, 0.f));

            render_rect(vec2_new(s + 40, s + 10 + (i * 35)), vec2_new(s + 360, s + 30 + (i * 35)), color_new(0.5f, 0.5f, 0.5f));
        }

        break;
    }
    case stage_exit:
    {
        exit(0);

        break;
    }
    case stage_settings:
    {
        color_t clr = color_new(0.2f, 0.2f, 0.2f);
        render_rect(vec2_new(s, s), vec2_new(g.width - s, g.height - s), clr);

        break;
    }
    case stage_game:
    {
        render_meteorite(vec2_new(100.f, 100.f), 25.f, color_new(0.6f, 0.6f, 0.6f));

        render_rect(vec2_new(g.width - 205, g.height - 30), vec2_new(g.width - 15, g.height - 10), color_new(0.4f, 0.4f, 0.4f));
        int parts = ship->health / 20;

        for (int i = 0; i < parts; ++i)
            render_rect(vec2_new(g.width - 52 - (37 * i), g.height - 28), vec2_new(g.width - 20 - (37 * i), g.height - 12), color_new(1.f, 0.f, 0.f));

        // Render ship triangle
        render_triangle(ship->pos, 25.f, color_new(1.f, 1.f, 1.f), ship->rotation);

        break;
    }
    case stage_pause:
    {
        color_t clr = color_new(0.2f, 0.2f, 0.2f);
        render_rect(vec2_new(s, s), vec2_new(g.width - s, g.height - s), clr);

        break;
    }
    default: // Invalid stage
        assert(0, "Invalid Input!");
        break;
    }
}
#ifndef __RENDER_HANDLER_H__
#define __RENDER_HANDLER_H__

#include "../include.hpp"
#include "renderer.h"

float t = 0.f;
int reverse = 0;
float s = 180.f;

int handle_render(int score, int bestScore) {

    switch (g.stage)
    {
    case stage_main:
    {
        // Background ...
        if (reverse == 1)
            t -= 0.2f;
        else
            t += 0.2f;

        for (int i = 0; i < 40; ++i)
            render_triangle(vec2_add(poses[i], vec2(t, t)), 25.f, color(0.5f, 0.5f, 0.5f), rotate[i]);

        if (t >= 200.f)
            reverse = 1;
        else if (t <= 10.f)
            reverse = 0;

        // Main panel
        color_t clr = color(0.2f, 0.2f, 0.2f);
        render_rect(vec2(s, s + 30), vec2(g.width - s, g.height - s - 20), clr);

        // Main text
        render_text("mayday", vec2(g.width / 3 - 40, (g.height / 6) * 5), 10.f, color(1.f, 1.f, 1.f));

        // Score text
        char buffer[100];
        sprintf(buffer, "best score %d", bestScore);
        render_text(buffer, vec2(20.f, 20.f), 2.f, color(1.f, 1.f, 1.f));

        // Selection
        char text[2][50] = { "Exit", "Play" };
        for (int i = 1; i <= 2; ++i)
        {
            // Selected option
            if (choise == i)
                render_rect(vec2(s + 38, s + 38 + (i * 35)), vec2(s + 362, s + 62 + (i * 35)), color(1.0f, 0.f, 0.f));

            // Render option
            render_rect(vec2(s + 40, s + 40 + (i * 35)), vec2(s + 360, s + 60 + (i * 35)), color(0.5f, 0.5f, 0.5f));
            render_text(text[i - 1], vec2(s + 50, s + 55 + (i * 35)), 2.f, color(1.f, 1.f, 1.f));
        }

        if (score > bestScore)
            bestScore = score;

        break;
    }
    case stage_exit:
    {
        // Close the app
        exit(0);

        break;
    }
    case stage_game:
    {
        // Bullets
        for (int i = 0; i < 100; i++)
        {
            if (bullets[i] == NULL)
                continue;

            render_line(bullets[i]->startPos, bullets[i]->endPos, color(1.f, 0.f, 0.f));
        }

        // Meteorites
        for (int i = 0; i < 10; i++)
        {
            if (meteorites[i] == NULL)
                continue;

            render_meteorite(meteorites[i]->pos, 25.f, color(0.6f, 0.6f, 0.6f));
        }

        // Ship triangle
        render_triangle(ship->pos, 25.f, color(1.f, 1.f, 1.f), ship->rotation);

        // HP background 
        render_rect(vec2(g.width - 205, g.height - 30), vec2(g.width - 15, g.height - 10), color(0.4f, 0.4f, 0.4f));
        int parts = ship->health / 20;

        // HP bars
        for (int i = 0; i < parts; ++i)
            render_rect(vec2(g.width - 52 - (37 * i), g.height - 25), vec2(g.width - 20 - (37 * i), g.height - 15), color(1.f, 0.f, 0.f));

        break;
    }
    case stage_end:
    {
        // Score text
        char buffer[100];
        sprintf(buffer, "SCORE: %d", score);

        render_text("end of the game", vec2(g.width / 3 - 120, (g.height / 6) * 5.5), 5.f, color(1.f, 1.f, 1.f));
        render_text(buffer, vec2(g.width / 3 - 25, (g.height / 6) * 5), 5.f, color(1.f, 1.f, 1.f));

        render_text("press enter to continue", vec2(20.f, 20.f), 2.f, color(1.f, 1.f, 1.f));

        break;
    }
    default: // Invalid stage
        assert(0, "Invalid Input!");
        break;
    }
}

#endif // __RENDER_HANDLER_H__
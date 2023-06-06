#pragma once
#include "../include.hpp"

void handle_movement(entity_t* ent) {
	if (key_active(VK_UP))
		ent->pos = new_pos(ent->pos, ent->rotation, 5.f);
	
	if (key_active(VK_DOWN))
		ent->pos = new_pos(ent->pos, ent->rotation, -5.f);

	if (key_active(VK_RIGHT))
		ent->rotation -= 4.0f;

	if (key_active(VK_LEFT))
		ent->rotation += 4.0f;
}

void handle_action(entity_t* ent) {
	if (key_active(VK_SPACE))
		bullet_new(ent);
}

void handle_selection(int* choise) {
	if (key_pressed(VK_UP))
		*choise += (*choise >= 3) ? 0 : 1;
	else if (key_pressed(VK_DOWN))
		*choise -= (*choise <= 1) ? 0 : 1;

	if (key_pressed(VK_RETURN))
		g.stage = *choise;
}

void handle_input() {

	switch (g.stage)
	{
	case stage_main:
	{
		handle_selection(&choise);

		break;
	}
	case stage_settings:
	{
		if (key_pressed(VK_ESCAPE))
			g.stage = 0;

		break;
	}
	case stage_game:
	{
		if (key_pressed(VK_ESCAPE))
			g.stage = (g.stage == 3) ? 4 : 3;

		handle_action(ship);
		handle_movement(ship);

		break;
	}
	case stage_pause:
	{
		if (key_pressed(VK_ESCAPE))
			g.stage = (g.stage == 3) ? 4 : 3;

		break;
	}
	}
}

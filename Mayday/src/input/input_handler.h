#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include "../include.hpp"

// Handle player movement in game
void handle_movement(entity_t* ent) {
	if (key_active(VK_UP))
		ent->pos = calculate_pos(ent->pos, ent->rotation, 5.f);
	
	if (key_active(VK_DOWN))
		ent->pos = calculate_pos(ent->pos, ent->rotation, -5.f);

	if (key_active(VK_RIGHT))
		ent->rotation -= 4.0f;

	if (key_active(VK_LEFT))
		ent->rotation += 4.0f;

	if (key_pressed(VK_ESCAPE))
		g.stage = 3;

	for (int i = 0; i < 10; i++) {
		if (meteorites[i] == NULL)
			continue;

		int is_in_bounds = in_bounds(ent->pos, meteorites[i]->pos, 25.f);
		if (is_in_bounds)
		{
			ent->health -= 10.f;
			if (ent->health <= 0.f)
				g.stage = 3;
		}
	}
}

// Handle fire event etc.
void handle_action(entity_t* ent) {
	if (key_active(VK_SPACE))
		bullet_new(ent);
}

// Handle main page selection
void handle_selection(int* choise) {
	if (key_pressed(VK_UP))
		*choise += (*choise >= 2) ? 0 : 1;
	else if (key_pressed(VK_DOWN))
		*choise -= (*choise <= 1) ? 0 : 1;

	if (key_pressed(VK_RETURN))
		g.stage = *choise;
}

// Main handle function
void handle_input() {

	switch (g.stage)
	{
	case stage_main:
	{
		handle_selection(&choise);

		break;
	}
	case stage_game:
	{
		handle_action(ship);
		handle_movement(ship);

		break;
	}
	case stage_end:
	{
		if (key_pressed(VK_RETURN))
			g.stage = 0;

		break;
	}
	default: // Invalid stage
		assert(0, "Invalid Input!");
		break;
	}
}

#endif // __INPUT_HANDLER_H__
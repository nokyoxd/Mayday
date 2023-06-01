#pragma once
#include "../sdk/datatypes/types.h"

void handle_input(entity_t* ent) {
	
	if (GetAsyncKeyState(VK_RIGHT) & 0x01)
		ent->pos.x += (ent->pos.x >= 1.f) ? 0.f : 0.05f;

	if (GetAsyncKeyState(VK_LEFT) & 0x01)
		ent->pos.x -= (ent->pos.x <= -1.f) ? 0.f : 0.05f;
}

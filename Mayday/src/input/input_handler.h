#pragma once
#include "../datatypes/types.h"

void handle_movement(entity_t* ent) {
	
	if (GetAsyncKeyState(VK_RIGHT) & 0x01)
		ent->pos.x += (ent->pos.x >= 640.f) ? 0.f : 10.f;

	if (GetAsyncKeyState(VK_LEFT) & 0x01)
		ent->pos.x -= (ent->pos.x <= 0.f) ? 0.f : 10.f;
}

void handle_input(globals_t* globals) {

	if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
		globals->m_iState = (globals->m_iState == 1) ? 0 : 1;
}

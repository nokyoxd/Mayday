#pragma once
#include "../globals.h"

void handle_movement(entity_t* ent) {
	
	if (GetAsyncKeyState(VK_RIGHT) & 0x01)
		ent->pos.x += (ent->pos.x >= 640.f) ? 0.f : 10.f;

	if (GetAsyncKeyState(VK_LEFT) & 0x01)
		ent->pos.x -= (ent->pos.x <= 0.f) ? 0.f : 10.f;
}

void handle_selection(int* choise) {
	if (GetAsyncKeyState(VK_UP) & 0x01)
		*choise += (*choise >= 3) ? 0 : 1;
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
		*choise -= (*choise <= 1) ? 0 : 1;

	if (GetAsyncKeyState(VK_RETURN) & 0x01)
	{
		_G.m_iState = *choise;
	}
}

void handle_input() {

	switch (_G.m_iState)
	{
	case 2:
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
			_G.m_iState = 0;

		break;
	}
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
		_G.m_iState = (_G.m_iState == 3) ? 4 : 3;
}

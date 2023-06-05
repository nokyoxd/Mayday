#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int key_active(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}

int key_pressed(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x01);
}

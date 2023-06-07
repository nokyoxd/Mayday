#ifndef __WRAPPERS_H__
#define __WRAPPERS_H__

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int key_active(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}

int key_pressed(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x01);
}

#endif // __WRAPPERS_H__

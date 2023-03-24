#pragma once
#include "../include.hpp"

static int speed = 30;
void handle_input(int* x, int* y)
{
    if (GetAsyncKeyState(VK_UP) & 0x01)
        *y += speed;

    if (GetAsyncKeyState(VK_DOWN) & 0x01)
        *y -= speed;

    if (GetAsyncKeyState(VK_RIGHT) & 0x01)
        *x += speed;

    if (GetAsyncKeyState(VK_LEFT) & 0x01)
        *x -= speed;
}
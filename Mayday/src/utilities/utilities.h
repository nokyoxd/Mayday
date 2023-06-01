#pragma once
#include <stdlib.h>

#define assert(condition, message) assert_func(condition, message, __FILE__, __LINE__)

float random_float(float min, float max) {
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

void assert_func(int condition, const char* message, const char* file, int line) {
    if (!condition) {
        char popupMessage[256];
        sprintf(popupMessage, "Assertion failed: %s\n\nFile: %s\nLine: %d", message, file, line);
        MessageBoxA(NULL, popupMessage, "Assertion Failed", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
}


#pragma once
#include <stdlib.h>

#define assert(condition, message) assert_func(condition, message, __FILE__, __LINE__)

#define assert_fn(func, expected) \
    do { \
        printf("Calling function: %s\n", #func); \
        int result = func(); \
        if (result != expected) { \
            printf("Error: Assertion failed.\n"); \
            printf("Error-log: Location: %s, line %d (Expected: %d, Returned: %d)\n", __FILE__, __LINE__, expected, result); \
        } \
    } while (0)

void assert_func(int condition, const char* message, const char* file, int line) {
    if (!condition) {
        char popupMessage[256];
        sprintf(popupMessage, "Assertion failed: %s\n\nFile: %s\nLine: %d", message, file, line);
        MessageBoxA(NULL, popupMessage, "Assertion Failed", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
}

float random_float(float min, float max) {
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}


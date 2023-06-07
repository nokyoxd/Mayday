#ifndef __INCLUDE_HPP__
#define __INCLUDE_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include <time.h>

#include "utilities/wrappers.h"
#include "utilities/math.h"
#include "utilities/utilities.h"

#include "datatypes/entity.h"

// Globals
globals_t g = {
    .stage = 0,
    .width = 768,
    .height = 550,
};

GLFWwindow* window = NULL;
entity_t* ship = NULL;

vec2_t poses[40];
float rotate[40];

int choise = 2;

#endif // __INCLUDE_HPP__
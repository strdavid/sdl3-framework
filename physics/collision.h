#pragma once

#include "SDL3/SDL.h"

bool isColliding(SDL_FRect a, SDL_FRect b);

void resolveCollision(SDL_FRect &a, SDL_FRect &b);
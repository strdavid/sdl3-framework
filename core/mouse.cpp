#include "mouse.h"

mouse Mouse = {{0, 0}, 0, 0};

void GetMousePos()
{
    SDL_GetMouseState(&Mouse.pos.x, &Mouse.pos.y);
}
#include "mouse.h"

mouse Mouse = {{0, 0}, 0, 0, false, 0.0f, 0.0f};

void GetMousePos()
{
    SDL_GetMouseState(&Mouse.pos.x, &Mouse.pos.y);
    Mouse.pos = WorldToScreenSpace(Mouse.pos);
}
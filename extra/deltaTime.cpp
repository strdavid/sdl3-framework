#include "deltaTime.h"

double deltaTime;

Uint64 NOW = 0;
Uint64 LAST = 0;


void calculateDeltaTime()
{
    LAST = NOW;
    NOW = SDL_GetTicksNS();
    
    deltaTime = (double)(NOW - LAST) / SDL_NS_PER_SECOND;
}
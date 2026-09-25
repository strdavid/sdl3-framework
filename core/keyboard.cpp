#include "keyboard.h"

const bool* keyboard;  
bool previousKeyboard[SDL_SCANCODE_COUNT] = {};
int timeSinceLastKeypressKeyboard[SDL_SCANCODE_COUNT];

bool isKeyDown(const char* key)
{
    SDL_Scancode scancode = SDL_GetScancodeFromName(key);

    if (scancode == SDL_SCANCODE_UNKNOWN)
        return false;

    if(keyboard[scancode])
    {
        return true;
    } else {
        return false;
    }
}

bool isKeyPressed(const char* key)
{
    SDL_Scancode scancode = SDL_GetScancodeFromName(key);

    if (scancode == SDL_SCANCODE_UNKNOWN)
        return false;

    return keyboard[scancode] &&
           !previousKeyboard[scancode];
}


bool wasKeyPressed(const char* key, int ms)
{
    SDL_Scancode scancode = SDL_GetScancodeFromName(key);

    if (scancode == SDL_SCANCODE_UNKNOWN)
        return false;

    if(timeSinceLastKeypressKeyboard[scancode] <= ms)
    {
        return true;
    }

    return false;
}
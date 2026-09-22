#include "keyboard.h"


bool isKeyDown(const char* key)
{
    const bool* keyboard = SDL_GetKeyboardState(nullptr);  
    SDL_Scancode scancode = SDL_GetScancodeFromName(key);
    if(keyboard[scancode])
    {
        return true;
    } else {
        return false;
    }
}
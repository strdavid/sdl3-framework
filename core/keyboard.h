#include "SDL3/SDL.h"


extern const bool* keyboard; 
extern bool previousKeyboard[SDL_SCANCODE_COUNT];

bool isKeyDown(const char* key);

bool isKeyPressed(const char* key);
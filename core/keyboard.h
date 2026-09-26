#include "SDL3/SDL.h"


extern const bool* keyboard; 
extern bool previousKeyboard[SDL_SCANCODE_COUNT];
extern float timeSinceLastKeypressKeyboard[SDL_SCANCODE_COUNT];

bool isKeyDown(const char* key);

bool isKeyPressed(const char* key);

// was a specific key pressed in the last x milliseconds?
bool wasKeyPressed(const char* key, float ms);
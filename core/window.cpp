#include "window.h"


SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

void CreateWindow(const char* name) {
    window = SDL_CreateWindow(name, 800, 800, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, nullptr);
}
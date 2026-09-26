#pragma once
#include "ui.h"

struct Panel : UIElement {
    const char* name;
    Vec2 pos;
    Vec2 size;
    color Color;
    bool filled = true;

    Panel(const char* name, Vec2 pos, Vec2 size, color Color, bool filled = true)
        : name(name), pos(pos), size(size), Color(Color), filled(filled) {
            addUIElement(name, this);
        }
    
    void draw() {
        SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, 255);
        SDL_FRect rect = {pos.x, pos.y, size.x, size.y};
        if(filled)
        {
            SDL_RenderFillRect(renderer, &rect);
        } else {
            SDL_RenderRect(renderer, &rect);
        }
    }
};
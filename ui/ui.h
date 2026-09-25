#pragma once

#include "../core/draw.h"
#include "../core/misc.h"
#include "../core/color.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <string.h>
#include <unordered_map>
#include <iostream>


struct UIElement {
    const char* name;
    Vec2 pos;
    Vec2 size;

    virtual ~UIElement() = default;
    virtual void draw() = 0;
    virtual void changeText(const char* text) {}; // just for text, dumb fix but whatever
};


extern std::unordered_map<const char*, UIElement*> UIElements;

void drawUI();

UIElement* getUIElement(const char* name);

void addUIElement(const char* name, UIElement* element);
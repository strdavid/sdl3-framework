#pragma once
#include "ui.h"

struct Panel : UIElement {
    const char* name;
    Vec2 pos;
    Vec2 size;
    color Color;

    Panel(const char* name, Vec2 pos, Vec2 size, color Color)
        : name(name), pos(pos), size(size), Color(Color) {
        }
};
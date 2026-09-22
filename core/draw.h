#pragma once

#include "SDL3/SDL.h"
#include "window.h"
#include "misc.h"
#include "color.h"

void drawRect(Vec2 pos, Vec2 size, color color, bool filled=true);

void drawLine(Vec2 start, Vec2 end, color color);

void drawCircle(Vec2 pos, int radius, color color);

void drawPixel(Vec2 pos, color color);
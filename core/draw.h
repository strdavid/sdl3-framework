#pragma once

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "window.h"
#include "misc.h"
#include "color.h"
#include "sprite.h"

void drawRect(Vec2 pos, Vec2 size, color color, bool filled=true);

void drawLine(Vec2 start, Vec2 end, color color);

void drawCircle(Vec2 pos, int radius, color color);

void drawPixel(Vec2 pos, color color);

void drawSprite(Sprite sprite, Vec2 pos, Vec2 size);
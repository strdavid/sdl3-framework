#pragma once

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include <vector>
#include <unordered_map>
#include "window.h"
#include "misc.h"
#include "color.h"
#include "sprite.h"
#include "../extra/camera.h"

void drawRect(Vec2 pos, Vec2 size, color color, bool filled=true);

void drawLine(Vec2 start, Vec2 end, color color);

void drawCircle(Vec2 pos, int radius, color color);

void drawPixel(Vec2 pos, color color);

void drawSprite(Sprite sprite, Vec2 pos, Vec2 size);

void drawSpriteTiled(Sprite sprite, Vec2 pos, Vec2 size, float scale=1.0f);
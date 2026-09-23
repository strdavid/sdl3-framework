#pragma once

#include "SDL3/SDL.h"

#include "../core/misc.h"

struct Camera {
    Vec2 pos;
    Vec2 size;
};

extern Camera UsedCamera;

extern Camera DefaultCamera;

void EnableCamera(Camera camera);

Vec2 WorldToScreenSpace(Vec2 pos);

Vec2 Center(Vec2 pos);

Vec2 ScreenToWorldSpace(Vec2 pos);
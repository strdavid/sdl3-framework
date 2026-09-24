#pragma once

#include <vector>
#include "SDL3/SDL.h"
#include "../core/misc.h"
#include "../core/sprite.h"
#include "../core/draw.h"
#include "../physics/collision.h"
#include "../extra/deltaTime.h"

struct Object;

extern std::vector<Object*> objectsWithColliders;


struct Object {
private:
    SDL_FRect rect;
public:
    Vec2 pos;
    Vec2 size;
    Sprite sprite;
    bool isPixelArt;
    Vec2 velocity;
    bool tiled=false;
    float scale=1.0f;
    int flip=0;

    Object(Vec2 pos, Vec2 size, Sprite sprite="", bool isPixelArt=false, bool tiled=false, float scale=1.0f)
        : pos(pos), size(size), sprite(sprite), isPixelArt(isPixelArt), tiled(tiled), scale(scale)
    {
        rect = {pos.x, pos.y, size.x, size.y};
    }

    SDL_FRect* getRect();

    void draw();

    void update();

    void flipSprite(int flip);

    bool isOnGround();
};


void AddCollider(Object &obj);
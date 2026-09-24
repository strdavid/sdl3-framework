#pragma once

#include "SDL3/SDL.h"
#include "../core/sprite.h"
#include "../extra/deltaTime.h"
#include "../object/object.h"
#include <vector>
#include <unordered_map>

extern std::unordered_map<const char*, int> animationNames;

struct Spritesheet {
    std::vector<Sprite> sprites;
    float frameTime;
};

struct SpritesheetAnimation {
    Object *object;
    Spritesheet spritesheet;
    float timeSinceLastFrameChange;
    int frame;
    bool playing=false;
};

extern std::vector<SpritesheetAnimation> SpritesheetAnimations;

void animateObjectWithSpritesheet(Object &object, Spritesheet spritesheet, const char* animationName);

void continueAnimations();

void playSpritesheetAnimation(const char* animationName);
void pauseSpritesheetAnimation(const char* animationName);


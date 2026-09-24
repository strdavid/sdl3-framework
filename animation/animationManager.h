#pragma once

#include "spritesheet.h"

class animationManager {
public:
    void playAnimation(const char* animationName);
};

extern animationManager AnimationManager;
#pragma once

#include "../extra/deltaTime.h"
#include <vector>
#include <algorithm>

#define Linear 0
#define EaseIn 1
#define EaseOut 2
#define EaseInOut 3
#define Smooth 3

struct Animation {
    float *value;
    float startValue;
    float targetValue;
    float animationTime;
    float elapsedTime;
    int type;
};

extern std::vector<Animation> animations;

float lerp(float a, float b, float t);

float easeIn(float a, float b, float t);

float easeOut(float a, float b, float t);

float easeInOut(float a, float b, float t);

void animateValue(float *value, float targetValue, float animationTime, int animationType);

void continueAnimations();
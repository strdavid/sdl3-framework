
#include "animation.h"

std::vector<Animation> animations;

float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

float easeIn(float a, float b, float t) {
    t = t * t;
    return a + (b - a) * t;
}

float easeOut(float a, float b, float t) {
    t = 1.0f - (1.0f - t) * (1.0f - t);
    return a + (b - a) * t;
}

float easeInOut(float a, float b, float t) {
    t = t * t * (3.0f - 2.0f * t);
    return a + (b - a) * t;
}

void animateValue(float *value, float targetValue, float animationTime, int animationType)
{
    Animation animation = {value, *value, targetValue, animationTime, 0.0f, animationType};
    animations.push_back(animation);
}

void continueAnimations()
{
    for(Animation &animation : animations)
    {
        animation.elapsedTime += deltaTime;

        float t = animation.elapsedTime / animation.animationTime;
        t = std::clamp(t, 0.0f, 1.0f);

        if(animation.type == 0)
        {
            *animation.value = lerp(
                animation.startValue,
                animation.targetValue,
                t
            );
        } else if(animation.type == 1)
        {
            *animation.value = easeIn(
                animation.startValue,
                animation.targetValue,
                t
            );
        } else if(animation.type == 2)
        {
            *animation.value = easeOut(
                animation.startValue,
                animation.targetValue,
                t
            );
        } else if(animation.type == 3)
        {
            *animation.value = easeInOut(
                animation.startValue,
                animation.targetValue,
                t
            );            
        }

    }
}
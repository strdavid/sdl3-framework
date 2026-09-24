#include "animationManager.h"

animationManager AnimationManager;

void animationManager::playAnimation(const char* animationName)
{
    for(int i = 0; i < SpritesheetAnimations.size(); i++)
    {
        if(animationNames[animationName] == i)
        {
            SpritesheetAnimations[i].playing = true;
            continue;
        } else {
            SpritesheetAnimations[i].playing = false;
        }
        
    }
}
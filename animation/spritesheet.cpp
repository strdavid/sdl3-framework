#include "spritesheet.h"

std::unordered_map<const char*, int> animationNames;
std::vector<SpritesheetAnimation> SpritesheetAnimations;

void animateObjectWithSpritesheet(Object &object, Spritesheet spritesheet, const char* name)
{
    SpritesheetAnimation animation = {&object, spritesheet, 0.0f, 0, false};
    SpritesheetAnimations.push_back(animation);
    animationNames[name] = SpritesheetAnimations.size()-1;
}

void continueAnimations()
{
    for(SpritesheetAnimation &animation : SpritesheetAnimations)
    {
        if(!animation.playing)
        {
            continue;
        }

        animation.timeSinceLastFrameChange += (deltaTime*1000);
        if(animation.timeSinceLastFrameChange > animation.spritesheet.frameTime)
        {
            animation.timeSinceLastFrameChange = 0.0f;
            animation.frame++;
            if(animation.frame >= animation.spritesheet.sprites.size())
            {
                animation.frame = 0;
            }
            animation.object->sprite = animation.spritesheet.sprites[animation.frame];
        }
    }
}


void playSpritesheetAnimation(const char* animationName)
{
    SpritesheetAnimations[animationNames[animationName]].playing = true;
}

void pauseSpritesheetAnimation(const char* animationName)
{
    SpritesheetAnimations[animationNames[animationName]].playing = false;
}
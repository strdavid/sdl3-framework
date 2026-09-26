#include "sceneManager.h"

void (*loopFunction)() = nullptr;

void sceneManager::changeScene(void (*start)(), void (*loop)())
{
    UIElements.clear();
    objectsWithColliders.clear();
    animations.clear();
    SpritesheetAnimations.clear();
    animationNames.clear();
    start();
    loopFunction = loop;

}

sceneManager SceneManager;
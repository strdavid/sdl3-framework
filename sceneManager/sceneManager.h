#pragma once

#include "../ui/ui.h"
#include "../object/object.h"
#include "../animation/animation.h"
#include "../animation/spritesheet.h"

extern void (*loopFunction)();

class sceneManager {
public:
    void changeScene(void (*start)(), void (*loop)());
};

extern sceneManager SceneManager;
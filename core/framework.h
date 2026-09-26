#pragma once

#include "SDL3/SDL.h"
#include "window.h"
#include "draw.h"
#include "mouse.h"
#include "keyboard.h"
#include "../extra/deltaTime.h"
#include "../physics/collision.h"
#include "../extra/debug.h"
#include "../object/object.h"
#include "../animation/spritesheet.h"
#include "../animation/animationManager.h"
#include "../animation/animation.h"
#include "../animation/runAfter.h"
#include "../ui/ui.h"
#include "../ui/text.h"
#include "../ui/panel.h"
#include <algorithm>
#include <string>


void start();
void loop();
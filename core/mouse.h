#include "misc.h"
#include "SDL3/SDL.h"


struct mouse {
    Vec2 pos;
    bool isLeftClicking;
    bool isRightClicking;
};

extern mouse Mouse;


void GetMousePos();
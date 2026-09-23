#include "misc.h"
#include "SDL3/SDL.h"


struct mouse {
    Vec2 pos;
    bool isLeftClicking;
    bool isRightClicking;
    bool isScrolling;
    float scroll;
    float totalScroll;
};

extern mouse Mouse;


void GetMousePos();
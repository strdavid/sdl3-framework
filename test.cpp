#include "core/framework.h"
#include <iostream>

void start()
{
    CreateWindow("hello world");
    EnableCamera(DefaultCamera);
}

void loop()
{
    UsedCamera.pos = Center({200, 300});

    drawLine({25, 25}, {125, 125}, WHITE);
    drawRect({25, 25}, {25, 25}, RED);
    drawRect({125, 125}, {25, 25}, GREEN, false);
    drawCircle({400, 400}, 25, BLUE);

    drawPixel(Mouse.pos, GREEN);

    if(isKeyDown("space"))
    {
        drawCircle({300, 300}, 5, RED);
    }

    if(Mouse.isLeftClicking)
    {
        drawCircle(Mouse.pos, 10, RED);
    }

    if(Mouse.isRightClicking)
    {
        drawCircle(Mouse.pos, 10, BLUE);
    }

    if(isColliding({25, 25, 25, 25}, {Mouse.pos.x, Mouse.pos.y, 1, 1}))
    {
        debug("collidin'");
    }
    

    drawCircle({50, Mouse.totalScroll}, 10, RED);

    drawSprite("silly_lil_drawing.png", {600, 600}, {200, 200});
    drawSpriteTiled("silly_lil_drawing.png", {300, 600}, {200, 200}, 0.08);
}
#include "core/framework.h"
#include <iostream>

void start()
{
    CreateWindow("hello world");
}

void loop()
{
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

    drawSprite("silly_lil_drawing.png", {600, 600}, {200, 200});
}
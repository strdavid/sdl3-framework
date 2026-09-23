#include "core/framework.h"

void start()
{
    CreateWindow("hello world");
    EnableCamera(DefaultCamera);
}

void loop()
{
    UsedCamera.pos.x += 1;

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

    

    drawCircle({50, Mouse.totalScroll}, 10, RED);

    drawSprite("silly_lil_drawing.png", {600, 600}, {200, 200});
    drawSpriteTiled("silly_lil_drawing.png", {300, 600}, {200, 200}, 0.08);
}
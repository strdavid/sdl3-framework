#include "core/framework.h"


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
}
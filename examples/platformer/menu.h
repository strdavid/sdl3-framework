#pragma once
#include "../../core/framework.h"
#include "game.h"

void menuStart() {
    static Text menuText = {"menuText", {0, 200-54/2}, {800, 54}, "Platformer Example", WHITE, "examples/platformer/fonts/pixelArtFont.ttf", 54, TextCenter, 2, BLACK};
    static Text subtitleText = {"subtitleText", {0, 400-32/2}, {800, 32}, "Left Click to play the game!", WHITE, "examples/platformer/fonts/pixelArtFont.ttf", 32, TextCenter, 2, BLACK};
    static Panel bg = {"bg", {0, 0}, {800, 800}, {194, 227, 232}};
}

void menuLoop()
{
    if(Mouse.isLeftClicking)
    {
        SceneManager.changeScene(gameStart, gameLoop);
    }
}
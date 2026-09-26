#include "game.h"
#include "menu.h"

void start()
{
    CreateWindow("Platformer Example");
    SceneManager.changeScene(menuStart, menuLoop);
}

void loop()
{
    // Scene Manager will change the loop func to menuLoop after start() is executed
}
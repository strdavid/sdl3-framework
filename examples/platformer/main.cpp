#include "../core/framework.h"

Object player = {{400, 400}, {0, 0}, {35, 35}, "examples/platformer/character.png"};
Object ground1 = {{0, 750}, {0, 0}, {800, 50}, "examples/platformer/ground.png", true, 3};
Object ground2 = {{900, 750}, {0, 0}, {800, 50}, "examples/platformer/ground.png", true, 3};
Object ground3 = {{-900, 750}, {0, 0}, {800, 50}, "examples/platformer/ground.png", true, 3};
float speed = 255;
float jumpStrength = 400;

void start()
{
    AddCollider(player);
    AddCollider(ground1);
    AddCollider(ground2);
    AddCollider(ground3);

    CreateWindow("Platformer Example");
    EnableCamera(DefaultCamera);
}

void loop()
{
    UsedCamera.pos = Center(player.pos);

    if(!player.isOnGround())
    {
        player.velocity.y += 600 * deltaTime;
    } else {
        if(player.velocity.y > 0)
        {
            player.velocity.y = 0;
        }
    }

    if(isKeyDown("a"))
    {
        player.velocity.x = -speed;
    } else if(isKeyDown("d"))
    {
        player.velocity.x = speed;
    } else {
        player.velocity.x = 0;
    }

    if(isKeyPressed("space") && player.isOnGround())
    {
        player.velocity.y -= jumpStrength;
    }



    player.draw();
    player.update();

    ground1.draw();
    ground2.draw();
    ground3.draw();
}
#include "../core/framework.h"

Object player = {
    {400, 400}, // position
    {48, 48}, // size
    "examples/platformer/character.png", //sprite path
    true // is pixel art (should scale mode be set to nearest)
};

Object ground1 = {
    {0, 750},
    {800, 18*2},
    "examples/platformer/ground.png",
    true,
    true,
    2.0f
};

Object ground2 = {
    {900, 750},
    {800, 35},
    "examples/platformer/ground.png",
    true,
    true,
    2.0f
};

Object ground3 = {
    {-900, 750},
    {800, 35},
    "examples/platformer/ground.png",
    true,
    true,
    2.0f
};

Spritesheet playerSpritesheet = {
    {"examples/platformer/character.png", 
    "examples/platformer/character2.png"},
    100
};

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

    animateObjectWithSpritesheet(player, playerSpritesheet, "player_walk");
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
        player.flipSprite(LEFT);
        playSpritesheetAnimation("player_walk");
    } else if(isKeyDown("d"))
    {
        player.velocity.x = speed;
        player.flipSprite(RIGHT);
        playSpritesheetAnimation("player_walk");
    } else {
        player.velocity.x = 0;
        pauseSpritesheetAnimation("player_walk");
    }

    if(wasKeyPressed("space", 10) && player.isOnGround())
    {
        player.velocity.y -= jumpStrength;
    }



    player.draw();
    player.update();

    ground1.draw();
    ground2.draw();
    ground3.draw();
}
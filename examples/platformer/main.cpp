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

Spritesheet playerWalkSpritesheet = {
    {"examples/platformer/character2.png", 
    "examples/platformer/character.png"},
    100
};

Spritesheet playerJumpSpritesheet = {
    {"examples/platformer/character.png"},
    100
};

Spritesheet playerIdleSpritesheet = {
    {"examples/platformer/character2.png"},
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

    animateObjectWithSpritesheet(player, playerWalkSpritesheet, "player_walk");
    animateObjectWithSpritesheet(player, playerJumpSpritesheet, "player_jump");
    animateObjectWithSpritesheet(player, playerIdleSpritesheet, "player_idle");
}

void loop()
{
    // Center camera on player
    UsedCamera.pos = Center(player.pos);

    // Movement
    if(isKeyDown("a"))
    {
        player.velocity.x = -speed;
        player.flipSprite(LEFT);

        AnimationManager.playAnimation("player_walk");
    } else if(isKeyDown("d"))
    {
        player.velocity.x = speed;
        player.flipSprite(RIGHT);

        AnimationManager.playAnimation("player_walk");
    } else {
        player.velocity.x = 0;
        AnimationManager.playAnimation("player_idle");
    }

    // Jump
    if(wasKeyPressed("space", 10) && player.isOnGround())
    {
        player.velocity.y -= jumpStrength;
    }

    // Gravity
    if(!player.isOnGround())
    {
        player.velocity.y += 600 * deltaTime;

    } else {
        if(player.velocity.y > 0)
        {
            player.velocity.y = 0;
        }
    }

    // Fall animation
    if(player.velocity.y != 0)
    {
        AnimationManager.playAnimation("player_jump");
    } else {
        pauseSpritesheetAnimation("player_jump");
    }

    // Draw player
    player.draw();
    player.update();

    // Draw ground
    ground1.draw();
    ground2.draw();
    ground3.draw();
}
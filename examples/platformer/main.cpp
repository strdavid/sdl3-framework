#include "../core/framework.h"

Object player = {
    {400, 702}, // position
    {48, 48}, // size
    "examples/platformer/images/character.png", //sprite path
    true // is pixel art (should scale mode be set to nearest)
};

// ground platforms
Object ground1 = {
    {200, 750},
    {400, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground2 = {
    {350, 600},
    {300, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground3 = {
    {150, 450},
    {200, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground4 = {
    {300, 300},
    {250, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground5 = {
    {100, 150},
    {200, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground6 = {
    {350, 0},
    {300, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground7 = {
    {150, -150},
    {250, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground8 = {
    {400, -280},
    {200, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground9 = {
    {200, -440},
    {300, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};

Object ground10 = {
    {350, -580},
    {250, 18*2},
    "examples/platformer/images/ground.png",
    true,
    true,
    2.0f
};


Spritesheet playerWalkSpritesheet = {
    {"examples/platformer/images/character2.png", 
    "examples/platformer/images/character.png"},
    100
};

Spritesheet playerJumpSpritesheet = {
    {"examples/platformer/images/character.png"},
    100
};

Spritesheet playerIdleSpritesheet = {
    {"examples/platformer/images/character2.png"},
    100
};


float speed = 255;
float jumpStrength = 450;


void start()
{
    AddCollider(player);
    AddCollider(ground1);
    AddCollider(ground2);
    AddCollider(ground3);
    AddCollider(ground4);
    AddCollider(ground5);
    AddCollider(ground6);
    AddCollider(ground7);
    AddCollider(ground8);
    AddCollider(ground9);
    AddCollider(ground10);


    CreateWindow("Platformer Example");
    EnableCamera(DefaultCamera);

    animateObjectWithSpritesheet(player, playerWalkSpritesheet, "player_walk");
    animateObjectWithSpritesheet(player, playerJumpSpritesheet, "player_jump");
    animateObjectWithSpritesheet(player, playerIdleSpritesheet, "player_idle");

    static Text scoreText = {"score", {0, 15}, {800, 32}, "0", WHITE, "examples/platformer/fonts/pixelArtFont.ttf", 32, TextCenter, 2, BLACK};
}


void loop()
{
    // Show score
    int score = (-player.pos.y+750-48)/10;
    getUIElement("score")->changeText(std::to_string(score).c_str());

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


    // Draw bg
    drawSprite("examples/platformer/images/sky.png", {-3000, -3000}, {6000, 6000});

    // Draw player
    player.draw();
    player.update();

    // Draw ground
    ground1.draw();
    ground2.draw();
    ground3.draw();
    ground4.draw();
    ground5.draw();
    ground6.draw();
    ground7.draw();
    ground8.draw();
    ground9.draw();
    ground10.draw();

}
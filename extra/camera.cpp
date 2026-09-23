#include "camera.h"

Camera UsedCamera = {{0, 0}, {0, 0}};
Camera DefaultCamera = {{0, 0}, {800, 800}};

void EnableCamera(Camera camera)
{
    UsedCamera = camera;
}

Vec2 WorldToScreenSpace(Vec2 pos)
{
    return {pos.x + UsedCamera.pos.x, pos.y + UsedCamera.pos.y};
}

Vec2 ScreenToWorldSpace(Vec2 pos)
{
    return {pos.x - UsedCamera.pos.x, pos.y - UsedCamera.pos.y};
}

Vec2 Center(Vec2 pos)
{
    return {pos.x - UsedCamera.size.x / 2, pos.y - UsedCamera.size.y / 2};
}
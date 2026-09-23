#include "collision.h"

bool isColliding(SDL_FRect a, SDL_FRect b)
{
    return !((a.x + a.w < b.x) ||
             (a.x > b.w + b.x) ||
             (a.y > b.h + b.y) ||
             (a.y + a.h < b.y));
}

void resolveCollision(SDL_FRect &a, SDL_FRect &b)
{
    if (!isColliding(a, b))
    {
        return;
    }

    float overlapLeft = (a.x + a.w) - b.x;
    float overlapRight = (b.x + b.w) - a.x;
    float overlapTop = (a.y + a.h) - b.y;
    float overlapBottom = (b.y + b.h) - a.y;

    float minOverlapX = (overlapLeft < overlapRight ? -overlapLeft : overlapRight);
    float minOverlapY = (overlapTop < overlapBottom ? -overlapTop : overlapBottom);

    if (abs(minOverlapX) < abs(minOverlapY))
    {
        a.x += minOverlapX;
    }
    else
    {
        a.y += minOverlapY;
    }
}
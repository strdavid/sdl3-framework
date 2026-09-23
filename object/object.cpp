#include "object.h"


std::vector<Object*> objectsWithColliders;

SDL_FRect* Object::getRect()
    {
        return &rect;
    }

void Object::draw()
    {
        if(!tiled)
        {
            drawSprite(sprite, pos, size);
        } else {
            drawSpriteTiled(sprite, pos, size, scale);
        }
    }

void Object::update()
    {
        pos.x += velocity.x * deltaTime;
        pos.y += velocity.y * deltaTime;
        rect = {pos.x, pos.y, size.x, size.y};

        for(Object* other : objectsWithColliders)
        {
            if(other->pos.x == pos.x && other->pos.y == pos.y)
            {
                continue;
            }

            resolveCollision(rect, *other->getRect());
            pos.x = rect.x;
            pos.y = rect.y;
        }
    }

bool Object::isOnGround()
    {
        rect = {pos.x, pos.y, size.x, size.y};
        float rectPosYStat = rect.y;

        for(Object* other : objectsWithColliders)
        {
            if(other->pos.x == pos.x && other->pos.y == pos.y)
            {
                continue;
            }

            if(isColliding(rect, *other->getRect()))
            {
                return true;
            }
        }

        return false;
    }

void AddCollider(Object &obj)
{
    objectsWithColliders.push_back(&obj);
}
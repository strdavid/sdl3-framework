#include "draw.h"


void drawRect(Vec2 pos, Vec2 size, color color, bool filled)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_FRect rect = {pos.x - UsedCamera.pos.x, pos.y - UsedCamera.pos.y, size.x, size.y};
    if(filled)
    {
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_RenderRect(renderer, &rect);
    }
}

void drawLine(Vec2 start, Vec2 end, color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderLine(renderer, start.x - UsedCamera.pos.x, start.y - UsedCamera.pos.y, end.x - UsedCamera.pos.x, end.y - UsedCamera.pos.y);
}


void drawCircle(Vec2 pos, int radius, color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    for (int w = -radius; w <= radius; w++)
    {
        for (int h = -radius; h <= radius; h++)
        {
            if (w * w + h * h <= radius * radius)
            {
                SDL_RenderPoint(renderer, pos.x - UsedCamera.pos.x + w, pos.y - UsedCamera.pos.y + h);
            }
        }
    }
}

void drawPixel(Vec2 pos, color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderPoint(renderer, pos.x - UsedCamera.pos.x, pos.y - UsedCamera.pos.y);
}

std::unordered_map<Sprite, SDL_Texture *> loadedTextures;

void drawSprite(Sprite sprite, Vec2 pos, Vec2 size) {
    SDL_Texture *texture;
    if(loadedTextures.find(sprite) != loadedTextures.end())
    {
        texture = loadedTextures[sprite];
    } else {
        SDL_Texture *texture = IMG_LoadTexture(renderer, sprite);
        loadedTextures[sprite] = texture;
    }
    
    SDL_FRect rect = {pos.x - UsedCamera.pos.x, pos.y - UsedCamera.pos.y, size.x, size.y};

    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}


void drawSpriteTiled(Sprite sprite, Vec2 pos, Vec2 size, float scale) {
    SDL_Texture *texture;
    if(loadedTextures.find(sprite) != loadedTextures.end())
    {
        texture = loadedTextures[sprite];
    } else {
        SDL_Texture *texture = IMG_LoadTexture(renderer, sprite);
        loadedTextures[sprite] = texture;
    }

    
    SDL_FRect rect = {pos.x - UsedCamera.pos.x, pos.y - UsedCamera.pos.y, size.x, size.y};

    SDL_RenderTextureTiled(renderer, texture, nullptr, scale, &rect);
}
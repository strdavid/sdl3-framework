#include "draw.h"


void drawRect(Vec2 pos, Vec2 size, color color, bool filled)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_FRect rect = {pos.x, pos.y, size.x, size.y};
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
    SDL_RenderLine(renderer, start.x, start.y, end.x, end.y);
}


void drawCircle(Vec2 pos, int radius, color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    for (int w = -radius; w <= radius; w++)
    {
        for (int h = -radius; h <= radius; h++)
        {
            if (w * w + h * h <= radius * radius)
            {
                SDL_RenderPoint(renderer, pos.x + w, pos.y + h);
            }
        }
    }
}

void drawPixel(Vec2 pos, color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderPoint(renderer, pos.x, pos.y);
}
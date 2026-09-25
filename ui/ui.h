#pragma once

#include "../core/draw.h"
#include "../core/misc.h"
#include "../core/color.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <string.h>
#include <unordered_map>
#include <iostream>

#define TextLeft 0
#define TextCenter 1
#define TextRight 2

extern std::unordered_map<const char*, TTF_Font*> loadedFonts;

struct Text;

extern std::vector<Text> textElements;

void AddTextElementToUI(Text &text);

struct Text {
    Vec2 pos;
    Vec2 size;
    const char* text;
    color Color;
    const char* fontPath; // font path
    float fontSize = 16;
    int textAlign = TextCenter;
    bool visible = true;
    SDL_Texture* textTexture;
    SDL_FRect rect;


    Text(Vec2 pos, Vec2 size, const char* text, color Color, const char* fontPath, float fontSize = 16, int textAlign = TextCenter, bool visible = true)
        : pos(pos), size(size), text(text), Color(Color), fontPath(fontPath), fontSize(fontSize), textAlign(textAlign), visible(visible) {
            TTF_Font* font = TTF_OpenFont(fontPath, fontSize);
            SDL_Color textColor = {Color.r, Color.g, Color.b, 255};
            SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, strlen(text), textColor);
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); 
            if(!textTexture)
            {
                std::cout << "fuck";
            }
            float textW = (float)textSurface->w;
            float textH = (float)textSurface->h;
            SDL_DestroySurface(textSurface);
            rect = {pos.x, pos.y, textW, textH};
            if(textAlign == TextLeft)
            {
                rect.x = rect.x;
            } else if(textAlign == TextCenter)
            {
                rect.x = pos.x+(size.x-textW)/2;
            } else if(textAlign == TextRight)
            {
                rect.x = pos.x+(size.x-textW);
            }

            AddTextElementToUI(*this);
        }
    
    void draw();
};

void drawUI();

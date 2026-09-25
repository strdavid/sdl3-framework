#pragma once

#include "ui.h"


#define TextLeft 0
#define TextCenter 1
#define TextRight 2

extern std::unordered_map<const char*, TTF_Font*> loadedFonts;

struct Text;

void AddTextElementToUI(Text *text);

extern std::vector<Text*> textElements;

struct Text : UIElement {
    const char* name;
    Vec2 pos;
    Vec2 size;
    const char* text;
    color Color;
    const char* fontPath; // font path
    float fontSize = 16;
    int textAlign = TextCenter;
    int outlineWidth = 0;
    color outlineColor = BLACK;
    bool visible = true;
    SDL_Texture* textTexture;
    SDL_Texture* outlineTexture;
    SDL_FRect rect;
    SDL_FRect outlineRect;
    TTF_Font* font;

    Text(const char* name, Vec2 pos, Vec2 size, const char* text, color Color, const char* fontPath, float fontSize = 16, int textAlign = TextCenter, int outlineWidth = 0, color outlineColor = BLACK, bool visible = true)
        : name(name), pos(pos), size(size), text(text), Color(Color), fontPath(fontPath), fontSize(fontSize), textAlign(textAlign), 
        outlineWidth(outlineWidth), outlineColor(outlineColor), visible(visible) {
            font = TTF_OpenFont(fontPath, fontSize);
            if(outlineWidth != 0)
            {
                TTF_SetFontOutline(font, outlineWidth);
                SDL_Color outlineSDLColor = {outlineColor.r, outlineColor.g, outlineColor.b, 255};
                SDL_Surface* outline = TTF_RenderText_Blended(font, text, strlen(text), outlineSDLColor);
                outlineTexture = SDL_CreateTextureFromSurface(renderer, outline); 
                float textW = (float)outline->w;
                float textH = (float)outline->h;
                SDL_DestroySurface(outline);
                outlineRect = {pos.x, pos.y-outlineWidth/2-1, textW, textH};
                if(textAlign == TextLeft)
                {
                    outlineRect.x = rect.x;
                } else if(textAlign == TextCenter)
                {
                    outlineRect.x = pos.x+(size.x-textW)/2;
                } else if(textAlign == TextRight)
                {
                    outlineRect.x = pos.x+(size.x-textW);
                }
                TTF_SetFontOutline(font, 0);
            }
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

            addUIElement(name, this);
            AddTextElementToUI(this);
        }
    
    void changeText(const char* newText) override;

    void draw() override;
};


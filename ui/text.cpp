#include "text.h"

std::unordered_map<const char*, TTF_Font*> loadedFonts;
std::vector<Text*> textElements;


void AddTextElementToUI(Text *text) {
    textElements.push_back(text);
}


void Text::draw()
{
    if(visible)
    {
        if(outlineTexture)
        {
            SDL_RenderTexture(renderer, outlineTexture, NULL, &outlineRect);
        }
        SDL_RenderTexture(renderer, textTexture, NULL, &rect);
    }
}

void Text::changeText(const char* newText)
{
    SDL_DestroyTexture(textTexture);
    text = newText;
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

    if(outlineTexture)
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
}
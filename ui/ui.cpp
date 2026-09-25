#include "ui.h"
#include "../extra/debug.h"

std::unordered_map<const char*, TTF_Font*> loadedFonts;
std::vector<Text> textElements;


void AddTextElementToUI(Text &text) {
    textElements.push_back(text);
}


void drawUI() {
    for(Text &text: textElements)
    {
        text.draw();
    }
}

// TEXT
void Text::draw()
{
    if(visible)
    {
        SDL_RenderTexture(renderer, textTexture, NULL, &rect);
    }
}
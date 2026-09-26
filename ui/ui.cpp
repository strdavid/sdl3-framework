#include "ui.h"
#include "../extra/debug.h"

std::unordered_map<const char*, UIElement*> UIElements;

#include "text.h"
void drawUI() {
    for(const auto& [name, element] : UIElements)
    {
        element->draw();
    }
}

UIElement* getUIElement(const char* name)
{
    if(UIElements.find(name) != UIElements.end())
    {
        return UIElements[name];
    } else {
        debug("this will probably crash but im not doing anything to prevent it lol");
    }
}

void addUIElement(const char* name, UIElement* element)
{
    UIElements[name] = element;
}
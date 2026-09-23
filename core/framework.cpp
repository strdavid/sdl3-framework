#include "framework.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    bool run = true;
    SDL_Event event;

    NOW = SDL_GetTicksNS();

    start();

    while(run)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                run = false;
            }
            if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    Mouse.isLeftClicking = true;
                } else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    Mouse.isRightClicking = true;
                }  
            } else if(event.type == SDL_EVENT_MOUSE_BUTTON_UP)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    Mouse.isLeftClicking = false;
                } else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    Mouse.isRightClicking = false;
                }  
            } else if(event.type == SDL_EVENT_MOUSE_WHEEL )
            {
                Mouse.scroll = event.wheel.y;
                Mouse.totalScroll -= Mouse.scroll;
            }
        }
        calculateDeltaTime();
        GetMousePos();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        loop();

        SDL_RenderPresent(renderer);
    }

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
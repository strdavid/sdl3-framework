#include "framework.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    bool run = true;
    SDL_Event event;

    start();

    while(run)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                run = false;
            }
        }
        SDL_RenderClear(renderer);

        loop();

        SDL_RenderPresent(renderer);
    }

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
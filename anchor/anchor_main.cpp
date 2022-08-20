#include <iostream>
#include <SDL.h>

//screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main( int argc, char* args[])
{
    //the window we are rendering to
    SDL_Window* window = NULL;

    //the surface contained by the window
    SDL_Serface* screenSurface = NULL;

    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: ", SDL_GetError();
    }
    else
    {
        //create window
        window = SDL_CreateWindow("Anchor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: ", SDL_GetError();
        }
        else
        {
            //get window surface
            screenSurface = SDL_GetWindowSurface(window);
            //fill the surface
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 
                                                         0xFF, 0xFF, 0xFF));
            //update the surface
            SDL_UpdateWindowSurface(window);

            //wait two seconds
            SDL_Delay(2000);
        }
    }
    //destroy window
    SDL_DestroyWindow(window);

    //quit sdl subsystems
    SDL_Quit();
    return 0;
}
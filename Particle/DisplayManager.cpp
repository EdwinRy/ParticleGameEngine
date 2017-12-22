#include "DisplayManager.h"
#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>

using namespace Display;
//using namespace std;

SDL_Window* window;

DisplayManager::DisplayManager()
{

}

void DisplayManager::CreateDisplay(int width, int height, char* title)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width,height, SDL_WINDOW_SHOWN);
}

void DisplayManager::DeleteDisplay()
{

}
#include "DisplayManager.h"
#include "../ParticleRenderer/Renderer.h"
#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>
#include <SDL2/SDL_vulkan.h>
#include <iostream>

using namespace Display;
//using namespace RenderingEngine;

SDL_Window* window;

DisplayManager::DisplayManager()
{

}

void DisplayManager::createDisplay(
    int width, int height, char* title, RenderingEngine::Renderer renderer)
{
    std::cout << "Setting up SDL" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);

    //Setup the window to use the Vulkan API
    if(renderer.getRenderingAPI == VULKAN)
    {
        window = SDL_CreateWindow(
            title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width,height, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);


        //Information about this application
        const VkApplicationInfo appinfo
        {
            VK_STRUCTURE_TYPE_APPLICATION_INFO, //stype
            nullptr,    //pnext
            title,  //app name
            VK_MAKE_VERSION(1,0,0),    //app version
            "ParticleGameEngine",   //engine name
            VK_MAKE_VERSION(1,0,0),    //engine version
            VK_API_VERSION_1_0,    //api version

        };

        uint32_t extensionCount;       
        SDL_Vulkan_GetInstanceExtensions(window,&extensionCount,nullptr);

        //Information about the Vulkan instance
        VkInstanceCreateInfo instanceInfo;
        instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceInfo.pApplicationInfo = &appinfo;
       
    }

    //Setup the window to use the OpenGL API
    else if(renderer.getRenderingAPI == OPENGL)
    {
        window = SDL_CreateWindow(
            title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width,height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    }

    
    
}

void DisplayManager::deleteDisplay()
{

}
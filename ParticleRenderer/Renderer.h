#pragma once
namespace RenderingEngine
{
    typedef enum RenderingAPI
    {
        OPENGL,
        VULKAN,
        SOFTWARE
    }RenderingAPI;

    class Renderer
    {
        private:
        RenderingAPI api;
        public:    
        Renderer(RenderingAPI api);

        RenderingAPI getRenderingAPI();
    };
}
#pragma once
#include <stdlib.h>
#include <string>
#include "../ParticleRenderer/Renderer.h"

namespace Display{
    class DisplayManager
    {
        public:
        DisplayManager();
        ~DisplayManager();

        void createDisplay(
            int width, int height, char* title, RenderingEngine::Renderer renderer);
        void deleteDisplay();

    };
}
#include "Renderer.h"

using namespace RenderingEngine;

Renderer::Renderer(RenderingAPI api)
{
    this->api = api;
}

RenderingAPI Renderer::getRenderingAPI()
{
    return this->api;
}
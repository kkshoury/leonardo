#include "SceneRenderer.h"


void leo::SceneRenderer::registerRenderer(const IRenderer* renderer)
{
}

void leo::SceneRenderer::unregisterRenderer(const IRenderer* renderer)
{
}

void leo::SceneRenderer::renderScene(const IRenderTarget& target) const
{
}

leo::SceneRenderer::SceneRenderer()
{
}


leo::SceneRenderer::~SceneRenderer()
{
	_listeners.clear();
}

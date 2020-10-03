#pragma once

#ifndef __SCENE_RENDERER__
#define __SCENE_RENDERER__

#include <vector>
#include "GLRenderTarget.h"
#include "Scene.h"

namespace leo {

	class IRenderer {
		virtual void render(const IRenderTarget* target) const = 0;
	};

	/*
		Contains references to all IRenderer objects that make up a scene.
		An instance of SceneRenderer is created by the application and
		IRenderer objects can register with this SceneRenderer

		TODO: determine how to handle logic for sorting rendering
	*/

	class ISceneRenderer
	{

	};

	class SceneRenderer : ISceneRenderer
	{
	public:
		void registerRenderer(const IRenderer* renderer);
		void unregisterRenderer(const IRenderer* renderer);

		void renderScene(const IRenderTarget& target) const;

		SceneRenderer();
		~SceneRenderer();

	private:
		std::vector<const IRenderer*> _listeners;
		IScene* _scene;
	};


}
#endif
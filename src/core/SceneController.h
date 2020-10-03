#pragma once
#ifndef  __LEO_SCENE_CONTROLLER__
#include "Scene.h"
#include <memory>

namespace leo {

	class SceneController
	{
	public:
		SceneController();
		~SceneController();

	private:
		std::unique_ptr<IScene> _ptrScene;

	};


}

#endif // ! __LEO_SCENE_CONTROLLER__
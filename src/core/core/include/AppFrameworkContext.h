#pragma once

#include <vector>

namespace leo {
	class InputEventEmitter;
	class GLRenderTarget;

	struct AppFrameworkContext {
		GLRenderTarget* renderTarget;
		InputEventEmitter* inputEventEmitter;
	};
}
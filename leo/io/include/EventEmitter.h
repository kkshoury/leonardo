
/*#pragma once
#include <vector>
#include <memory>
#include "MouseEventListener.h"
#include "KeyEventListener.h"

namespace leo {

	class EventEmitter2 {
	public:
		void init() const;
		void pollEvents() const;
		void waitForEvents() const;
		void waitForEventsTimeout(double ms) const;

		void keyCallback();
		void mouseCallback();

	private:
		std::vector<std::shared_ptr<KeyEventListener>> keyListeners;
		std::vector<std::shared_ptr<MouseEventListener>> mouseListeners;

	};


}*/
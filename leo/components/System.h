#pragma once
#include <vector>
#include "../core/include/AppFrameworkObject.h"
#include "Component.h"

namespace leo {

	class System{
		virtual void off() = 0;
		virtual void on() = 0;

		virtual int process(double t_ms) = 0;

		virtual bool add(int id, std::vector<Component> entity) = 0;
		virtual bool remove(int id) = 0;
		virtual bool freeze(int id) = 0;
		virtual bool unfreeze(int id) = 0;

	};
}
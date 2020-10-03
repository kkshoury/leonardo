#pragma once
#include <vector>
#include <memory>
#include "Component.h"

namespace leo {

	class System{
		virtual void off() = 0;
		virtual void on() = 0;

		virtual int process(double t_ms) = 0;

		virtual bool add(int id, const std::vector<std::shared_ptr<Component>>& entity) = 0;
		virtual bool remove(int id) = 0;
		virtual bool freeze(int id) = 0;
		virtual bool unfreeze(int id) = 0;
		virtual bool canProcess(const std::vector<std::shared_ptr<Component>>& componentList) = 0;
	};
}
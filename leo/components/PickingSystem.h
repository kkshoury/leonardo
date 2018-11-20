#pragma once
#include "System.h"
#include "Component.h"
#include <vector>
#include <memory>
#include "../io/include/KeyEventListener.h"
#include "../io/include/GLFWEventEmitter.h"


namespace leo {

	static class PickKeyListener;
	
	class PickingSystem : public System, public AppFrameworkObject {
	public:
		void addEntity(Component component);

		bool removeEntity(int id);
	private:
		std::unique_ptr<std::vector<Component>> componentList;
		std::shared_ptr<PickKeyListener> keyListener;

		// Inherited via AppFrameworkObject
		virtual void preInit() override;
		virtual void init() override;
		virtual void postInit() override;
		virtual void start() override;
		virtual void end() override;
		virtual void dispose() override;

		// Inherited via System
		virtual void off() override;
		virtual void on() override;
		virtual int process(double t_ms) override;
		virtual bool add(int id, std::vector<Component> entity) override;
		virtual bool remove(int id) override;
		virtual bool freeze(int id) override;
		virtual bool unfreeze(int id) override;
	};

	static class PickKeyListener : public KeyEventListener {
		// Inherited via KeyEventListener
		virtual void onKeyDown(char key, double t_ms) override;
		virtual void onKeyUp(char key, double t_ms) override;
	};
}


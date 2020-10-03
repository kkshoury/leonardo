#pragma once
#include <memory>
#include <vector>

#include "Component.h"
#include "Pickable.h"
#include "System.h"
#include "io.h"
#include "AppFrameworkObject.h"
#include "AppFrameworkContext.h"
#include "InputEventEmitter.h"

namespace leo {

	class PickKeyListener;
	class PickMouseListener;
	
	class PickingSystem : public System, public AppFrameworkObject {
	public:
		void addEntity(std::shared_ptr<Component> component);

		bool removeEntity(int id);
		
		// Inherited via AppFrameworkObject
		virtual void preInit() override;
		virtual void init(const AppFrameworkContext& context) override;
		virtual void postInit() override;
		virtual void start() override;
		virtual void end() override;
		virtual void dispose() override;

		// Inherited via System
		virtual void off() override;
		virtual void on() override;
		virtual int process(double t_ms) override;
		virtual bool add(int id, const std::vector<std::shared_ptr<Component>> &entity) override;
		virtual bool remove(int id) override;
		virtual bool freeze(int id) override;
		virtual bool unfreeze(int id) override;
		virtual bool canProcess(const std::vector<std::shared_ptr<Component>>& componentList) override;

	private:
		std::unique_ptr<std::vector<Component*>> _componentList;
		std::unique_ptr<PickKeyListener> _keyListener;
		std::unique_ptr<PickMouseListener> _mouseListener;
		InputEventEmitter* _inputEventEmitter;

		bool _on;
	};

	class PickKeyListener : public KeyEventListener {
		// Inherited via KeyEventListener
		virtual void onKeyDown(char key, double t_ms) override;
		virtual void onKeyUp(char key, double t_ms) override;
		virtual void onClick(char key, double t_ms) override;
		virtual void onDoubleClick(char key, double t_ms) override;
	};

	class PickMouseListener : public MouseEventListener {
		// Inherited via MouseEventListener
		virtual void onMouseDown(int mx, int my, MouseButton_enum button, double t_ms) override;
		virtual void onMouseUp(int mx, int my, MouseButton_enum button, double t_ms) override;
		virtual void onMouseDragged(int mx, int my, double t_ms) override;
	};
}


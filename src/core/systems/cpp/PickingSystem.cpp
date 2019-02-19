#include <iostream>
#include "..\include\PickingSystem.h"

void leo::PickKeyListener::onKeyDown(char key, double t_ms)
{
	std::cout << key << " pressed"<<std::endl;
}

void leo::PickKeyListener::onKeyUp(char key, double t_ms)
{

}

void leo::PickKeyListener::onClick(char key, double t_ms)
{
}

void leo::PickKeyListener::onDoubleClick(char key, double t_ms)
{
}

void leo::PickingSystem::addEntity(std::shared_ptr<Component> component)
{
}

bool leo::PickingSystem::removeEntity(int id)
{
	return false;
}

void leo::PickingSystem::preInit()
{
}

void leo::PickingSystem::init(const AppFrameworkContext& context)
{
	//_keyListener = std::make_shared<PickKeyListener>();
	//_mouseListener = std::make_shared<PickMouseListener>();
	_inputEventEmitter = context.inputEventEmitter;
}

void leo::PickingSystem::postInit()
{

}

void leo::PickingSystem::start()
{
	_inputEventEmitter->addKeyListener(_keyListener.get(), InputEventEmitter::InputEventType::DOWN);
	_inputEventEmitter->addMouseListener(_mouseListener.get(), InputEventEmitter::InputEventType::DOWN);
}

void leo::PickingSystem::end()
{
}

void leo::PickingSystem::dispose()
{
}

void leo::PickingSystem::off()
{
}

void leo::PickingSystem::on()
{
}

int leo::PickingSystem::process(double t_ms)
{
	return 0;
}

bool leo::PickingSystem::add(int id, const std::vector<std::shared_ptr<Component>> &entity)
{
	return false;
}

bool leo::PickingSystem::remove(int id)
{
	return false;
}

bool leo::PickingSystem::freeze(int id)
{
	return false;
}

bool leo::PickingSystem::unfreeze(int id)
{
	return false;
}

bool leo::PickingSystem::canProcess(const std::vector<std::shared_ptr<Component>>& componentList)
{
	for (auto itr = std::begin(componentList); itr != std::end(componentList); itr++) {
		if ((*itr)->getId() == CPickable::id()) {
			return true;
		}
	}

	return false;
}


void leo::PickMouseListener::onMouseDown(int mx, int my, MouseButton_enum button, double t_ms)
{
	std::cout << "mouse is down" << std::endl;
}

void leo::PickMouseListener::onMouseUp(int mx, int my, MouseButton_enum button, double t_ms)
{
	std::cout << "mouse is Up" << std::endl;

}

void leo::PickMouseListener::onMouseDragged(int mx, int my, double t_ms)
{
	std::cout << "mouse is dragged" << std::endl;


}

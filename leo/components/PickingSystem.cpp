#include "PickingSystem.h"
#include <iostream>

void leo::PickKeyListener::onKeyDown(char key, double t_ms)
{
	std::cout << key << " pressed";
}

void leo::PickKeyListener::onKeyUp(char key, double t_ms)
{

}

void leo::PickingSystem::addEntity(Component component)
{
}

bool leo::PickingSystem::removeEntity(int id)
{
	return false;
}

void leo::PickingSystem::preInit()
{
}

void leo::PickingSystem::init()
{
	this->keyListener = std::make_shared<PickKeyListener>();
}

void leo::PickingSystem::postInit()
{

}

void leo::PickingSystem::start()
{
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

bool leo::PickingSystem::add(int id, std::vector<Component> entity)
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

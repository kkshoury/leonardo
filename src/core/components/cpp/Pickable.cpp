#include "Pickable.h"

leo::CPickable::CPickable()
{
	type_id = "component_pickable_id";
}

bool leo::CPickable::isPicked() const
{
	return picked;
}

void leo::CPickable::setPicked(bool picked)
{
	this->picked = picked;
}

bool leo::CPickable::testPickCondition() const
{
	return true;
}

ComponentId_type leo::CPickable::getId() const
{
	return type_id;
}

ComponentId_type leo::CPickable::id()
{
	return "component_pickable_id";
}

#include "Pickable.h"

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

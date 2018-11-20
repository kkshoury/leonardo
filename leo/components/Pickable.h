#pragma once
#include <memory>
#include "Component.h"
#include "CGeometry.h"
#include "System.h"

namespace leo {

	class CPickable : public Component 
	{
	public:
		const static int COMPONENT_PICKABLE_ID = 0;

		bool isPicked() const;
		void setPicked(bool picked);
		virtual bool testPickCondition() const;
	private:
		bool picked = false;
	};
}
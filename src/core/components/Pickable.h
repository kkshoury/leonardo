#pragma once
#include <memory>
#include "CGeometry.h"
#include "System.h"

namespace leo {

	class CPickable : public Component 
	{
	public:
		CPickable();

		bool isPicked() const;
		void setPicked(bool picked);
		virtual bool testPickCondition() const;
		
		// Inherited via Component
		virtual ComponentId_type getId() const override;
		static ComponentId_type id();
	private:
		ComponentId_type type_id;
		bool picked = false;

	};
}
#ifndef _LEO_COMPONENT_
#define _LEO_COMPONENT_
#pragma once

#include <string>

#ifndef _LEO_COMP_TYPE
#define _LEO_COMP_TYPE
	typedef std::string ComponentId_type;
#endif

namespace leo {
	class Component {
	public:
		virtual ComponentId_type getId() const = 0;
	};

	

}

#endif

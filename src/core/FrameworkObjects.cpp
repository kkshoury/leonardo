#include "graphics.h"
#include "io.h"
#include "components.h"
#include "AppFrameworkObject.h"

#include <vector>
#include <memory>

namespace leo {

	std::unique_ptr<std::vector<leo::AppFrameworkObject*>> getAppObjects() {
		auto list = std::make_unique<std::vector<leo::AppFrameworkObject*>>();
		
		return std::move(list);
	}	

}

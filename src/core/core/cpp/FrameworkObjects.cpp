#include "graphics.h"
#include "common.h"
#include "io.h"
#include "components.h"
#include "AppFrameworkObject.h"

#include <vector>

namespace leo {

	std::vector<std::shared_ptr<leo::AppFrameworkObject>>* getAppObjects() {
		auto list = new std::vector<std::shared_ptr<leo::AppFrameworkObject>>();
		
		list->push_back(std::shared_ptr<leo::AppFrameworkObject>(new PickingSystem()));



		return list;
	}	

}

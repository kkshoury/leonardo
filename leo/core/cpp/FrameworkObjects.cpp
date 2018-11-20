#include "../core.h"
#include "../graphics/graphics.h"
#include "../common/common.h"
#include "../io/io.h"
#include "../components/components.h"

#include <vector>

namespace leo {

	std::vector<std::shared_ptr<leo::AppFrameworkObject>>* getAppObjects() {
		auto list = new std::vector<std::shared_ptr<leo::AppFrameworkObject>>();
		list->push_back(std::shared_ptr<leo::AppFrameworkObject>(new PickingSystem()));



		return list;
	}	

}

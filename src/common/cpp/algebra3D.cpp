#include "vec3.h"

namespace leo {
	namespace lin3d {

		static int x;
	
		inline float dot(const vec3& a, const vec3& b) {
			return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
		}

		inline vec3 cross(const vec3& a, const vec3& b) {
			return vec3(
				a.y()*b.z() - a.z()*b.y(),
				-(a.x()*b.z() - a.z()*b.x()),
				a.x()*b.y() - a.y()*b.x());
		}



	}

}
#include <cmath>

#define M_PI 3.14159265358979323846f
#define HALF_CIRCLE_DEGREES (180.0f)
namespace leo {
	namespace math3d {
		typedef float degrees_type;
		typedef float radians_type;
		
		float HALF_PI = M_PI / HALF_CIRCLE_DEGREES;
		float INV_PI = 1.0f / M_PI;

		degrees_type toDegree(radians_type angle) {
			return  angle * HALF_PI;
		}

		radians_type toRadians(degrees_type angle) {
			return angle * HALF_PI * HALF_CIRCLE_DEGREES;
		}

	}
}
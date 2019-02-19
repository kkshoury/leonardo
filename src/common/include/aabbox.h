#ifndef _LEO_AA_BOUNDING_BOX_
#define _LEO_AA_BOUNDING_BOX_
#pragma once

#include "vec3.h"
#include "aabbox.h"

namespace leo {
	class AABbox {
	public:
		AABbox();
		AABbox(const vec3 &p1, const vec3& p2);
		AABbox(float x1, float y1, float z1, float x2, float y2, float z2);
		
		vec3 getLow() const;
		vec3 getHigh() const;

		void addPoint(float x, float y, float z);
		void addPoint(const vec3 &point);

		bool isValid();


	private:
		vec3 _center;
		vec3 _low;
		vec3 _high;

		void _validate(const vec3 & p);
		void _validate(float x, float y, float z);



	};
}
#endif

#ifndef _LEO_SPHERE_GEOMETRY_
#define _LEO_SPHERE_GEOMETRY_
#pragma once

#include "Geometry3D.h"

namespace leo {
	class SphereGeometry : Geometry3D{
	public:
		SphereGeometry();
		SphereGeometry(const vec3 &center, float radius);
		
		float getRadius() const;
		vec3 getCenter() const;

		void setRadius(float radius);
		void setCenter(const vec3& center);
		void setCenter(float x, float y, float z);

		// Inherited via Geometry3D
		virtual AABbox getAABoundingBox() override;
		virtual std::shared_ptr<MeshGeometry> generateMeshGeometry() override;

	private:
		float _radius;
		vec3 _center;
		AABbox _bbox;
	};
}

#endif
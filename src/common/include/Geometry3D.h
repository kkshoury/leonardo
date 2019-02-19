#ifndef _LEO_GEOMETRY_3D_
#define _LEO_GEOMETRY_3D_
#pragma once

#include "aabbox.h"
#include "vec3.h"

class MeshGeometry;

namespace leo {
	class Geometry3D {
	public:
		virtual AABbox getAABoundingBox() = 0;
		virtual std::shared_ptr<MeshGeometry> generateMeshGeometry() = 0;
	};
}

#endif
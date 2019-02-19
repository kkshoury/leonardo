#pragma once

#include "Geometry3D.h"

namespace leo {
	class PolygonGeometry : public Geometry3D {
	public:
		PolygonGeometry();
		~PolygonGeometry();


		// Inherited via Geometry3D
		virtual leo::AABbox getAABoundingBox() override;
		virtual std::shared_ptr<MeshGeometry> generateMeshGeometry() override;

	private:
		AABbox _bbox;
		std::shared_ptr<MeshGeometry> _mesh;
	};
}
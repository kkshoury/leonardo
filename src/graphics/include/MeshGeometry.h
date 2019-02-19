#pragma once

#include <vector>

namespace leo {
	class PolygonMeshGeometry {

	};

	typedef VertexVertexPolygonMesh VVPolygonMesh;

	class VertexVertexPolygonMesh : public PolygonMeshGeometry {

	};

	class TriangleMesh {
	public:
		std::vector<float> vertices;
		std::vector<float> colors;

	};
}
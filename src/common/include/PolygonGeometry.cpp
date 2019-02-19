#include "PolygonGeometry.h"

leo::PolygonGeometry::PolygonGeometry()
{
}

leo::PolygonGeometry::~PolygonGeometry()
{
}

leo::AABbox leo::PolygonGeometry::getAABoundingBox()
{
	return AABbox();
}

std::shared_ptr<MeshGeometry> leo::PolygonGeometry::generateMeshGeometry()
{
	return std::shared_ptr<MeshGeometry>();
}

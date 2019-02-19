#include "SphereGeometry.h"

leo::SphereGeometry::SphereGeometry()
{
	_bbox = AABbox();
}

leo::SphereGeometry::SphereGeometry(const vec3 & center, float radius)
{
	_center = center;
	_radius = radius;
	_bbox = AABbox();

}

float leo::SphereGeometry::getRadius() const
{
	return _radius;
}

vec3 leo::SphereGeometry::getCenter() const
{
	return _center;
}

void leo::SphereGeometry::setRadius(float radius)
{
	_radius = radius;
}

void leo::SphereGeometry::setCenter(const vec3 & center)
{
	_center = center;
}

void leo::SphereGeometry::setCenter(float x, float y, float z)
{
	_center = vec3(x, y, z);
}

leo::AABbox leo::SphereGeometry::getAABoundingBox()
{
	return AABbox();
}

std::shared_ptr<MeshGeometry> leo::SphereGeometry::generateMeshGeometry()
{
	return std::shared_ptr<MeshGeometry>();
}


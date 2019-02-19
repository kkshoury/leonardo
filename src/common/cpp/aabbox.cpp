#include "aabbox.h"

leo::AABbox::AABbox()
{
	float min = std::numeric_limits<float>().lowest();
	float max = std::numeric_limits<float>().infinity();

	_low = vec3(min, min, min);
	_high = vec3(max, max, max);

}

leo::AABbox::AABbox(const vec3 & p1, const vec3 & p2) : AABbox()
{
	_validate(p1);
	_validate(p2);
}

leo::AABbox::AABbox(float x1, float y1, float z1, float x2, float y2, float z2)
{
	_validate(x1, y1, z1);
	_validate(x2, y2, z2);
}

vec3 leo::AABbox::getLow() const
{
	return _low;
}

vec3 leo::AABbox::getHigh() const
{
	return _high;
}

void leo::AABbox::addPoint(float x, float y, float z)
{
	_validate(x, y, z);
}

void leo::AABbox::addPoint(const vec3 & point)
{
	_validate(point);
}

bool leo::AABbox::isValid()
{
	float min = std::numeric_limits<float>().lowest();
	float max = std::numeric_limits<float>().infinity();

	bool valid = !(_low.x()== min || _low.y() == min || _low.z() == min);
	valid = valid && !(_high.x() == max || _high.y() == max || _high.z() == max);
	valid = valid && _low.x()<= _high.x() && _low.y() <= _high.y() && _low.z() <= _high.z();

	return valid;
}

void leo::AABbox::_validate(const vec3 & p)
{
	if (p.x() < _low.x()) {
		_low.setX(p.x());
	}

	if (p.y() < _low.y()) {
		_low.setY(p.y());
	}

	if (p.z() < _low.z()) {
		_low.setZ(p.z());
	}


	if (p.x()> _high.x()) {
		_high.setX(p.x());
	}

	if (p.y() > _high.y()) {
		_high.setY(p.y());
	}

	if (p.z() > _high.z()) {
		_high.setZ(p.z());
	}


	
}

void leo::AABbox::_validate(float x, float y, float z)
{
	if (x < _low.x()) {
		_low.setX(x);
	}

	if (y < _low.y()) {
		_low.setY(y);
	}

	if (z < _low.z()) {
		_low.setZ(z);
	}


	if (x > _high.x()) {
		_high.setX(x);
	}

	if (y > _high.y()) {
		_high.setY(y);
	}

	if (z > _high.z()) {
		_high.setZ(z);
	}



}

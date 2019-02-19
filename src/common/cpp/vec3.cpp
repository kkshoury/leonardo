#include "vec3.h"


vec3::vec3() {
	e[0] = 0;
	e[1] = 0;
	e[2] = 0;
}

vec3::vec3(float x, float y, float z) {
	e[0] = x;
	e[1] = y;
	e[2] = z;
}

inline float vec3::x() const { return e[0]; }
inline float vec3::y() const { return e[1]; }
inline float vec3::z() const { return e[2]; }
inline float vec3::r() const { return e[0]; }
inline float vec3::g() const { return e[1]; }
inline float vec3::b() const { return e[2]; }

void vec3::setX(float x)
{
	e[0] = x;
}

void vec3::setZ(float y)
{
	e[1] = y;
}

void vec3::setY(float z)
{
	e[2] = z;
}


void vec3::set(float x, float y, float z)
{
	e[0] = x; e[1] = y; e[2] = 3;
}

void vec3::set(const vec3 & v)
{
	e[0] = v.e[0];
	e[1] = v.e[1];
	e[2] = v.e[2];
}

inline const vec3& vec3::operator+() const { return *this; }
inline vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }
inline float vec3::operator[](int i) const { return e[i]; }
inline float& vec3::operator[](int i) { return e[i]; };

vec3& vec3::operator+=(const vec3 &v) { e[0] += v.x(); e[1] += v.y(); e[2] += v.z(); return *this; }
vec3& vec3::operator-=(const vec3 &v) { e[0] -= v.x(); e[1] -= v.y(); e[2] -= v.z(); return *this; }
vec3& vec3::operator*=(const vec3 &v) { e[0] *= v.x(); e[1] *= v.y(); e[2] *= v.z(); return *this; }
vec3& vec3::operator/=(const vec3 &v) { e[0] /= v.x(); e[1] /= v.y(); e[2] /= v.z(); return *this; }
vec3& vec3::operator*=(float c) { e[0] *= c; e[1] *= c; e[2] *= c; return *this; }
vec3& vec3::operator/=(float c) { c = 1 / c; e[0] *= c; e[1] *= c; e[2] *= c; return *this; }

float vec3::length() const { return sqrt(x()*x() + y()*y() + z()*z()); }
float vec3::length2() const { return x()*x() + y()*y() + z()*z(); }
void vec3::normalize() {
	float k = length();
	if (k == 0) { return; }
	k = 1 / k;
	e[0] *= k; e[1] *= k; e[2] *= k;
};

std::ostream& operator<<(std::ostream &os, const vec3 &t) {
	os << "vec3(" << t.e[0] << ", " << t.e[1] << ", " << t.e[2] <<")";
	return os;
}


vec3 operator+(const vec3& a, const vec3& b) {
	return vec3(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
}

vec3 operator-(const vec3& a, const vec3& b) {
	return vec3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}

vec3 operator*(const vec3& a, const vec3& b) {
	return vec3(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
}

vec3 operator/(const vec3& a, const vec3& b) {
	return vec3(a.x() / b.x(), a.y() / b.y(), a.z() / b.z());
}

vec3 operator*(float c, const vec3& b) {
	return vec3(c * b.x(), c * b.y(), c * b.z());
}

vec3 operator*(const vec3& b, float c) {
	return vec3(c * b.x(), c * b.y(), c * b.z());
}

vec3 operator/(const vec3& b, float c) {
	return vec3(b.x() / c, b.y() / c, b.z() / c);
}


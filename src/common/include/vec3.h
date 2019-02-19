#ifndef _LEO_VEC3_
#define _LEO_VEC3_
#pragma once

#include <iostream>
#include <math.h>

typedef float float_t;
class vec3
{
public:
	vec3();
	vec3(float x, float y, float z);
	inline float x() const;
	inline float y() const;
	inline float z() const;
	inline float r() const;
	inline float g() const;
	inline float b() const;

	void setX(float x);
	void setZ(float y);
	void setY(float z);

	void set(float x, float y, float z);
	void set(const vec3& v);

	inline const vec3& operator+() const;
	inline vec3 operator-() const;
	inline float operator[](int i) const;
	inline float& operator[](int i);

	inline vec3& operator+=(const vec3 &v);
	inline vec3& operator-=(const vec3 &v);
	inline vec3& operator*=(const vec3 &v);
	inline vec3& operator/=(const vec3 &v);
	inline vec3& operator*=(float c);
	inline vec3& operator/=(float c);

	float length() const;
	float length2() const;
	void normalize();


	~vec3() {};

	float e[3];
};

std::ostream& operator<<(std::ostream &os, const vec3 &t);

vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator*(const vec3& a, const vec3& b);
vec3 operator/(const vec3& a, const vec3& b);
vec3 operator*(float c, const vec3& b);
vec3 operator*(const vec3& b, float c);
vec3 operator/(const vec3& b, float c);


typedef vec3 pos3;
typedef vec3 rgb;

#endif
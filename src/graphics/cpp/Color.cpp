#include "Color.h"

char leo::Color::r()
{
	return (val & 0xFF000000) >> 24;
}

char leo::Color::g()
{
	return (val & 0x00FF0000) >> 16;
}

char leo::Color::b()
{
	return (val & 0x0000FF00) >> 8;
}

char leo::Color::a()
{
	return (val & 0x000000FF);
}

void leo::Color::r(char r)
{

}

void leo::Color::g(char g)
{
}

void leo::Color::b(char b)
{
}

void leo::Color::a(char a)
{
}

int leo::Color::getInt()
{
	return 0;
}

void leo::Color::setInt(int color)
{
	val = color;
}

float leo::Color::getFloat()
{
	return (val)/255.f;
}

void leo::Color::setFloat(float col)
{
	val = (int)(col * 255);
}

leo::Color::Color(char r, char g , char b, char a = 255)
{
	this->r(r); 
	this->g(g); 
	this->b(b);
	this->a(a);
}

leo::Color::Color(int rgba)
{
	val = rgba;
}

#include "Linear.h"

float LinearCurve::easeIn(float t, float b, float c, float d)
{
	return c * t / d + b;
}
float LinearCurve::easeOut(float t, float b, float c, float d)
{
	return c * t / d + b;
}

float LinearCurve::easeInOut(float t, float b, float c, float d)
{
	return c * t / d + b;
}
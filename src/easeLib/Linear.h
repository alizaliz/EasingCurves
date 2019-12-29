#ifndef _PENNER_LINEAR
#define _PENNER_LINEAR

class LinearCurve
{

public:
	static float easeIn(float t, float b, float c, float d);
	static float easeOut(float t, float b, float c, float d);
	static float easeInOut(float t, float b, float c, float d);
};

#endif
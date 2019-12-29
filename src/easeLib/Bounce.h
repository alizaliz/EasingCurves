#ifndef _PENNER_BOUNCE
#define _PENNER_BOUNCE

class BounceCurve
{

public:
	static float easeIn(float t, float b, float c, float d);
	static float easeOut(float t, float b, float c, float d);
	static float easeInOut(float t, float b, float c, float d);
};

#endif
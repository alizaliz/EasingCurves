
#ifndef EasingCurves_h
#define EasingCurves_h

//#include "Arduino.h"

#include "./easeLib/Back.h"
#include "./easeLib/Bounce.h"
#include "./easeLib/Circ.h"
#include "./easeLib/Cubic.h"
#include "./easeLib/Elastic.h"
#include "./easeLib/Expo.h"
#include "./easeLib/Linear.h"
#include "./easeLib/Sine.h"
#include "./easeLib/Quad.h"
#include "./easeLib/Quart.h"
#include "./easeLib/Quint.h"

enum ease
{
    BACK,
    BOUNCE,
    CIRC,
    CUBIC,
    ELASTIC,
    EXPO,
    LINEAR,
    SINE,
    QUAD,
    QUART,
    QUINT
};

class EasingCurves
{
public:
    typedef float (*EaseFunction)(float t, float b, float c, float d);

    EasingCurves();
    EasingCurves(ease type, float start, float end, float duration);

    void SetType(ease type);

private:
    float m_startValue;
    float m_change;
    long m_startTime;
    float m_duration;

    EaseFunction easeInFunction;
    EaseFunction easeOutFunction;
    EaseFunction easeInOutFunction;
};

#endif

#ifndef EasingCurves_h
#define EasingCurves_h

#include "Arduino.h"
#include "easeLib/Back.h"
#include "easeLib/Bounce.h"
#include "easeLib/Circ.h"
#include "easeLib/Cubic.h"
#include "easeLib/Elastic.h"
#include "easeLib/Expo.h"
#include "easeLib/Linear.h"
#include "easeLib/Sine.h"
#include "easeLib/Quad.h"
#include "easeLib/Quart.h"
#include "easeLib/Quint.h"

enum ease
{
    BACK_IN,
    BACK_OUT,
    BACK_INOUT,
    BOUNCE_IN,
    BOUNCE_OUT,
    BOUNCE_INOUT,
    CIRC_IN,
    CIRC_OUT,
    CIRC_INOUT,
    CUBIC_IN,
    CUBIC_OUT,
    CUBIC_INOUT,
    ELASTIC_IN,
    ELASTIC_OUT,
    ELASTIC_INOUT,
    EXPO_IN,
    EXPO_OUT,
    EXPO_INOUT,
    LINEAR_IN,
    LINEAR_OUT,
    LINEAR_INOUT,
    SINE_IN,
    SINE_OUT,
    SINE_INOUT,
    QUAD_IN,
    QUAD_OUT,
    QUAD_INOUT,
    QUART_IN,
    QUART_OUT,
    QUART_INOUT,
    QUINT_IN,
    QUINT_OUT,
    QUINT_INOUT
};

class EasingCurves
{
public:
    typedef float (*EaseFunction)(float t, float b, float c, float d);

    EasingCurves();
    EasingCurves(ease type, float start, float end, float duration);

    void start();
    void restart();
    float update();
    float reverseUpdate();

    void setDurationMillis(unsigned long interval);
    void setDurationMicros(unsigned long interval);

    void setType(ease type);

    bool isActive();




private:

    float evaluate(unsigned long t);

    float m_startValue;
    float m_change;
    float m_currentValue;
    long m_startTime;
    float m_duration;

    bool m_active;

    EaseFunction easeFunction;
};

#endif
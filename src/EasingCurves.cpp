#include "EasingCurves.h"

EasingCurves::EasingCurves()
{
    EasingCurves(ease::LINEAR_IN, 0.0f, 1.0f, 1e+6);
}

EasingCurves::EasingCurves(ease type, float start, float end, float duration)
{
    setType(type);
    m_startValue = start;
    m_change = end - start;
    m_duration = 1000 * duration;
}

bool EasingCurves::isActive()
{
    return m_active;
}

void EasingCurves::start()
{
    m_active = true;
    m_startTime = micros();
}

void EasingCurves::restart()
{
    start();
}

float EasingCurves::evaluate(float t)
{

    if (t > m_duration || t < 0) // expand this for accuracy
    {
        m_active = false;
    }

    if (m_active)
        m_currentValue = easeFunction(t, m_startValue, m_change, m_duration);

    return m_currentValue;
}

float EasingCurves::update()
{
    return evaluate(static_cast<float>(micros() - m_startTime));
}

float EasingCurves::reverseUpdate()
{
    return evaluate(m_duration - static_cast<float>(micros() - m_startTime));
}

void EasingCurves::setDurationMillis(unsigned long duration)
{
    m_duration = 1000 * duration;
}

void EasingCurves::setDurationMicros(unsigned long duration)
{
    m_duration = duration;
}

void EasingCurves::setType(ease type)
{
    switch (type)
    {
    case BACK_IN:
        easeFunction = (&Back::easeIn);
        break;
    case BACK_OUT:
        easeFunction = (&Back::easeOut);
        break;
    case BACK_INOUT:
        easeFunction = (&Back::easeInOut);
        break;
    case BOUNCE_IN:
        easeFunction = (&BounceCurve::easeIn);
        break;
    case BOUNCE_OUT:
        easeFunction = (&BounceCurve::easeOut);
        break;
    case BOUNCE_INOUT:
        easeFunction = (&BounceCurve::easeInOut);
        break;
    case CIRC_IN:
        easeFunction = (&Circ::easeIn);
        break;
    case CIRC_OUT:
        easeFunction = (&Circ::easeOut);
        break;
    case CIRC_INOUT:
        easeFunction = (&Circ::easeInOut);
        break;
    case CUBIC_IN:
        easeFunction = (&Cubic::easeIn);
        break;
    case CUBIC_OUT:
        easeFunction = (&Cubic::easeOut);
        break;
    case CUBIC_INOUT:
        easeFunction = (&Cubic::easeInOut);
        break;
    case ELASTIC_IN:
        easeFunction = (&Elastic::easeIn);
        break;
    case ELASTIC_OUT:
        easeFunction = (&Elastic::easeOut);
        break;
    case ELASTIC_INOUT:
        easeFunction = (&Elastic::easeInOut);
        break;
    case EXPO_IN:
        easeFunction = (&Expo::easeIn);
        break;
    case EXPO_OUT:
        easeFunction = (&Expo::easeOut);
        break;
    case EXPO_INOUT:
        easeFunction = (&Expo::easeInOut);
        break;
    case LINEAR_IN:
        easeFunction = (&Linear::easeIn);
        break;
    case LINEAR_OUT:
        easeFunction = (&Linear::easeOut);
        break;
    case LINEAR_INOUT:
        easeFunction = (&Linear::easeInOut);
        break;
    case SINE_IN:
        easeFunction = (&Sine::easeIn);
        break;
    case SINE_OUT:
        easeFunction = (&Sine::easeOut);
        break;
    case SINE_INOUT:
        easeFunction = (&Sine::easeInOut);
        break;
    case QUAD_IN:
        easeFunction = (&Quad::easeIn);
        break;
    case QUAD_OUT:
        easeFunction = (&Quad::easeOut);
        break;
    case QUAD_INOUT:
        easeFunction = (&Quad::easeInOut);
        break;
    case QUART_IN:
        easeFunction = (&Quart::easeIn);
        break;
    case QUART_OUT:
        easeFunction = (&Quart::easeOut);
        break;
    case QUART_INOUT:
        easeFunction = (&Quart::easeInOut);
        break;
    case QUINT_IN:
        easeFunction = (&Quint::easeIn);
        break;
    case QUINT_OUT:
        easeFunction = (&Quint::easeOut);
        break;
    case QUINT_INOUT:
        easeFunction = (&Quint::easeInOut);
        break;
    }
}

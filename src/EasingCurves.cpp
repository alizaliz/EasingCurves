#include "EasingCurves.h"

EasingCurves::EasingCurves()
{
    EasingCurves(ease::LINEAR_IN, 0.0f, 1.0f, 1e+6);
}

EasingCurves::EasingCurves(ease type, float start, float end, float duration)
{
    SetType(type);
    m_startValue = start;
    m_change = end - start;
    m_duration =  1000 * duration;
}

void EasingCurves::Start()
{
    m_active = true;
    m_startTime = micros();
}

void EasingCurves::Restart()
{
    Start();
}

float EasingCurves::Update()
{
    if (!m_active)
        return m_currentValue;

    unsigned long elapsedTime = micros() - m_startTime;
    if (elapsedTime >= m_duration)
    {
        m_active = false;
        return m_currentValue;
    }

    m_currentValue = easeFunction(elapsedTime, m_startValue, m_change, m_duration);
    return m_currentValue;
}

void EasingCurves::SetDurationMillis(unsigned long duration)
{
    m_duration = 1000 * duration;
}

void EasingCurves::SetDurationMicros(unsigned long duration)
{
    m_duration = duration;
}

void EasingCurves::SetType(ease type)
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
        easeFunction = (&Bounce::easeIn);
        break;
    case BOUNCE_OUT:
        easeFunction = (&Bounce::easeOut);
        break;
    case BOUNCE_INOUT:
        easeFunction = (&Bounce::easeInOut);
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

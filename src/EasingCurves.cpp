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

animationState EasingCurves::currentState()
{
    return m_state;
}

void EasingCurves::start()
{
    m_state = ACTIVE;
    m_startTime = micros();
}

void EasingCurves::restart()
{
    start();
}

void EasingCurves::pause()
{
    if (m_state != ACTIVE) return;
    m_state = PAUSED;
    m_pauseElapsedValue = micros() - m_startTime;
}

void EasingCurves::resume()
{
    if (m_state != PAUSED) return;
    m_state = ACTIVE;
    m_startTime = micros() - m_pauseElapsedValue;
}

void EasingCurves::stop()
{
    m_state = INACTIVE;
    m_currentValue = m_startValue;
}


float EasingCurves::evaluate(float t)
{
    if (t >= m_duration || t <= 0) // expand this for accuracy
    {
        m_state = INACTIVE;
    }

    if (m_state == ACTIVE)
        m_currentValue = easeFunction(t, m_startValue, m_change, m_duration);

    return m_currentValue;
}

float EasingCurves::getValue()
{
    return evaluate(static_cast<float>(micros() - m_startTime));
}

float EasingCurves::getValueOneMinus()
{
    return evaluate(m_duration - static_cast<float>(micros() - m_startTime));
}

void EasingCurves::setStartValue(float start)
{
     m_startValue = start;
}

void EasingCurves::setEndValue(float end)
{
    m_change = end - m_startValue;
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
        easeFunction = (&BackCurve::easeIn);
        break;
    case BACK_OUT:
        easeFunction = (&BackCurve::easeOut);
        break;
    case BACK_INOUT:
        easeFunction = (&BackCurve::easeInOut);
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
        easeFunction = (&CircCurve::easeIn);
        break;
    case CIRC_OUT:
        easeFunction = (&CircCurve::easeOut);
        break;
    case CIRC_INOUT:
        easeFunction = (&CircCurve::easeInOut);
        break;
    case CUBIC_IN:
        easeFunction = (&CubicCurve::easeIn);
        break;
    case CUBIC_OUT:
        easeFunction = (&CubicCurve::easeOut);
        break;
    case CUBIC_INOUT:
        easeFunction = (&CubicCurve::easeInOut);
        break;
    case ELASTIC_IN:
        easeFunction = (&ElasticCurve::easeIn);
        break;
    case ELASTIC_OUT:
        easeFunction = (&ElasticCurve::easeOut);
        break;
    case ELASTIC_INOUT:
        easeFunction = (&ElasticCurve::easeInOut);
        break;
    case EXPO_IN:
        easeFunction = (&ExpoCurve::easeIn);
        break;
    case EXPO_OUT:
        easeFunction = (&ExpoCurve::easeOut);
        break;
    case EXPO_INOUT:
        easeFunction = (&ExpoCurve::easeInOut);
        break;
    case LINEAR_IN:
        easeFunction = (&LinearCurve::easeIn);
        break;
    case LINEAR_OUT:
        easeFunction = (&LinearCurve::easeOut);
        break;
    case LINEAR_INOUT:
        easeFunction = (&LinearCurve::easeInOut);
        break;
    case SINE_IN:
        easeFunction = (&SineCurve::easeIn);
        break;
    case SINE_OUT:
        easeFunction = (&SineCurve::easeOut);
        break;
    case SINE_INOUT:
        easeFunction = (&SineCurve::easeInOut);
        break;
    case QUAD_IN:
        easeFunction = (&QuadCurve::easeIn);
        break;
    case QUAD_OUT:
        easeFunction = (&QuadCurve::easeOut);
        break;
    case QUAD_INOUT:
        easeFunction = (&QuadCurve::easeInOut);
        break;
    case QUART_IN:
        easeFunction = (&QuartCurve::easeIn);
        break;
    case QUART_OUT:
        easeFunction = (&QuartCurve::easeOut);
        break;
    case QUART_INOUT:
        easeFunction = (&QuartCurve::easeInOut);
        break;
    case QUINT_IN:
        easeFunction = (&QuintCurve::easeIn);
        break;
    case QUINT_OUT:
        easeFunction = (&QuintCurve::easeOut);
        break;
    case QUINT_INOUT:
        easeFunction = (&QuintCurve::easeInOut);
        break;
    }
}

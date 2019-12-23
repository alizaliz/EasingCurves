#include "EasingCurves.h"

EasingCurves::EasingCurves()
{
    EasingCurves(ease::LINEAR, 0.0f, 1.0f, 1e+6);
}

EasingCurves::EasingCurves(ease type, float start, float end, float duration)
{
    m_startValue = start;
    m_change = end - start;
    SetType(type);
    m_duration = duration;
}

void EasingCurves::SetType(ease type)
{
    switch (type)
    {
    case BACK:
        easeInFunction = (&Back::easeIn);
        easeOutFunction = (&Back::easeOut);
        easeInOutFunction = (&Back::easeInOut);
        break;
    case BOUNCE:
        easeInFunction = (&Bounce::easeIn);
        easeOutFunction = (&Bounce::easeOut);
        easeInOutFunction = (&Bounce::easeInOut);
        break;
    case CIRC:
        easeInFunction = (&Circ::easeIn);
        easeOutFunction = (&Circ::easeOut);
        easeInOutFunction = (&Circ::easeInOut);
        break;
    case CUBIC:
        easeInFunction = (&Cubic::easeIn);
        easeOutFunction = (&Cubic::easeOut);
        easeInOutFunction = (&Cubic::easeInOut);
        break;
    case ELASTIC:
        easeInFunction = (&Elastic::easeIn);
        easeOutFunction = (&Elastic::easeOut);
        easeInOutFunction = (&Elastic::easeInOut);
        break;
    case EXPO:
        easeInFunction = (&Expo::easeIn);
        easeOutFunction = (&Expo::easeOut);
        easeInOutFunction = (&Expo::easeInOut);
        break;
    case LINEAR:
        easeInFunction = (&Linear::easeIn);
        easeOutFunction = (&Linear::easeOut);
        easeInOutFunction = (&Linear::easeInOut);
        break;
    case SINE:
        easeInFunction = (&Sine::easeIn);
        easeOutFunction = (&Sine::easeOut);
        easeInOutFunction = (&Sine::easeInOut);
        break;
    case QUAD:
        easeInFunction = (&Quad::easeIn);
        easeOutFunction = (&Quad::easeOut);
        easeInOutFunction = (&Quad::easeInOut);
        break;
    case QUART:
        easeInFunction = (&Quart::easeIn);
        easeOutFunction = (&Quart::easeOut);
        easeInOutFunction = (&Quart::easeInOut);
        break;
    case QUINT:
        easeInFunction = (&Quint::easeIn);
        easeOutFunction = (&Quint::easeOut);
        easeInOutFunction = (&Quint::easeInOut);
        break;
    }
}

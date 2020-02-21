
/*
    MIT License (MIT)
    Copyright (c) 2019 Zain Ali
    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * Wrapper and implementation by Zain Ali
 * Based on Robert Penner's easeing functions : http://robertpenner.com/easing/
 */

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

enum animationState
{
    ACTIVE,
    PAUSED,
    INACTIVE
};

class EasingCurves
{
public:
    typedef float (*EaseFunction)(float t, float b, float c, float d);

    /*! Instance 
        @param type
        ease enumeration type
        @param start
        start value on curve
        @param end
        end value on curve
        @param duration
        duration of ease in milliseconds
    */
    EasingCurves();
    EasingCurves(ease type, float start, float end, float duration);

    /*! Start the auto timed curve function 
        Sets active to true and startime to time of function call
    */
    void start();
    /*! Alias for start() function 
    */
    void restart();
    /*! Halt timer and save current position
    */
    void pause();
    /*! Continue timer and from saved position
    */
    void resume();
    /*! Force stop and reset of postion
    */
    void stop();
    /*! Get value from ease curve
        @return ease curve mapped value 
     */
    float getValue();
    /*! Get one minus value of ease curve
        @return 1 - t ease curve mapped value 
    */
    float getValueOneMinus();

    /*! Set start of curve value
    */
    void setStartValue(float start);
    /*! Set end of curve value 
    */
    void setEndValue(float end);

    /*! Set duration in milliseconds (1000 * microseconds)
        @param duration
        Duration in milliseconds
    */
    void setDurationMillis(unsigned long duration);
    /*! Set duration in microseconds 
        @param duration
        Duration in microseonds
    */
    void setDurationMicros(unsigned long duration);

    /*! Set type or mode of function 
        @param type
        ease enumeration type
    */
    void setType(ease type);
    /*! Get  state of function
        @return state of animation 
    */
    animationState currentState();

private:
    float evaluate(float t);

    float m_startValue;
    float m_change;
    float m_currentValue;

    unsigned long m_startTime;
    unsigned long m_pauseElapsedValue;

    float m_duration;

    animationState m_state;

    EaseFunction easeFunction;
};

#endif
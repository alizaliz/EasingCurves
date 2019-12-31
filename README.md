# EasingCurves
Easing library for Arduino. 
Wrapper and implementation of Robert Penners easeing functions : http://robertpenner.com/easing/

Use this library add vibrance to animations - LED fade, servo movements etc...

![](http://vitiy.info/wp-content/uploads/2014/11/Screenshot-2014-11-27-16.22.22.png)

# BASIC EXAMPLE

```cpp
/* 
 DESCRIPTION
 ====================
 Fade LED with sine easing curve.
 */
#include <EasingCurves.h>

#define LED_PIN LED_BUILTIN

// Instantiate an EasingCurves object
EasingCurves ease = EasingCurves(SINE_IN, 0, 254, 5000);

bool forward = true;

void setup()
{
  //Setup the LED :
  pinMode(LED_PIN, OUTPUT);
  ease.start();
}

void loop()
{

  if (ease.isActive())
  {
    int level;
    if (forward)
    {
      level = ease.getValue();
    }
    else
    {
      level = ease.getValueOneMinus();
    }
    analogWrite(LED_PIN, level);
  }
  else
  {
    ease.restart();
    forward = !forward;
  }
}
```

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
  switch (ease.currentState())
  {
    case ACTIVE: // Animate while active
      int level;
      if (forward)
      {
        level = ease.getValue(); // Forward on curve
      }
      else
      {
        level = ease.getValueOneMinus(); // Backward on curve
      }
      analogWrite(LED_PIN, level); 
      break;
    case INACTIVE: // Restart and flip direction
      ease.restart();
      forward = !forward;
      break;
  }
}

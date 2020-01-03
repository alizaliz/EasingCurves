/* 
 DESCRIPTION
 ====================
 Pause and Resume an easing curve.
 */
#include <EasingCurves.h>

#define LED_PIN LED_BUILTIN

// Instantiate an EasingCurves object
EasingCurves ease = EasingCurves(LINEAR_IN, 0, 254, 4000);

int timings[] = {1000, 2000, 3000};
int timing = 0;

unsigned long startTime;

void setup()
{
  //Setup the LED :
  pinMode(LED_PIN, OUTPUT);
  ease.start();

  startTime = millis();
}

void loop()
{
  if(millis() - startTime > timings[timing])
  {
    ++timing;
    switch(ease.currentState())
    {
      case ACTIVE:
        ease.pause();
        break;
      case PAUSED:
        ease.resume();
        break;
      case INACTIVE:
        ease.restart();
        break;
    }
    } 
    if(timing > 2)
    {
      timing = 0;
      startTime = millis();
    }
  }
  
  if (ease.currentState() == ACTIVE)
  {
    int level = ease.getValue();
    analogWrite(LED_PIN, level);
  }
}

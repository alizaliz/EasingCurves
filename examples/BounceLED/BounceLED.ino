
/* 
 DESCRIPTION
 ====================
 Simple example of the EasingCurves library that eases/fades LED when a button is pressed.
 */
// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <EasingCurves.h>
#include <Bounce2.h>

#define BUTTON_PIN 4
#define LED_PIN LED_BUILTIN

// Instantiate a Bounce object
Bounce debouncer = Bounce();

EasingCurves ease = EasingCurves(BOUNCE_IN, 0, 254, 2000);

void setup()
{

  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5); // interval in ms

  //Setup the LED :
  pinMode(LED_PIN, OUTPUT);
  ease.start();
}

void loop()
{
  // Update the Bounce instance :
  debouncer.update();

  // Update LED based on curve
  if (ease.isActive())
  {
    analogWrite(LED_PIN, constrain(ease.getValue(), 0, 254));
  }

  // Turn on or off the LED as determined by the state :
  if (debouncer.rose())
  {
    ease.start();
    delay(100);
    Serial.println("Start");
  }
}

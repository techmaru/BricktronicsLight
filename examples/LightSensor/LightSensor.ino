// Bricktronics Example: Light sensor
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Light Sensor.
//
// Light sensor readings are taken every 100 milliseconds, and
// printed out over the serial console. Be sure to set your serial
// console to 115200 baud. The light sensor library reports the measured
// light value with a unitless value between 0 (very dim) and
// 1023 (very bright). We can also set a calibration range, and the
// library can scale the raw value to a range of 0-100 based on the
// calibration values. Both these values are printed to the serial console.
//
// We also flash the Light Sensor's LED between each sample. We've found
// that the light doesn't help much in distinguishing between light and dark
// surfaces, but your mileage may vary, so give it a try.


// Include the Bricktronics Light sensor library
#include <BricktronicsLight.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port for the Light sensor (SENSOR_1 through SENSOR_4) below.
// For ports 3 and 4, use the jumpers to connect pins 1-2 and 4-5.
//
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
//#include <BricktronicsShield.h>
//BricktronicsLight ls = BricktronicsLight(BricktronicsShield::SENSOR_1);

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port for the light sensor (SENSOR_1 through SENSOR_4) below.
// Use the jumpers to connect pins 1-2 and 4-5 for the light sensor.
//
//#include <BricktronicsMegashield.h>
//BricktronicsLight ls = BricktronicsLight(BricktronicsMegashield::SENSOR_4);

// 3. With a Bricktronics Breakout board - No additional includes needed, just
// update the pin assignments in the BricktronicsLight constructor below.
//
// The BricktronicsLight() arguments are: inputPin, lightPin
// There is one consideration for pin assignments:
// A. inputPin needs to be an analog pin
//
//BricktronicsLight ls = BricktronicsLight(A0, 12);


void setup() 
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  //BricktronicsShield::begin();

  // Initialize the light sensor connections
  ls.begin();
}


void loop()
{
  Serial.print("Raw value: ");
  Serial.print(ls.value());
  Serial.print(" - scaled value: ");
  Serial.println(ls.scaledValue());

  // Flash the light sensor's built-in led, just for fun
  ls.setFloodlightAlways(true);
  delay(100);
  ls.setFloodlightAlways(false);

  delay(500);
}

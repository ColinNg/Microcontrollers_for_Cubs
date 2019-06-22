/* Simple test of the functionality of the photo resistor

Connect the photoresistor one leg to pin 0, and pin to +5V
Connect a resistor (around 10k is a good value, higher
values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).

----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------
*/

int lightPin = 1;  //define a pin for Photo resistor (1 = P2, 2 = P4, 3 = P3, 0 = P5)
int ledPin=1;     //define a pin for LED

void setup()
{
  pinMode( ledPin, OUTPUT );
}

void loop()
{
  analogWrite(ledPin, analogRead(lightPin)/40);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
  delay(10); //short delay for faster response to light.
}

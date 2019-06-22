/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 0;
int greenPin = 1;
int bluePin = 4;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{ 
  setColor(64, 64, 36);  // white
  delay(1000);
  setColor(192, 0, 0);  // red
  delay(1000);
  setColor(192, 16, 0);  // orange
  delay(1000);
  setColor(128, 32, 0);  // yellow
  delay(1000);  
  setColor(0, 48, 0);  // green
  delay(1000);
  setColor(0, 16, 32);  // blue
  delay(1000);
  setColor(6, 0, 32);  // indigo
  delay(1000);
  setColor(32, 0, 32 );  // violet
  delay(1000);

  setColor(64, 0, 32);  // magenta
  delay(1000);
  setColor(0, 48, 16);  // aqua
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

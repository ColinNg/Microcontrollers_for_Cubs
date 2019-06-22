int meter = 1;

void setup()
{
  pinMode(meter, OUTPUT);
}

void loop()
{
  setMeter(0);
  delay(1000);
  setMeter(100);
  delay(1000);
  setMeter(10);
  delay(1000);
  setMeter(90);
  delay(1000);  
  setMeter(20);
  delay(1000);
  setMeter(80);
  delay(1000);
  setMeter(30);
  delay(1000);
  setMeter(70);
  delay(1000);
  setMeter(40);
  delay(1000);
  setMeter(60);
  delay(1000);
  setMeter(50);
  delay(1000);
}

void setMeter(int percent)
{
  int level = percent * 0.0825; 
  analogWrite(meter, level);
}

int count;

void setup() 
{
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, INPUT);
  
}
 
void loop()
{
  if (!digitalRead(13))
  {
    ++count;
  }
  analogWrite(10, map((count%100), 0, 100, 255, 0));
  analogWrite(11, map((count%100), 0, 100, 0, 255));
  analogWrite(12, map((count%200), 0, 100, 255, 0));
  delay(10);
}

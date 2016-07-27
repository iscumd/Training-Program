// the setup function runs once when you press reset or power the board

int count;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  ++count;
  delay(1000);

  //// stoplight // **************************************
  //red
  if (count % 10 == 2)
  {
    digitalWrite(11, LOW); 
    digitalWrite(12, LOW); 
    digitalWrite(13, HIGH); 
  }
    //yellow
  if (count % 10 == 0)
  {
    digitalWrite(11, LOW); 
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW); 
  }
    //green
  if (count % 10 == 6)
  {
    digitalWrite(11, HIGH); 
    digitalWrite(12, LOW); 
    digitalWrite(13, LOW);  
  }

  
  
//// Red White Blue // **************************************
  // red
  if (count % 4 == 0)
  {
    digitalWrite(1, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
  }

  // white
    if (count % 4 == 1)
  {
    digitalWrite(1, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
  }
  // blue
    if (count % 4 == 2)
  {
    digitalWrite(1, LOW); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH);
  }
  // off
    if (count % 4 == 3)
  {
    digitalWrite(1, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH);
  }
  
}


















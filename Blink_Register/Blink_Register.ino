
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(57600); 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
}

int incomingByte = 0;

// the loop function runs over and over again forever
void loop() {
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);                       // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1500);                       // wait for a second
  
  /*if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }*/
  
}

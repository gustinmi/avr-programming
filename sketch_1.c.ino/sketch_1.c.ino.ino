/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int potPinGorDol = 1;    // select the input pin for the potentiometer
int valGorDol = 0;

int potPin = 2;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor


// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);
 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  
}

// the loop function runs over and over again forever
void loop() {

  Serial.println("Hello from serial every 5 seconds");
  delay(5000);

  /*val = analogRead(potPin);    // read the value from the sensor
  valGorDol = analogRead(potPinGorDol);    // read the value from the sensor
  
  Serial.println("Valus levodesno : ");
  Serial.println(val);

  Serial.println("Valus gor dol : ");
  Serial.println(valGorDol);

  delay(500);
  */
}

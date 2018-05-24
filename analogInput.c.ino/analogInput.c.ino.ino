/*
    Reading 2 potentiometers from RqadioControlled joystick. 
*/

int potPinGorDol = 1;    // select the input pin for the potentiometer
int valGorDol = 0;

int potPin = 2;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor


// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);
 
  // Just light up led for test 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
}

// the loop function runs over and over again forever
void loop() {

  Serial.println("Hello from serial every 5 seconds");
  delay(5000);

  val = analogRead(potPin);    // read the value from the 1st potentiometer 
  valGorDol = analogRead(potPinGorDol);    // read the value from 2nd potentiometer 

  // print out values
  
  Serial.println("Valus levodesno : ");  
  Serial.println(val);

  Serial.println("Valus gor dol : ");
  Serial.println(valGorDol);

}

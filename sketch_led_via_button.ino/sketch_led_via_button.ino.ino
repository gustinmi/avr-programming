
const int ledPin = 2;
const int buttonPin = 6;     // the number of the pushbutton pin

// variables will change:
int buttonState;         // variable for reading the pushbutton status
int ledState = HIGH;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  Serial.println("Startmilis: ");
  Serial.println(millis());
  Serial.println("New state: ");
  Serial.println(buttonState);
}

void loop() {
  
  int reading = digitalRead(buttonPin);
  //Serial.println("Reading milis : ");
  //Serial.println(reading);
  
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    Serial.println("Reading milis : ");
    Serial.println(reading);
    Serial.println("Lastdebounce: ");
    Serial.println(lastDebounceTime);
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      Serial.println("New state: ");
      Serial.println(buttonState);

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }

      
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
  
  
  
  



  
  
 
}

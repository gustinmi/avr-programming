#define PRODUCTION 1
volatile byte val = 0; 

// interface to 4051BE chip
const int commonPin = 3;    // Input pin common
const int pin_a = 4; // ABC INPUT OF 4051
const int pin_b = 5; // ABC INPUT OF 4051
const int pin_c = 2; // ABC INPUT OF 4051

void setup() {
  Serial.begin(9600);
  Serial.println("setup");

    // set atmega to chip pin connections
  pinMode(commonPin, INPUT);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
}

void loop() {

  int i = 0;
  int counter = 0;
  bool buttonState = LOW;
  byte valCopy = val;
  
  for(i = 0; i<4; i++, counter++){
    valCopy = val;
    // button channel select lower 4
    pinMode(commonPin, INPUT);
    digitalWrite(pin_c, LOW);  // select lower 4 input channels 1-4    
    digitalWrite(pin_b, (counter & (1 << 1)) > 0 ? HIGH :  LOW);  
    digitalWrite(pin_a, (counter & (1 << 0)) > 0 ? HIGH :  LOW);
    delay(1);    
    
    bool currentBtnState = val & (1<<i); // preberi trenutno stanje iz registra

    // 15 milisekund prebiraj gumb
    int y;
    for(y=0;y<10;y++){
      buttonState = digitalRead(commonPin);
      delay(1);    
    }
    
    if (buttonState == HIGH) {
      Serial.println("toggle state");
      if (currentBtnState == HIGH)
        val &=~(1<<i); // clear bit
      else
        val |= 1 << i; // set bit
    }  
  
    if (valCopy != val){

      digitalWrite(pin_c, HIGH); // select top 4 channels
      pinMode(commonPin, OUTPUT); // set commonPin for output
      delay(1); // wait few cycles

      if (currentBtnState == HIGH)
        digitalWrite(commonPin, LOW); 
      else
        digitalWrite(commonPin, HIGH);   
      
    }
    
  } // end of for
  
  delay(80); 
  printBinary(valCopy, false);
  Serial.print(" ");  
  printBinary(val, true);

  
} // end of loop


void led(){
  
  
}


void printBinary(byte b, bool newLine){
  for(int i = 7; i >= 0; i--)
    Serial.print(bitRead(b,i));
  if(newLine == true) Serial.println();  
}



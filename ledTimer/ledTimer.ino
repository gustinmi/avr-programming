//#define DEBUG 0
#define PRODUCTION 0
volatile int i = 0; // 0000 0000
volatile int j = 0; // 0000 0000
uint8_t btnPressed = 0;
volatile byte val = 0; 
volatile int executed = 0;
volatile bool mutex = false;

// interface to 4051BE chip
const int commonPin = 3;    // Input pin common
const int pin_a = 4; // ABC INPUT OF 4051
const int pin_b = 5; // ABC INPUT OF 4051
const int pin_c = 2; // ABC INPUT OF 4051

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  i++;
}

ISR(TIMER1_COMPB_vect)          // timer compare interrupt service routine
{
  
  if (mutex == false){
    //Serial.print(".");  
    mutex = true;
    digitalWrite(pin_c, HIGH); // select top 4 channels
    pinMode(commonPin, OUTPUT); // set commonPin for output

    bool currentBtnState = val & (1<<j); // preberi trenutno stanje iz registra
    
    digitalWrite(commonPin, currentBtnState); // select top 4 channels
    
    digitalWrite(pin_b, (j & (1 << 1)) > 0 ? HIGH :  LOW);  
    digitalWrite(pin_a, (j & (1 << 0)) > 0 ? HIGH :  LOW);

    mutex = false;
  }

  if(j<4) j++;
  else j=0;
}


void setup() {

  Serial.begin(57600);
  Serial.println("setup");
  
  TCCR1A = 0; // clear Timer control H register
  TCCR1B = 0; // clear Timer control L register

  TCNT1 = 0; // clear timer0 value 
  //TIMSK1 |= (1 << TOIE1);  // enable overflow interrupt
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1B);  // enable timer compare interrupt
  
  OCR1A = 1300; // vrednost za compare match overflow
  OCR1B = 512; // vrednost za compare match overflow
  TCCR1B |= (1 << WGM12); // CTC mode
  TCCR1A |= (1 << WGM12); // CTC mode

  // set atmega to chip pin connections
  pinMode(commonPin, INPUT);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);

  TCCR1B |= (1 << CS12); // 256 prescaler
  
  //interrupts(); 
}

void loop() {
    
    while(executed != i)
      ; // wait until counter increments for 1 step

    if(mutex==true) return;

    mutex = true;
    bool buttonState = LOW;
    byte valCopy = val;

    valCopy = val;
    // button channel select lower 4
    pinMode(commonPin, INPUT);
    digitalWrite(pin_c, LOW);  // select lower 4 input channels 1-4    
    digitalWrite(pin_b, (i & (1 << 1)) > 0 ? HIGH :  LOW);  
    digitalWrite(pin_a, (i & (1 << 0)) > 0 ? HIGH :  LOW);
    
    bool currentBtnState = val & (1<<i); // preberi trenutno stanje iz registra
    buttonState = digitalRead(commonPin);
    
    if (buttonState == HIGH) {
      if (currentBtnState == HIGH)
        val &=~(1<<i); // clear bit
      else
        val |= 1 << i; // set bit
    } 

    mutex = false;
    
    //printBinary(valCopy, false);
    //Serial.print(".");  
    printBinary(val, true);

    executed++;
    i=0; 
    //Serial.print(i); 
    
    if(executed>=4){
      executed = 0;
      i=0;
    } 
 

}

void printBinary(byte b, bool newLine){
  #ifdef DEBUG
  for(int i = 7; i >= 0; i--)
    Serial.print(bitRead(b,i));
  if(newLine == true) Serial.println();  
  #endif
  return;
}


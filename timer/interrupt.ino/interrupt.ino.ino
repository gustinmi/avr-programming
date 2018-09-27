#define ledPin 5

void setup()
{
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage 

  // initialize timer1 
  noInterrupts();           // disable all interrupts (before 16 bit access, because interrupt can occur betweeen 2 reads to High and Low 8 bits of 16bit )
  
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 34286;            // preload timer 65536-16MHz/256/2Hz
  
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  
  interrupts();             // enable all interrupts
}

ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  //Serial.println("Hello from serial every 5 seconds"); 
  TCNT1 = 34286;            // preload timer
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}

void loop()
{
  // if you put "timer" routine here, with delay, it will not be precise, because the execution time for the code inside loop will always be added 
}


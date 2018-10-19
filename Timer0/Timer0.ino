volatile int i = 0;

void setup() {

  Serial.begin(115200);
  Serial.println("setup"); 

  TCCR0A = 0; // clear Timer control H register
  TCCR0B = 0; // clear Timer control L register

  /*
   * COM0A0  - set OC0A on compare match
   * WGM01  - CTC MOde
  */
  TCCR0A |= (1<<COM0A0)|(1<<WGM01); // toggle on Compare match
  TCCR0B |= (1<<CS02)|(1<<CS00); // start timer, 1024 prescaler
  DDRD = (1<<DDD6); // output compare pull up activation

}

void loop() {
  i++;
  if(i==10000){
    //Serial.println(TCNT0); // print timer value
    Serial.println("Test 123");
    i=0;
  }
}

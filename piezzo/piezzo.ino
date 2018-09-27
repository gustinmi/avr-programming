int piezoPin = 13;

void setup() {
  // put your setup code here, to run once:

}

volatile int i = 0;

void loop() {

  /*Tone needs 2 arguments, but can take three
    1) Pin#
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */

   if(i<5){
      tone(piezoPin, 444, 200); 
   } 
   
   i++;
   
   delay(1000);
   
}

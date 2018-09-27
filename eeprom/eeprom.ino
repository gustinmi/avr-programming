#include <EEPROM.h>

void setup() {

    Serial.begin(9600); 

  //if (EEPROM.read(0) != 0xAA) {
    EEPROM.write(1, 12);
    EEPROM.write(2, 34);
    EEPROM.write(0, 0xAA);

    Serial.print("Done setup");
  //}else{
    Serial.println("Value is");

    Serial.print(EEPROM.read(0));
  //}

  

}

void loop() {
  // put your main code here, to run repeatedly:

}

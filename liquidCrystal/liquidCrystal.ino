/* 
 * LCD Example
 * LCD R/W pin to ground - A Read/Write (R/W) pin that selects reading mode or writing mode
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/

#include <LiquidCrystal.h>

const int 
  /*
    A register select (RS) pin - controls where in the LCD's memory you're writing data to.
    You can select either the data register, which holds what goes on the screen,
    or an instruction register, which is where the LCD's controller looks for instructions on what to do next.
  */
  rs = 6,  // LCD RS pin to digital pin 12

  /* An Enable pin that enables writing to the registers */
  en = 7,  // LCD Enable pin to digital pin 11

  /* D0-D7 data bits for register (write), or bits from register when reading */
  d4 = 12,   // LCD D4 pin to digital pin 5
  d5 = 11,   // LCD D5 pin to digital pin 4
  d6 = 10,   // LCD D6 pin to digital pin 3
  d7 = 9;   // LCD D7 pin to digital pin 2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(57600);
  Serial.println("setup LCD");

  lcd.begin(16, 2);   // set up the LCD's number of columns and rows:
  lcd.print("hello, world!");
  
  Serial.print("Done lcd");
}


void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);  
  delay(1000);
}

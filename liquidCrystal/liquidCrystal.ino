#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6;

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

LiquidCrystal lcd(rs, en, 2, 3, 10, 13, 9, 8, 7, 6);

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 1);
  // Print a message to the LCD.
  //lcd.print("0");

  Serial.print("Done lcd");
}
volatile int i = 0;
void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(i, 0);
  // print the number of seconds since reset:
  
  String thisString = String(i);
  lcd.print("E");
  i++;
  if (i>16){
    
    lcd.clear();
    i = 0;
  } 
  
  delay(1000);
}

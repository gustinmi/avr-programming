
/* 
 * LCD Example
 * LCD R/W pin to ground - A Read/Write (R/W) pin that selects reading mode or writing mode
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/

/* lyquic crystal LCD display based on HD44780 */
#include <LiquidCrystal.h> 
/* temperature and humudity sensor based on NTC 100K Termistor */
#include "DHT.h"

int digitValue; //  value from the digit input pin void setup ()

const int 

  soundPin = 0,
  
  /* sound sensor */
  sound_dig_pin = 13, // select the input pin for the potentiometer
  
  /* DHT11 Temperature sensor */
  dht11_pin = 8, // pin for DHT11 Temperature sensor
  
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

#define DHTTYPE DHT11

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(dht11_pin, DHT11);

void setup() {
  Serial.begin(57600);
  Serial.println("setup LCD");

  lcd.begin(16, 2);   // set up the LCD's number of columns and rows:
  lcd.print("initializing application ...");
  
  dht.begin();
  pinMode (sound_dig_pin, INPUT); 

  delay(500); // wait with screen
  lcd.clear();
  Serial.print("Done lcd");
}

float h = 0, t = 0, f = 0;

bool soundDetected = false;
int lastValue = 0;
bool soundNotifiCleared = true;

void loop() {
  bool soundNotify = false;
  int value = analogRead(soundPin); //read the value of A0
  if(lastValue != value){
    if ((lastValue = 0 || lastValue > value + 5) || (lastValue < value - 5)) { // tolerance
      lastValue = value;
      soundNotify = true;
    }
  }
  
  Serial.println(value);

  soundDetected = digitalRead(sound_dig_pin);
    
  bool changed = false;
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float hCurr = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tCurr = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float fCurr = dht.readTemperature(true);

  // init the first time
  if (h != hCurr){
    h = hCurr;
    changed = true;
  }
  if (t != tCurr){
    t = tCurr;
    changed = true;
  }
  if (f != fCurr){
    f = fCurr;
    changed = true;
  }
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //int chk = DHT.read11(dht11_pin);
  if (changed == true){
    lcd.setCursor(0,0); 
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print("%");
  }

  //lcd.setCursor(0,0); 
  if (soundNotify == true){
    lcd.setCursor(15, 0);
    lcd.print("*");
    soundNotifiCleared == false;
  }else {

    if (soundNotifiCleared == false){ // only clear if not cleared before
      lcd.setCursor(15, 0);
      lcd.print(".");
      soundNotifiCleared = true;
    } 
    
  }
  
  delay(300);
  
}

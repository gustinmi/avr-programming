#include <Wire.h>

#define EEPROM_ADR 0x51 //55
#define MAX_I2C_WRITE 16
byte tempStore[MAX_I2C_WRITE]; 
byte counter = 0;

void setup() {

  //Start the I2C Library
  Wire.begin();
  Wire.setClock(400000); // 400 KHZ

  //Start the serial port
  Serial.begin(57600);

  // Fill the test data
  for (counter = 0; counter < MAX_I2C_WRITE; counter++){
    tempStore[counter] = counter;
  }

  long currentSpot = 0;
  writeEEPROMPage(currentSpot);

  delay(1000);
  for (long x = 0 ; x < 0x10 ; x++) //Read all 131,071 bytes from EERPOM
  {
    byte val = readEEPROM(x);
    //Serial.println(val);
  }
}

void loop(){

  

  //Here is where we'll keep track of where in the memory we're writing
  //long currentSpot = 0;
  //byte counter = 0;

  
  
    //Once we've collected a page worth, go ahead and do 
    //a page write operation
  //  writeEEPROMPage(currentSpot);
//    counter = 0; //Reset
//    currentSpot += MAX_I2C_WRITE;

    

}

void resetWithCounter()
{

  long timerReset = 0;

  while (1){
    timerReset = millis();
    if (millis() - timerReset > 2000)
    {
      //Serial.println(currentSpot);
      timerReset = millis();
    }
  }


    
}



/* This is the 3 step memory reading procedure that
we talked about. First we send the MSB of the address. 
Then we send the LSB of the address. Then we ask for the 
number of bytes that we want to receive. Here, we're 
going 1 byte at a time*/

byte readEEPROM(long eeaddress)
{
  Serial.print("Reading eeprom loc");
  Serial.println(eeaddress);
  Wire.beginTransmission(EEPROM_ADR);

  Wire.write((int)(eeaddress >> 8)); // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_ADR, 1);

  byte rdata = 0xFF;
  if (Wire.available()){
    Serial.print("GOT");
    rdata = Wire.read();
    Serial.print(rdata);
  } 
  return rdata;
}



/* This is the 3 step memory writing procedure that
we talked about. First we send the MSB of the address. 
Then we send the LSB of the address. Then we send the 
data that we want to store. */

void writeEEPROMPage(long eeAddress)
{
  Serial.print("EEPROM write");
  Serial.println(eeAddress);
  
  Wire.beginTransmission(EEPROM_ADR);

  Wire.write((int)(eeAddress >> 8)); // MSB
  Wire.write((int)(eeAddress & 0xFF)); // LSB

  //Write bytes to EEPROM
  for (byte x = 0 ; x < MAX_I2C_WRITE ; x++)
    Wire.write(tempStore[x]); //Write the data

  Wire.endTransmission(); //Send stop condition
}

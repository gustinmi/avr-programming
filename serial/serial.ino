void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.print("Starting to listen");
  delay(1000);
}

void loop() {
  
  while (Serial.available())
  {
     byte buff = Serial.read(); //Read this byte into the array
     Serial.print(buff);
  }
  

}

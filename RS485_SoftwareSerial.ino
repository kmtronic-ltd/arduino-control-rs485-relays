#include <SoftwareSerial.h>
const int RS485_Direction = 8;     // the pin of the RS485 control direction (TX/RX)
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(RS485_Direction,OUTPUT); //set pin to output for RS485 control direction (TX/RX)
  digitalWrite(RS485_Direction, HIGH); // set to HIGH level for Transmiting data ( LOW for receive)  
}

void loop() // run over and over
{

  for(uint8_t i=1; i < 9; i++ ){
      KMtronic_Relay_ON(i);
      delay(50);
  }

    for(uint8_t i=1; i < 9; i++ ){
      KMtronic_Relay_OFF(i);
      delay(50);
  }


  KMtronic_Relay_ON(1);
  delay(500);

  KMtronic_Relay_OFF(1);
  delay(500);

  KMtronic_Relay_ON(8);
  delay(500);

  KMtronic_Relay_OFF(8);
  delay(500);

}

void KMtronic_Relay_ON(uint8_t number)
{
  mySerial.write((uint8_t)0xFF);
  mySerial.write((uint8_t)number);
  mySerial.write((uint8_t)0x01);
}

void KMtronic_Relay_OFF(uint8_t number)
{
  mySerial.write((uint8_t)0xFF);
  mySerial.write((uint8_t)number);
  mySerial.write((uint8_t)0x00);
}















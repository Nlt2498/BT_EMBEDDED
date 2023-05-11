/*
 * File: Master.ino
 * Author: NGUYEN THANH
 * Date: 5/5/2023
 * Description: This is file for SPI
*/


#define SCK_PIN 4
#define MOSI_PIN 5
#define MISO_PIN 6
#define SS_PIN 7

void setup() {
  // put your setup code here, to run once:
  SPI_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t rev;
  SPI_begin();
  rev = SPI_transfer("a"); //ASCII: 0x61 97 
  SPI_end();
  delay(1);
}

void SPI_setup(){
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, OUTPUT);
  digitalWrite(SCK_PIN, HIGH);
  pinMode(SCK_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);  
  pinMode(SS_PIN, OUTPUT);
  delay(1);
}

void SPI_begin(void){
  digitalWrite(SS_PIN, HIGH); 
}

void SPI_end(void){
  digitalWrite(SCK_PIN, LOW); 
  digitalWrite(SS_PIN, HIGH); 
}

uint8_t SPI_transfer(uint8_t byte_out)
{
  uint8_t byte_in = 0; //0000.0000
  uint8_t ibit, res;
  //1000.0000(0x80) -> 0100.0000 -> 0010.0000 .... -> 0000.0001 -> 0000.0000(stop condition)
  for(ibit=0x80; ibit>0; ibit = ibit>>1) //ibit=1000.0000
  {
    res = byte_out & ibit; //(1=true, 0=false)
    digitalWrite(MOSI_PIN, res);
    delayMicroseconds(25);
    digitalWrite(SCK_PIN, HIGH);
  
    if(digitalRead(MISO_PIN) == HIGH){
      byte_in = byte_in | ibit; //0000.0000 | 1000.0000 = 1000.0000
      delayMicroseconds(25);
      digitalWrite(SCK_PIN, LOW);
    }
  }
  return byte_in;
}

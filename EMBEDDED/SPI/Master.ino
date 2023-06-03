/*
 * File: Master.ino
 * Author: NGUYEN THANH
 * Date: 5/5/2023
 * Description: This is file for MASTER_SPI using Arduino
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
  uint8_t rev[2];
  SPI_start();
  rev[0] = SPI_transfer('X');  //0x58
  rev[1] = SPI_transfer('Y');  //0x59
  SPI_end();
  Serial.println("Master: " + String((char)rev[0])); 
  Serial.println("Master: " + String((char)rev[1]));
  delay(1000);
}


/*
 * Function: SPI_setup
 * Description: This function use for initialize, configure pins for MISO, MOSI, SS, SCK
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/

void SPI_setup(){
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, OUTPUT);
  digitalWrite(SCK_PIN, HIGH);
  pinMode(SCK_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);  
  pinMode(SS_PIN, OUTPUT);
  delay(1);
}

/*
 * Function: SPI_begin
 * Description: This function use for starting SPi signal
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/

void SPI_begin(void){
  digitalWrite(SS_PIN, HIGH); 
}

/*
 * Function: SPI_stop
 * Description: This function use for stopping SPi signal
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/
void SPI_end(void){
  digitalWrite(SCK_PIN, LOW); 
  digitalWrite(SS_PIN, HIGH); 
}

/*
 * Function: SPI_transfer
 * Description: This function use for Master to transfer data SPI. MODE 0 bitOrder MSB
 * Input:
 *   data - data want to send
 * Output:
 *   return: data read via SPI
*/
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

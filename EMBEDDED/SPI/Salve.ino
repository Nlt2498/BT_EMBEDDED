/*
 * File: Salve.ino
 * Author: NGUYEN THANH
 * Date: 5/5/2023
 * Description: This is file for SALVE_SPI using Arduino
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
  rev[0] = SPI_transfer('9'); //0x38
  rev[1] = SPI_transfer('8'); //0x39
  Serial.println("Salve: " + String((char)rev[0]));
  Serial.println("Salve: " + String((char)rev[1]));
}

/*
 * Function: SPI_setup
 * Description: This function use for initialize, configure pins for MISO, MOSI, SS, SCK
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/

void SPI_setup(void)
{
  pinMode(SCK_PIN, INPUT);
  pinMode(MOSI_PIN, INPUT);
  pinMode(SS_PIN,INPUT);
  pinMode(MISO_PIN, OUTPUT);  
}


/*
 * Function: SPI_transfer
 * Description: This function use for Salve to transfer data SPI. MODE 0 bitOrder MSB
 * Input:
 *   data - data want to send
 * Output:
 *   return: data read via SPI
*/

//CPOL = 0. CPHASE = 0; MSB(FRIST)
uint8_t SPI_transfer(uint8_t byte_out)
{
  uint8_t byte_in = 0; // 0000.0000
  uint8_t ibit,res;
  while(digitalRead(SS_PIN)== HIGH); //Waiting SS Low
  for(ibit=0x80; ibit>0; ibit=ibit>>1)//1000.000
  {
    res = byte_out & ibit; 
    digitalWrite(MISO_PIN, res);
    while(digitalRead(SCK_PIN) == LOW);

    if(digitalRead(MOSI_PIN)== HIGH) 
      byte_in = byte_in | ibit;
    while(digitalRead(SCK_PIN) == HIGH);

  }
  return byte_in;
}

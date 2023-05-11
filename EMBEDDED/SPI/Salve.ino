

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
  rev = SPI_transfer('A'); //ASCI: 65 0x41
}

void SPI_setup(void)
{
  pinMode(SCK_PIN, INPUT);
  pinMode(MOSI_PIN, INPUT);
  pinMode(SS_PIN,INPUT);
  pinMode(MISO_PIN, OUTPUT);  
}

//CPOL = 0. CPHASE = 0; MSB(FRIST)
uint8_t SPI_transfer(uint8_t byte_out)
{
  uint8_t byte_in = 0; // 0000.0000
  uint8_t ibit,res;
  while(digitalRead(SS_PIN)== HIGH); 
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

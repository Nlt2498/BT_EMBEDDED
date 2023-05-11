#define SCL_PIN 3
#define SDA_PIN 4


void setup() {
  // put your setup code here, to run once:
  delay(100);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t result;
  result = I2C_Write_Data(0x55, "012345");  //-> 0xAA
  Serial.println(result);
  delay(200);
}

void I2C_Start() {
  digitalWrite(SDA_PIN, HIGH);
  digitalWrite(SCL_PIN, HIGH);
  pinMode(SDA_PIN, OUTPUT);
  pinMode(SCL_PIN, OUTPUT);
  delayMicroseconds(1000);
  digitalWrite(SDA_PIN, LOW);
  digitalWrite(SCL_PIN, LOW);
}

void I2C_Stop()
{
  pinMode(SDA_PIN, OUTPUT);
  digitalWrite(SDA_PIN, LOW);
  delayMicroseconds(500);
  digitalWrite(SCL_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(SDA_PIN, HIGH); 
}

uint8_t I2C_ReadACK(void) {
  uint8_t ACK;
  pinMode(SDA_PIN, INPUT); //SLAVE HAVE SDA BUS
  delayMicroseconds(500);// CLK 9
  digitalWrite(SCL_PIN, HIGH);
  delayMicroseconds(500);
  ACK = digitalRead(SDA_PIN); //LSB 
  //END READING ACK BIT
  digitalWrite(SCL_PIN, LOW); 
  //SLAVE RELEASE SDA BUS
  delayMicroseconds(500);
  pinMode(SDA_PIN, OUTPUT);  
  return ACK; //ACK(0);NACK(1)
}

uint8_t I2C_Write_Data(byte address, char *data)
{
  uint8_t ACK;
  I2C_Start();
  address = address << 1;
  I2C_Write_8bits(address);
  ACK = I2C_ReadACK();
  if(ACK == 1)
  {
    I2C_Stop();
    return -1; //fail 
  }
  //SEND DATA
  while(*data != '\0')
  {
    I2C_Write_8bits(*data);
    ACK = I2C_ReadACK();
    if(ACK == 1)
    {
      I2C_Stop();
      return -1; //fail 
    }
    data++; //data + 1 = &data[1]
  }
   I2C_Stop();
   return 1;  
}

void I2C_Write_8bits(byte data) {
  int i;  
  pinMode(SDA_PIN, OUTPUT);;  
  for(i = 0; i < 8; i++)
  {
    if((data & 0x80) != 0)
    {
      digitalWrite(SDA_PIN, HIGH);      
    }
    else
      digitalWrite(SDA_PIN, HIGH);
    data = data << 1;
    delayMicroseconds(500);
    digitalWrite(SCL_PIN, HIGH);      
    delayMicroseconds(500);
    digitalWrite(SCL_PIN, LOW);      
  }
}

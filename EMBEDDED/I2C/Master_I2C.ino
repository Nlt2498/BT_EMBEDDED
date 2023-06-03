/*
 * File: Master.ino
 * Author: NGUYEN THANH
 * Date: 5/5/2023
 * Description: This is file for MASTER_I2C using Arduino
*/

#define SCL_PIN 3
#define SDA_PIN 4


void setup() {
  // put your setup code here, to run once:
  delay(100);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //MASTER READ DATA FROM SLAVE---------------------------
  byte rev[20]={0};
  int8_t res;
  res = I2C_ReadData(0x13, rev, 7);
  if(res==1){
    Serial.print("Read ok: ");
    Serial.println(String((char*)rev));
  }else if(res==-1){
    Serial.println("Read fails: ");
  }
  delay(1000);

  
  //MASTER SEND DATA TO SLAVE------------------------------------
  int8_t result;
  result = I2C_WriteData(0x13,"[M]12345.:)"); // S AB A 31 A 32 A 33 A 34 A 35 A P,
  // 0x56 = 1010.1100
  Serial.println(result);
  delay(1000); 
}

/*
 * Function: I2C_start
 * Description: This function use for starting I2C signal
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/

void I2C_Start() {
  digitalWrite(SDA_PIN, HIGH);
  digitalWrite(SCL_PIN, HIGH);
  pinMode(SDA_PIN, OUTPUT);
  pinMode(SCL_PIN, OUTPUT);
  delayMicroseconds(1000);
  digitalWrite(SDA_PIN, LOW);
  digitalWrite(SCL_PIN, LOW);
}

/*
 * Function: I2C_stop
 * Description: This function use for stopping I2C signal
 * Input:
 *  input: none
 * Output:
 *  return: none 
*/

void I2C_Stop()
{
  pinMode(SDA_PIN, OUTPUT);
  digitalWrite(SDA_PIN, LOW);
  delayMicroseconds(500);
  digitalWrite(SCL_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(SDA_PIN, HIGH); 
}

/*
 * Function: I2C_ReadACK
 * Description: This function use for reading ACK signal from Salve about
 * Input:
 *  input: none
 * Output:
 *  return: 1 bit ACK 
*/

uint8_t I2C_ReadACK(void) {
  uint8_t ACK;
  pinMode(SDA_PIN, INPUT);  //SLAVE HAVE SDA BUS
  delayMicroseconds(500);   // CLK 9
  digitalWrite(SCL_PIN, HIGH);
  delayMicroseconds(500);
  ACK = digitalRead(SDA_PIN); //LSB 
  //END READING ACK BIT
  digitalWrite(SCL_PIN, LOW); 
  //SLAVE RELEASE SDA BUS
  delayMicroseconds(500);
  pinMode(SDA_PIN, OUTPUT);  
  return ACK;   //ACK(0); NACK(1)
}

/*
 * Function: I2C_Write_Data
 * Description: This function use for MaSter to transfer data I2C.
 * Input:
 *   data - data want to send and adrress
 * Output:
 *   return: 1 Success or -1 Fail
*/

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


/*
 * Function: I2C_Write_8bits
 * Description: This function use for write 8 bit data.
 * Input:
 *   data - data want to send
 * Output:
 *   return: none
*/

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

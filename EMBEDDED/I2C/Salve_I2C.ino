#define SCL_PIN 3
#define SDA_PIN 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte rev[20]={0};
  int8_t s, c;
  
  s = I2C_begin(0x13); //waiting until MASTER (until meet START CONDITION)----------
  if(s == 0){  //Master writes - Slave reads
    I2C_read(rev, 11);
    Serial.println("Master wants to write data.");
    Serial.println(String((char *)rev));
  }
  else if(s == 1) { //Master reads - Slave writes
    c = I2C_write("[S]abcd"); //S AA A 61 A 62 A 63 A 64 A P
    Serial.println("Master wants to read data.");
    if(c==1)          Serial.println("Write successfully!");
    else if(c==-1)    Serial.println("Fail to write!(Master not respond)");
    else              Serial.println("Something wrong???");  
  } 
  else if(s == 2)
   Serial.println("Wrong address.(Not my Address)");
  else
   Serial.println("Other uncontrolled case!!!");
}

uint8_t I2C_begin(byte address)
{
  //(1) Right Address 
  // w: return 0
  // r: return 1
  //(2) Wrong Address: return 2
  //(3) NOT START CONDITION: LOOP AGAIN....
   uint8_t data=0, i, rw=0;
   while(true)
   {
    pinMode(SDA_PIN, INPUT);
    pinMode(SCL_PIN, INPUT);
    while( (digitalRead(SDA_PIN) != 1)||(digitalRead(SCL_PIN) !=1) );//waiting for ideal condition-----------
    while( digitalRead(SDA_PIN) == 1 );//waiting until SDA=0
    delayMicroseconds(25); 
    if(digitalRead(SCL_PIN) == 1) // This is the START CONDITION--------
    {
      while(digitalRead(SCL_PIN) == 1) ;//waiting until SCL=0

      //read ADDRESS, R(1)/W(0).------------------
      for(i=0;i<8;i++) {
        while(digitalRead(SCL_PIN)== 0); //waiting until SCL=1
        data = (data<<1) | digitalRead(SDA_PIN);
        while(digitalRead(SCL_PIN)== 1); //waiting until SCL=0
      }
      //data = aaaa.aaaw
      rw = data & 1; //aaaa.aaaw & 0000.0001
      data = data>>1; //aaaa.aaaw>>1 = 0aaa.aaaa
      if(data==address) //it's me.
      {
        //send ACK to Master.---------------------
        I2C_SendACK();
        return rw;
      }else //this address is not me.
      {
        return 2;      
      }
    }
    else //No, it's not the Start Condition....:( 
    {}
   }   
}

byte I2C_ReadByte(void)
{
  byte data, i;
  pinMode(SDA_PIN, INPUT);
  pinMode(SCL_PIN, INPUT);
  //read 8bit data
  for(i=0;i<8;i++) {
   while(digitalRead(SCL_PIN)==0) ; //waiting until SCL=1
   data = (data<<1) | digitalRead(SDA_PIN);
   while(digitalRead(SCL_PIN)==1); //waiting until SCL=0
  }
  //SUCCESS to receive all 8bit data (7address+1r/w) (8bitdata)
  I2C_SendACK();
  return data;
}

void I2C_SendACK(void)
{
   //send ACK to Master.---------------------
   //SUCCESS to receive all 8bit data (7address+1r/w) (8bitdata)
   pinMode(SDA_PIN, OUTPUT);
   digitalWrite(SDA_PIN, LOW);
   while(digitalRead(SCL_PIN)==0); //waiting until SCL=1
   while(digitalRead(SCL_PIN)==1); //waiting until SCL=0
   pinMode(SDA_PIN, INPUT);// SHOULD CALL AFTER CALLING "SDA_OUTPUT"
}

uint8_t I2C_ReadACK(void)
{
  //return (0): ACK, return(1): NACK
  uint8_t ack;
  pinMode(SDA_PIN, INPUT);
  while(digitalRead(SCL_PIN)== 0); //waiting until SCL=1
  ack = digitalRead(SDA_PIN);
  while(digitalRead(SCL_PIN)==1); //waiting until SCL=0
  return ack;
}


//SLAVE SEND(8BIT/1BYTE) - after MASTER RECEIVES, send back 1 bit ACK.
void I2C_WriteByte(byte data) //write 8 bit. data=8bit (MSB)
{
  int i;
  pinMode(SDA_PIN, OUTPUT);
  for(i=0;i<8;i++)
  {
    //data(0xF0) (11110000)& 0x80(1000.0000) = 1000.0000 (0x80)
    //data(0x0F) (00001111)& 0x80(1000.0000) = 0000.0000   (0)
    if( (data & 0x80) == 0x80 ) {
      digitalWrite(SDA_PIN, HIGH);
    }else {
      digitalWrite(SDA_PIN, LOW);
    }
    data = data << 1;
    while(digitalRead(SCL_PIN)==0); //waiting until SCL=1
    while(digitalRead(SCL_PIN)==1); //waiting until SCL=0
   }

}


void I2C_read(byte *data, uint8_t count)
{
  int i;
  for(i=0;i<count;i++)
  {
    *data = I2C_ReadByte(); // data[0]
     data++;
  }
}

int8_t I2C_write(char *data) //"abc" = 'a' + 'b' + 'c' + '\0'
{
  //return (-1): fail to send.
  //return (+1): write successfully.
  uint8_t ack; //0:ack, 1:nack
  while(*data != '\0')
  {
    I2C_WriteByte(*data);
    ack = I2C_ReadACK();
    if(ack == 1) //Master's not respond!
    { 
      pinMode(SDA_PIN, INPUT);
      return -1; //fail.
    }
    data++;   
  }
  pinMode(SDA_PIN, INPUT);
  return 1;  //success
}

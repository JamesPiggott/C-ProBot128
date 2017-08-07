// Write a 3Byte long float number
 void WriteFloat_24C64(word EE_Adresse, float zahlf)
 {
     float VKSf, NKSf;
     word VKSw;
     byte NKSb;
     word high_byte, low_byte, teiler;

     teiler=256;

     VKSw = zahlf;
     VKSf = VKSw;
     NKSf = zahlf - VKSf;
     NKSb = NKSf *100.0;

     high_byte = VKSw / teiler;
     low_byte  = VKSw % teiler;

     Write_24C64(EE_Adresse,   high_byte);
     Write_24C64(EE_Adresse+1, low_byte);
     Write_24C64(EE_Adresse+2, NKSb);
 }


//Read a 3Byte long float number
 float ReadFloat_24C64(word EE_Adresse)
 {
     float zahlf;
     word VKSw;
     byte NKSb;

     VKSw= Read_24C64(EE_Adresse)*256 + Read_24C64(EE_Adresse+1);
     NKSb= Read_24C64(EE_Adresse+2);

     zahlf= VKSw + NKSb/100.0;

     return zahlf;

 }


//Write data to I²C-EEPROM
 void Write_24C64(word Adresse, byte Daten)
 {
     I2C_Start();
     I2C_Write(0xA0);                        //DEVICE ADDRESS : A0
     I2C_Write(Adresse>>8);                  //HIGH word ADDRESS
     I2C_Write(Adresse);                     //LOW word ADDRESS
     I2C_Write(Daten);                       //write Data
     I2C_Stop();
     AbsDelay(5);                            //delay for EEPROM Write Cycle
 }

//Read data to I²C-EEPROM
 byte Read_24C64(word Adresse)
 {
     byte I2C_DATA;

     I2C_Start();
     I2C_Write(0xA0);                        //DEVICE ADDRESS : A0
     I2C_Write(Adresse>>8);                  //HIGH word ADDRESS
     I2C_Write(Adresse);                     //LOW word ADDRESS
     I2C_Start();                            //RESTART
     I2C_Write(0xA1);                        //DEVICE ADDRESS : A1
     I2C_DATA=(I2C_Read_NACK());
     I2C_Stop();
     return I2C_DATA;                        //return I2C Data Register
 }
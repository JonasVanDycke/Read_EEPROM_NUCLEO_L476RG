// #include "mbed.h"
// #include "EEPROM.h"

// using namespace EEPROMDriver;

// Serial pc(USBTX, USBRX);
// I2C i2cbus(I2C_SDA, I2C_SCL); //sda & scl

// int main() {

//     printf("\r\n[Particula] Example of using EEPROM driver");

//     char data[8] = {};  // Amount of bytes in data = 8
//     unsigned int lengthData = sizeof(data); 
//     char buffer[lengthData] = {};
    
//     EEPROMDriver::EEPROM eeprom(&i2cbus);

//     pc.printf("\r\nReading from eeprom");
//     eeprom.read(buffer, lengthData, 0);

//     pc.printf("\r\nPrinting the read data from eeprom to Serial device");
//     pc.printf("\r\n"); 

//     //Uitlezen zonder 0x vooraan
//     for(unsigned int i = 0; i < lengthData; i++){
//         pc.printf("%.2x ", buffer[i]);
//     } pc.printf("\r\n");

//     for(unsigned int i = 0; i < lengthData; i++){
//         pc.printf("0x%.2x ", buffer[i]);
//     } pc.printf("\r\n");


//     while(1) {
//         ThisThread::sleep_for(30000);
//     }

//     return 0;
// }
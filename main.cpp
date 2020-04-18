// Compile with: mbed compile -f 
//           Or: mbed compile -f --toolchain GCC_ARM --target NUCLEO_L476RG
// https://os.mbed.com/forum/helloworld/topic/3827/?page=1#comment-19090
// #include "mbed.h"
// #include <string>

 
// // Read temperature from LM75BD
 
// I2C i2c(I2C_SDA, I2C_SCL);        // sda, scl
 
// const int addr = 0x11;
 
// int main() {
//     char regaddr[1];
//     char readdata[8]; // room for length and 7 databytes
//     char writedata[9]; // room for reg address, length and 7 databytes
//     while (1) {
//         regaddr[0] = 0xE0;
//         i2c.write(addr, regaddr, 1, true);  // select the register, no I2C Stop
//         i2c.read(addr, readdata, 8);        // read the length byte and the 7 databytes

//         wait(1);
    
        

//         regaddr[0] = 0x0000;
//         i2c.write(addr, regaddr, 1);
//         i2c.read(addr, regaddr, 2);
//         printf("Register 0x%x = 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",
//                   regaddr[0],
//                   readdata[0], readdata[1], readdata[2], readdata[3], readdata[4],
//                   readdata[5], readdata[6], readdata[7] );
//         wait(1);


//         //char tmp = (char((regaddr[0]<<8)|regaddr[1]) / 256.0);
//         //printf("Temp = 0x%x\r\n", tmp);
//     }return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include "mbed.h"
// I2C i2c(I2C_SDA, I2C_SCL); //sda, scl 
// Serial pc(USBTX, USBRX); //tx, rx

// const int addr = 0x02; //define the I2C Address - 7 bit address plus 1 on right. This taken from sequence diagram provided. Always seems to be 1 whether R/W. Not sure though

// int main() {
//     char cmd[1]; //command register 
//     char reg0data[7]; //register to hold Register 0 - 7 bytes of info 

//     while (1) { 
//         cmd[0] = 0xE0; //command register - 0xE0 is base address 
//         i2c.write(addr, cmd, 1); //adrress the SM72445, send the reister address 
//         i2c.read(addr, reg0data, 7); //read register contents from SM72445 into reg0data array

//         wait (0.07); //default time suggested

//         //print the data to the screen - register 0 byte1 just to test establishment of comms 
//         float reg0byte1 = reg0data[1]; //first byte of register 0 
//         pc.printf("Register 0 Byte 1 = %.2f\r\n", reg0byte1); 
//         wait(5); 
//     } 
// }
////////////////////////////////////////////////////////////////////////////////////////////
// #include "mbed.h"

// I2C i2c(I2C_SDA, I2C_SCL); //sda = D14, PB_9, I2C_SDA //scl = D15, PB_8, I2C_SCL
// Serial pc(USBTX, USBRX);


// const int addr = 0x0000; // define the correct I2C Address    

// int main() {
//     char regaddr[1];
//     char readdata[8]; // room for length and 7 databytes
//     char writedata[9]; // room for reg address, length and 7 databytes

//     while (1) {
//         regaddr[0] = 0x00;
//         i2c.write(addr, regaddr, 1, true);  // select the register, no I2C Stop
//         i2c.read(addr, readdata, 8);        // read the length byte and the 7 databytes
 
//         // print the data to the screen
//         printf("///////////////////////////////////\r\n");
//         pc.printf("Register1 0x%.4x = 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",
//                   regaddr[0],
//                   readdata[0], readdata[1], readdata[2], readdata[3], 
//                   readdata[4], readdata[5], readdata[6], readdata[7] );
//         pc.printf("Register2 %#.4x = %#x %#x %#x %#x %#x %#x %#x %#x\r\n",
//                   regaddr[0],
//                   readdata[0], readdata[1], readdata[2], readdata[3], 
//                   readdata[4], readdata[5], readdata[6], readdata[7] );
//         wait(1);
 
//          // copy the data, starting with register address
//          writedata[0] = regaddr[0];  // register address
//          writedata[1] = readdata[0]; // length, should be 7
//          writedata[2] = readdata[1]; // byte 1
//          writedata[3] = readdata[2];
//          writedata[4] = readdata[3];
//          writedata[5] = readdata[4];
//          writedata[6] = readdata[5];
//          writedata[7] = readdata[6];
//          writedata[8] = readdata[7]; // byte 7
 
//         // write the data
//         i2c.write(addr, writedata, 9); // select the register, 
//                                        // write the length, write 7 databytes      
//         pc.printf("Register3 0x%x = 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",
//                   writedata[0],
//                   writedata[1], writedata[2], writedata[3], writedata[4],
//                   writedata[5], writedata[6], writedata[7], writedata[8] );
//         pc.printf("Register4 %#x = %#x %#x %#x %#x %#x %#x %#x %#x\r\n",
//                   writedata[0],
//                   writedata[1], writedata[2], writedata[3], writedata[4],
//                   writedata[5], writedata[6], writedata[7], writedata[8] );
//         wait(1);



// //  Uitgang:
// // //////////////////////////////////
// // Register1 0x0000 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
// // Register2 0000 = 0x5f 0x97 0 0x8 0 0 0 0
// // Register3 0x0 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
// // Register4 0 = 0x5f 0x97 0 0x8 0 0 0 0



//   }
// }
////////////////////////////////////////////////////////////////////////////////

#include "mbed.h"
#include "EEPROM.h"

using namespace EEPROMDriver;

Serial pc(USBTX, USBRX);
I2C i2cbus(I2C_SDA, I2C_SCL); //sda & scl

int main(){

    printf("\r\n[Particula] Example of using EEPROM driver");

    //original////////////////////////////////////////////////////
    //char data[] = {0x05,0x61,0x92,0x31,0x04,0x55,0x68,0x7a,0x8b,0xc9,0xa4,0xb9};
    //char data2[] = {0x05,0x64,0x92,0x31,0x04,0x55,0x68,0x7a};
    //char data3[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12};
    //////////////////////////////////////////////////////////////
    char data[8] = {};
    //char data[] = {0x0005,0x0061,0x0092,0x0031,0x0004,0x0055,0x0068,0x007a,0x008b,0x00c9,0x00a4,0x00b9};
    //char data2[32] = {};
    //char data3[64] = {};
    //char data3[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c};

    unsigned int lengthTest = sizeof(data); 
    // unsigned int lengthTest2 = sizeof(data2);
    // unsigned int lengthTest3 = sizeof(data3);
        
    //original////////////////////////////////////////////////////
    char buffer[lengthTest] = {0};
    // char buffer2[lengthTest2] = {0};
    // char buffer3[lengthTest3] = {0};
    //////////////////////////////////////////////////////////////
    //char buffer[lengthTest];
    //char buffer2[lengthTest2];
    //char buffer3[lengthTest3];
    
    EEPROMDriver::EEPROM eeprom(&i2cbus);

    //pc.printf("\r\nWriting data array to eeprom");
    //eeprom.write(data, lengthTest, 0); 
    // eeprom.write(data2, lengthTest2, lengthTest);
    //eeprom.write(data3, lengthTest3, lengthTest2 + lengthTest);

    pc.printf("\r\nReading from eeprom");

    eeprom.read(buffer, lengthTest, 0);
    // eeprom.read(buffer2, lengthTest2, lengthTest);
    // eeprom.read(buffer3, lengthTest3, lengthTest2 + lengthTest);

    pc.printf("\r\nPrinting the read data from eeprom to Serial device");
    pc.printf("\r\n"); 

    //Uitlezen zonder 0x vooraan
    for(unsigned int i = 0; i < lengthTest; i++){
        pc.printf("%.2x ", buffer[i]);
    } pc.printf("\r\n");

    for(unsigned int i = 0; i < lengthTest; i++){
        pc.printf("0x%.2x ", buffer[i]);
    } pc.printf("\r\n");


    // for(unsigned int i = 0; i < lengthTest2; i++){
    //     pc.printf("0x%x ", buffer2[i]);
    // } pc.printf("\r\n");


    // for(unsigned int i = 0; i < lengthTest3; i++){
    //     pc.printf("0x%x ", buffer3[i]);
    // }

    while(1) {
        ThisThread::sleep_for(30000);
    }

    return 0;
}
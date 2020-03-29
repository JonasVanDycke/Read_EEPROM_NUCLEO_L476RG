// Compile with: mbed compile -f --toolchain GCC_ARM --target NUCLEO_L476RG
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

#include "mbed.h"
#include <string>
 
#define RELAY_BOARD_ADDR (0x40)

I2C i2c(I2C_SDA, I2C_SCL);
Serial pc(USBTX, USBRX); //tx, rx
//I2C i2c(I2C_SDA, I2C_SCL);
 
DigitalOut myled(LED1);
 
int main()
{
 
    char data_write[2];
    char data_counter = 0;
    
    data_write[0] = 0x12;
    data_write[1] = 0x02;
     
    while (1) {
        
        i2c.write(RELAY_BOARD_ADDR, data_write, 2, 0);
 
        myled = !myled;

        data_counter++;
        
        data_write[1] = data_counter;
        pc.printf(data_counter + "Register \r\n");
        pc.printf("Register 0x%x 0x%x\r\n",
                  data_write[0],
                  data_write[1]);

        wait(2.0);
    }
 
}
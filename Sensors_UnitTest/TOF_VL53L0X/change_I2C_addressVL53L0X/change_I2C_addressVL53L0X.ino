/**
* @file: Change_I2C_SlaveAddress_VL53L0X.ino
* @date: jun 27, 2024
* @author: AhmedSamy
*
* @brief: Change I2C address for GY-530 VL53L0X module with ESP32 Platform
**/



#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();


// Default address 0x29
/* put any address between 0x29 to 0x7F  */
#define ADDRESS     0x30 
/*****************************************/

void setup() {
  lox.begin(ADDRESS);


  Serial.begin(9600);
  Serial.print("\nAddress is: 0x");
  Serial.println(ADDRESS, HEX);
}

void loop(){
  
}

 
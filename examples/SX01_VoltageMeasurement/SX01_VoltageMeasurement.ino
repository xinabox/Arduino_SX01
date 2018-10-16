/*************************************************************
  This is an example for the SX01
  Analog IN - Max Input 3.3V
  
  You can buy one on our store!
  -----> https://xinabox.cc/products/SX01/
  
  This example measures the input voltage on the SX01
  and displays it on the Serial Monitior
    
  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <arduino-SX01.h>

xSX01 SX01;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

   // Set the I2C Pins for CW01
	#ifdef ESP8266
	  Wire.pins(2, 14);
	  Wire.setClockStretchLimit(15000);
  #endif
  // Start the I2C Communication
  Wire.begin();

  // Start the ☒CHIP Sensor
  SX01.begin();
}

void loop() {
  Serial.println("==============================");
  Serial.println("   SX01 Voltage Measurement");
  Serial.println("==============================");

  float voltage = 0;

  SX01.poll();

  voltage = SX01.getVoltage();

  // Print Voltage 
  Serial.print("Voltage = ");
  Serial.print(voltage,3);
  Serial.println(" V");
  Serial.println();

  delay(1000);
}

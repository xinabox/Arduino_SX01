/*************************************************************
  This is an example for the SX01
  Analog IN - Max Input 3.3V
  
  You can buy one on our store!
  -----> https://xinabox.cc/SX01/
  
  This example measures the input voltage on the SX01
  and displays it on the Serial Monitior
    
  The sensor communicates over the I2C Bus.

  ------------------------TIPS--------------------------
  ----->Wire.begin(2,14); Communication with CW01
  
*************************************************************/

#include <xCore.h>
#include <xSX01.h>

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

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
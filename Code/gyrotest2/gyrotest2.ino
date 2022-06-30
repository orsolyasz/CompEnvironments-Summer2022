//include libraries for BNO055
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//Two BNO gyroscopes communicating through I2C
//one sensor of them has ADR connected to 3 volts to change the default address
Adafruit_BNO055 bno = Adafruit_BNO055(55);

float gy1y=0;
float gy1z=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

    bno.setExtCrystalUse(true);
}


void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t event; 
 bno.getEvent(&event);
 
 gy1y=event.orientation.y;
 gy1z=event.orientation.z;
 
 Serial.print("Y:");
 Serial.print(gy1y);
 Serial.print("Z:");
 Serial.println(gy1z);

}

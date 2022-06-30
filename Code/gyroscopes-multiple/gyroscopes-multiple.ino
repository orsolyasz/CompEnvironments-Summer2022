char inChar;

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
Adafruit_BNO055 bno2 = Adafruit_BNO055(55, 0x29);
//Gyroscpe setup

int timeNow;
int timePost=0;

float gy1y=0;
float gy1z=0;
float gy2y=0;
float gy2z=0;

//const int GY1 = 7;
//const int GY2 = 8;

void setup() {
//   pinMode(GY1, OUTPUT);
//   pinMode(GY2, OUTPUT);
//   digitalWrite(GY2, LOW);
//   digitalWrite(GY1, HIGH);


  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

  Serial.begin(9600);

   /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

   if(!bno2.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no second BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  //delay(1000);
    
  bno.setExtCrystalUse(true);
  bno2.setExtCrystalUse(true);
  //Gyroscpoe setup
 
}

void loop() {
   /* Get a new sensor event */ 
//  for (int i=0; i<2; i++){
//      if (i==0){
//        digitalWrite(GY1, LOW);
//        digitalWrite(GY2, HIGH);
//        sensors_event_t event; 
//        bno.getEvent(&event);
//        gy1y=event.orientation.y;
//        gy1z=event.orientation.z;
//      } 
//      else if(i==1){
//        digitalWrite(GY1, HIGH);
//        digitalWrite(GY2, LOW);
//        sensors_event_t event2; 
//        bno.getEvent(&event2);
//        gy2y=event2.orientation.y;
//        gy2z=event2.orientation.z;
//      }
//}

 sensors_event_t event; 
 bno.getEvent(&event);
 gy1y=event.orientation.y;
 gy1z=event.orientation.z;
 
 sensors_event_t event2; 
 bno2.getEvent(&event2);
 gy2y=event2.orientation.y;
 gy2z=event2.orientation.z;

if(millis()-timePost > 800){
//  Serial.print("X");
//  Serial.print(event.orientation.x, 0);
//  Serial.print("Y");
//  Serial.print(event.orientation.y, 0);
//  Serial.print("Z");
//  Serial.println(event.orientation.z, 0);
  Serial.print(1);
  Serial.print("Y ");
  Serial.print(gy1y);
  Serial.print("  Z ");
  Serial.print(gy1z);
  Serial.print("  2");
  Serial.print("Y ");
  Serial.print(gy2y);
  Serial.print("  Z ");
  Serial.print(gy2z);
  Serial.println("");
  timePost = millis();
  }
}

//include libraries for BNO055
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//Two BNO gyroscopes communicating through I2C
//one sensor of them has ADR connected to 3 volts to change the default address
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
Adafruit_BNO055 bno2 = Adafruit_BNO055(55, 0x29);


//variables for Hardware Serial Communication

//Leonardo Board One Pin0 is connected to Leonardo Board Two Pin 1
//Board One Pin1 is connected to Board Two Pin0
char inChar;
char inData[10];
int dataLength = 0;
String gyro3Readings = "0000,0000,";


//variables to store gyroscope info
float gy1y=0;
float gy1z=0;
float gy2y=0;
float gy2z=0;
float gy3y=0;
float gy3z=0;


void setup() {
  // start Serial to write to computer, Serial1 to listen to the sender board
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("starting up");


  /* Initialise the sensors */
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

  bno.setExtCrystalUse(true);
  bno2.setExtCrystalUse(true);

 //initialize incoming data array
  for (dataLength = 0; dataLength < 10; dataLength++) {
    inData[dataLength]=',';
    }


   Serial.println("bnos found");
}

void loop() {
  Serial.println("looping");

  readGyro3Data();
  readGyro1Data();
  readGyro2Data();

  Serial.print("GYRO1: ");
  Serial.print(gy1y);
  Serial.print(",");
  Serial.print(gy1z);
  Serial.print("   GYRO2: ");
  Serial.print(gy2y);
  Serial.print(",");
  Serial.print(gy2z);
  Serial.print("   GYRO3: ");
  Serial.print(gy3y);
  Serial.print(",");
  Serial.print(gy3z);
  Serial.println("");

  delay(2);


}

void readGyro1Data() {
 sensors_event_t event; 
 bno.getEvent(&event);
 gy1y=event.orientation.y;
 gy1z=event.orientation.z;
  }

void readGyro2Data(){
   sensors_event_t event2; 
 bno2.getEvent(&event2);
 gy2y=event2.orientation.y;
 gy2z=event2.orientation.z;
  }

void readGyro3Data() {
  
  if (Serial1.available()) {
      //char inByte = Serial1.read();
//    Serial.write(inByte);
     if (Serial1.read() == 'b') {
       for (dataLength = 0; dataLength < 10; dataLength++) {
        delay(2);
        inData[dataLength] = Serial1.read();
         if (inData[dataLength] == 'n') {
           inData[dataLength] = ',';
           break;
         }
        }
      }
    }

  gyro3Readings="";
  for (int i = 0; i < 10; i++) {
    gyro3Readings = gyro3Readings + inData[i];
  }
  
  //Serial.println(gyro3Readings);
    getGyro3Values();

}


void getGyro3Values(){
   int firstCommaIndex = gyro3Readings.indexOf(',');
   int secondCommaIndex = gyro3Readings.indexOf(',', firstCommaIndex+1);

   String firstValue = gyro3Readings.substring(0,firstCommaIndex);
   String secondValue = gyro3Readings.substring(firstCommaIndex+1,secondCommaIndex);

   gy3z= firstValue.toInt();
   gy3y= secondValue.toInt();
 }

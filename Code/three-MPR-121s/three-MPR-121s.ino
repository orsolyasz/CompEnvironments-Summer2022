// set up MPR121 sensors
#include <Wire.h>
#include "Adafruit_MPR121.h"
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif
Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();
Adafruit_MPR121 cap3 = Adafruit_MPR121();

uint16_t currtouched1 = 0;
uint16_t currtouched2 = 0;
uint16_t currtouched3 = 0;

byte cap1values[12]= {0};
byte cap2values[12]= {0};
byte cap3values[12]= {0};

uint8_t cap1count = 0;
uint8_t cap2count = 0;
uint8_t cap3count = 0;

float cap1active = 0;
float cap2active = 0;
float cap3active = 0;

byte cap1target = 0;
byte cap2target = 0;
byte cap3target = 0;

byte checkpoint1 = 0;
byte checkpoint2 = 0;
byte checkpoint3 = 0;

const uint8_t threshold=2;

void setup() {
  Serial.begin(9600);
  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }

// initializing MPR121 capacitive sensors
  initializeMPRs();


}

void loop() {

  //reset our values
  resetArray(cap1values);
  resetArray(cap2values);
  resetArray(cap3values);
  cap1count = 0;
  cap2count = 0;
  cap3count = 0;

  //get all three MPR121 readings
  readMPRs();
  cap1active=checkActivation(cap1count, cap1target, cap1active, threshold);
  cap2active=checkActivation(cap2count, cap2target, cap2active, threshold);
  cap3active=checkActivation(cap3count, cap3target, cap3active, threshold);

  if(cap1active<0.2){
    checkpoint1=0;
    } else {checkpoint1=1;}
  if(cap2active<0.2){
    checkpoint2=0;
    } else {checkpoint2=1;}
  if(cap3active<0.2){
    checkpoint3=0;
    } else {checkpoint3=1;}

  Serial.print("is cap1 activated?");
  Serial.println(checkpoint1);
  Serial.print("is cap2 activated?");
  Serial.println(checkpoint2);
  Serial.print("is cap3 activated?");
  Serial.println(checkpoint3);


//for debug:
//  Serial.print("cap1 reads: ");
//  for(uint8_t i=0; i<12; i++){
//    Serial.print(cap1values[i]);
//  }
//  Serial.println("");

}

void resetArray(byte arrayinput[12]){
  for (uint8_t i=0; i<12; i++){
    arrayinput[i]=0;
    }
 }

float checkActivation(uint8_t counter,byte target,float tracker, int threshold){
  if(counter>threshold){
    target=1;
    }
  else{target=0;}
  tracker=tracker+(target-tracker)*0.2;
  return tracker;
  }


void readMPRs(){
  // getting our MPR121 sensor readings, these return a
  //number between 0 and 2^12
  currtouched1 = cap1.touched();
  delay(3);
  currtouched2 = cap2.touched();
  delay(3);
  currtouched3 = cap3.touched();
  delay(3);

   //store our readings as a binary array to make it easy to
 //see which touchpoint is on/off
 for(uint8_t i=0; i<12; i++){
    cap1values[i]=(int(currtouched1/(pow(2,(i)))))%2;
    cap2values[i]=(int(currtouched2/(pow(2,(i)))))%2;
    cap3values[i]=(int(currtouched3/(pow(2,(i)))))%2;
    if(i<11){
      if(cap1values[i]==1){
        cap1count++;
        }
        if(cap2values[i]==1){
        cap2count++;
        }
        if(cap3values[i]==1){
        cap3count++;
        }
      }
  }
 }

 void initializeMPRs(){
  if (!cap1.begin(0x5A)) {
    Serial.println("MPR121 cap1 not found, check wiring?");
    while (1);
  }
  if (!cap2.begin(0x5C)) {
    Serial.println("MPR121 cap2 not found, check wiring?");
    while (1);
  }
  if (!cap3.begin(0x5D)) {
    Serial.println("MPR121 cap3 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121s found!");
}

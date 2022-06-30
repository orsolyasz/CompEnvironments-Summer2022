//basic code for getting messages to and from unreal

char inChar;
const int analogInPin = A0;
int sensorValue = 0;  
float averageSensorReading = 0;
int MeasurementsToAverage = 32;



void setup() 
{


  pinMode(12, OUTPUT); //this is our LED pin
  digitalWrite(12, LOW); //default off
  
  Serial.begin(115200);
}

void loop() 
{ 


  sensorValue = analogRead(analogInPin); //reading our potentiometer

  
  Average(sensorValue); //custom function to filter data and reduce stuttering
  
  Serial.println(averageSensorReading); //printing the sensor value to the serial


  while(Serial.available()) //checking for received messages on serial
  { 
    inChar = Serial.read();
    toggleLight(); //custom function for turning on/off light - but this could be anything!
  }

  
  
  

  
}

void toggleLight(){
  if (inChar == '1') //if we receive the character "1"....
  {
    Serial.println("On");
    digitalWrite(12, HIGH);//... turn the LED on
  }

  else if (inChar == '0') //if we receive the character "0"....
  {
    Serial.println("Off");
    digitalWrite(12, LOW); //turn the light off
  }
}


void Average(int input)
{
  
  
  for(int i = 0; i < MeasurementsToAverage; ++i)
  {
    averageSensorReading += input;
    delay(1);
  }
  averageSensorReading /= MeasurementsToAverage;
}

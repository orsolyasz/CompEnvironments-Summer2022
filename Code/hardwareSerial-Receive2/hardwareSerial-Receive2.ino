char inData[10];
int dataLength = 0;

String gyro3Readings = "0000,0000,";

float gy3y=0;
float gy3z=0;

void setup() {
  // put your setup code here, to run once:
//  secondBoard.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);

  for (dataLength = 0; dataLength < 10; dataLength++) {
    inData[dataLength]=',';
    }

}

void loop() {
  
  readGyro3Data();
  getGyro3Values();


  // blank line to separate data from the two ports:


  delay(2);
//  secondBoard.listen();


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
  
  Serial.println(gyro3Readings);

}


void getGyro3Values(){
   int firstCommaIndex = gyro3Readings.indexOf(',');
   int secondCommaIndex = gyro3Readings.indexOf(',', firstCommaIndex+1);

   String firstValue = gyro3Readings.substring(0,firstCommaIndex);
   String secondValue = gyro3Readings.substring(firstCommaIndex+1,secondCommaIndex);

   gy3z= firstValue.toInt();
   gy3y= secondValue.toInt();

   Serial.print(gy3z);
   Serial.print("   ,   ");
   Serial.println(gy3y);
  
 }

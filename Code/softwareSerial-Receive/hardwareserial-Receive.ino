char incoming[100];


void setup() {
  // put your setup code here, to run once:
//  secondBoard.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  
 

  if (Serial1.available()) {
    char inByte = Serial1.read();
    
    Serial.write(inByte);
    
   }


  // blank line to separate data from the two ports:


  delay(2);
//  secondBoard.listen();


}

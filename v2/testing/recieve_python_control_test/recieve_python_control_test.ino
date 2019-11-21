void setup() { }

void loop() {
  while (1) {
    if (Serial.available() > 0) {
       input = 0;
       while (true) {
         // read the incoming byte:
         incomingByte = Serial.read();
         decodedByte = incomingByte -48;  //-48 converts between ASCII and integers
  
         // leave the loop if return character is received
         if (decodedByte==-38){
           break;
         }
         // put previous byte in the 10s place
         userInput = 10*userInput + decodedByte;
      }
    }
  }
  Serial.println(userInput);
}

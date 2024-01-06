#include <Arduino.h>

char incomingByte;
String msg;

//the signal pin for the relay
//can be set to any available digital pin
//on the Arduino
const int RELAY_PIN = 3;

void setup() {
  Serial.begin(9600); //baud rate - do not change
  Serial.begin(9600);
  //pinMode(RELAY_PIN,OUTPUT);
}

void loop() {
  if(Serial.available()){
    //incomingByte = Serial.read();
    msg = Serial.readStringUntil('\n');

    // say what you got:
    // Serial.print("I received: ");
    // Serial.println(incomingByte, DEC);
    // Serial.println(incomingByte);

    Serial.println(msg);
    
    //writeToPin(incomingByte);
  }
}

void writeToPin (char b) {
    if(b == '0'){
       digitalWrite(RELAY_PIN,LOW); //deactivate
    }
    if(b == '1'){
       digitalWrite(RELAY_PIN,HIGH); //activate
    }
}

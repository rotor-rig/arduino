#include <Arduino.h>

char incomingByte;

//the signal pin for the relay
//can be set to any available digital pin
//on the Arduino
const int RELAY_1 = 4; // relay channel 1 on=A off=a
const int RELAY_2 = 7; // relay channel 2 on=B off=b
const int RELAY_3 = 8; // relay channel 3 on=C off=c
const int RELAY_4 = 12; //relay channel 4 on=D off=d

//use Z and z to turn all relays on/off at once

void setup() {
  Serial.begin(9600); //baud rate - do not change
  pinMode(RELAY_1,OUTPUT);
  pinMode(RELAY_2,OUTPUT);
  pinMode(RELAY_3,OUTPUT);
  pinMode(RELAY_4,OUTPUT);
}

void loop() {
  if(Serial.available()){
    incomingByte = Serial.read();
    writeToPin(incomingByte);
  }
}

void writeToPin (char b) {
    switch (b) {
      case 'a': digitalWrite(RELAY_1,LOW); break;
      case 'A': digitalWrite(RELAY_1,HIGH); break;
      case 'b': digitalWrite(RELAY_2,LOW); break;
      case 'B': digitalWrite(RELAY_2,HIGH); break;
      case 'c': digitalWrite(RELAY_3,LOW); break;
      case 'C': digitalWrite(RELAY_3,HIGH); break;
      case 'd': digitalWrite(RELAY_4,LOW); break;
      case 'D': digitalWrite(RELAY_4,HIGH); break;
      case 'z':
        digitalWrite(RELAY_1,LOW);
        digitalWrite(RELAY_2,LOW);
        digitalWrite(RELAY_3,LOW);
        digitalWrite(RELAY_4,LOW);
      break;
      case 'Z':
        digitalWrite(RELAY_1,HIGH);
        digitalWrite(RELAY_2,HIGH);
        digitalWrite(RELAY_3,HIGH);
        digitalWrite(RELAY_4,HIGH);
      break;
    }
}

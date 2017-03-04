#include <Ultrasonic.h>

bool presed;
Ultrasonic ultrasonic(5,6);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  presed = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(9)){
    if(presed){
      if(ultrasonic.Ranging(CM)< 50){
        digitalWrite(8, HIGH);
      }
      presed = false;
    }
    else{
      digitalWrite(8, LOW);
      presed = true;
    }
  }
}

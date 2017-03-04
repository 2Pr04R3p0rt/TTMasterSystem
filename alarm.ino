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
  presed = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ultrasonic.Ranging(CM)< 50){
        digitalWrite(8, HIGH);
  }
  else digitalWrite(8, LOW);
}

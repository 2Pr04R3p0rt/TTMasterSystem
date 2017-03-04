#include <Ultrasonic.h>

bool pressed; //false = alarma apagada, true = alarma vigilante

Ultrasonic ultrasonic(5,6);

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode
  pinMode(8, OUTPUT);
  pinMode(1, INPUT); //aqui llegará la entrada del botón para cambiar los modos
  pressed = false; //por defecto la alarma está apagada
}

void loop()
{
  if (digitalRead(1) == HIGH) //si leemos que ha entrado un boton
  {
    alarma = true; //cambiamos el modo alarma
  }
  else alarma = false;
  if (alarma) //tenemos la alarma vigilando la casa, así que cuando el sensor detecte algo sonará la alarma
  {
    if(ultrasonic.Ranging(CM) < 50){
          digitalWrite(8, HIGH);
    }
    else digitalWrite(8, LOW);
  }
  else digitalWrite(8, LOW); //como el modo es off, dejamos alarma siempre apagada
}

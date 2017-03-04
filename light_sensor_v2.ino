#include <NECIRrcv.h>

#define IRPIN 8
#define sensor 2;

NECIRrcv ir(IRPIN);

//**variables globales
bool mode; //1 -> automático (1 mando), 0 -> manual (2 mando)
bool led; //false = apagado, true = encendido
const int luz=7;
void setup()
{
  mode = true;
  led = false;
  
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  
  ir.begin();
  Serial.println("NEC IR code reception");
}

void loop()
{
  //*** inicialización IR
  unsigned long ircode;
  ircode = ir.read();
  Serial.print("got code : 0x");
  Serial.println(ircode,HEX);
  
  //*** inicialización sensor_luz
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  Serial.println(led);
  if (ircode == 0xE916FF00)
  {
    mode = true;
    Serial.println("el modo es");
    Serial.println(mode);
  }
  else if (ircode == 0xE619FF00)
  {
    mode = false;
    Serial.println("el modo es");
    Serial.println(mode);
  }
  if (mode) //está el modo automático
  {
    if (sensorValue < 250)
    {
      digitalWrite(7, HIGH);
      led = true;
    }
    else
    {
      digitalWrite(7, LOW);
      led = false;
    }
  }
  else //modo manual
  {
    if (Serial.available()){
      //guardamos en c cada byte del buffer
      char c=Serial.read();
      //Mostramos c
      Serial.println();//debug
      if (c=='H'){
        digitalWrite(luz, HIGH);
      }
      else if (c=='L'){
        digitalWrite(luz, LOW);
      }
    }
  }
  delay(100);
}

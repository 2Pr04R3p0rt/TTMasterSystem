#include <NECIRrcv.h>
#define sensor 2; 	// Se define el pin donde conectamos el sensor
NECIRrcv ir(sensor);
		
void setup{
  Serial.begin(9600); 
  ir.begin();			
}
		
void loop{
  unsigned long codigo; // Los datos se almacenan en la variable código 			
  Serial.print("Código: "); //Se muestra el Código
  Serial.println(codigo) ;
}

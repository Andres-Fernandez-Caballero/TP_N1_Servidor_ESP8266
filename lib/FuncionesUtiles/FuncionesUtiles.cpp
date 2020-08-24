#include <FuncionesUtiles.h>

void halfBlink(int led, int espera){
  digitalWrite(led, !digitalRead(led));
  delay(espera);
}

void Blink(int led, int espera, int cant_repeticiones){
  
  for (int  i = 0; i <= cant_repeticiones; i++){
    
    halfBlink(led,espera);
    halfBlink(led,espera);

  }
}



void print(String texto)
{
	Serial.print(texto);
}

void println(String texto)
{
	Serial.println(texto);
}
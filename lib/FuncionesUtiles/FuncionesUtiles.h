/*** Funciones utiles.h ***/
/* Libreria para metodos estandar y repetitivos */

#pragma once

#ifndef FUNCIONES_UTILES_H
#define FUNCIONES_UTILES_H

#include <Arduino.h>

  void Blink(int led, int espera, int cant_repeticiones);

  //escritura en pantalla
  void print(String texto);
  void println(String texto);
  
#endif
/*** Interruptor.h ***/
/*** Clase para controlar los pines de salida de arduino 
 * cuando estos trabajan como interruptores 
 * ya sea de luces led o accionadores de potencia. ***/

#pragma once

#ifndef INTERRUPTOR_H
#define INTERRUPTOR_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

class Interruptor
{
private:
    int pin;
    bool state;
    void commitState(); // envia al pin el state de la clase Interruptor.
    void stateMessage(); // muestra por consola el estado 
public:
    Interruptor(int _pin); // constructor con parametros
    //~Interruptor(); // destructor de clase
    int getPin(); // devuelve el numero de pin asignado en el arduino.
    void changeState(); // alterna el estado del interruptor;
    void changeState(bool new_state); // cambia el estado del interruptor a uno especificado por parametro ( si no le veo sentido pero podria servir supongo).
    bool isOn(); // retorna el estado del interruptor tru si esta encendido y false si esta apagado.
    String ToString(); // devuevle un strig con el contenido del objeto formateado
    String ToJson();
};

#endif
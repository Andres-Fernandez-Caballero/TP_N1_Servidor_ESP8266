/*** Luz.h ***/
/* Libreria que gestiona la clase Luz */

#pragma once

#ifndef LUZ_H
#define LUZ_H

#include <Arduino.h>
#include "FuncionesUtiles.h"

class Luz
{
private:
    int pin;
    bool state;

    void setOutput();
    
public:
    Luz(); // constructor generico
    Luz(int pin);
    //~Luz(); // destructor
    void changeState(); //alterna el estado de la luz
	void changeState(bool state); // defino el nuevo estado de la luz
	String getState();
	int getPin();
	void begin(int pin_rele);
	bool isLuzOn();
};

#endif
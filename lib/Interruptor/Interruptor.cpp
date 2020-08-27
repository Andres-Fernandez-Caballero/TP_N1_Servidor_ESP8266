#include <Interruptor.h>

Interruptor::Interruptor(int _pin): pin(_pin){
    pinMode(this->pin,OUTPUT); //defino al pin como salida digital
    this->state = false; // valor por defecto de la salida
}

void Interruptor::stateMessage(){
    Serial.println(this->ToString());
}

void Interruptor::commitState(){
    digitalWrite(this->pin, this->state);
    //stateMessage();
}

int Interruptor::getPin(){
    return this->pin;
}

void Interruptor::changeState(){
    this->state = !this->state;
    commitState();
}

void Interruptor::changeState(bool new_state){
    this->state = new_state;
    commitState();
}

bool Interruptor::isOn(){
    return this->state;
}

String Interruptor::ToString(){
    String strPin = "pin ->" + getPin();
    String strState = " estado -> "+ isOn()? "Encendido" : "Apagado";
     return strPin + strState;
}


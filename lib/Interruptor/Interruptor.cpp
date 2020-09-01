#include <Interruptor.h>

Interruptor::Interruptor(int _pin): pin(_pin){
    pinMode(getPin(),OUTPUT); //defino al pin como salida digital
    changeState(LOW); // valor por defecto de la salida
}

void Interruptor::stateMessage(){
    Serial.println(ToString());
}

void Interruptor::commitState(){
    digitalWrite(getPin(), isOn());
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

String Interruptor::ToJson(){
    StaticJsonDocument<200> interruptor_;
    
    interruptor_["pin"] = getPin();
    interruptor_["state"] = isOn();

    String json;

    serializeJsonPretty(interruptor_,json);

    return json;
}


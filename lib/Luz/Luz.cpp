#include "Luz.h"

Luz::Luz()
{
	this->pin = 0;
	this->state = false;
}

Luz::Luz(int pin): pin(pin)
{
	this->state = false;
}
/*
Luz::~Luz()
{
	println("Objeto luz destruido");
}
*/

void Luz::changeState()
{
	this->state = !this->state;
	setOutput();
}

void Luz::changeState(bool state)
{
	this->state = state;
	setOutput();

}

String Luz::getState()
{
	return this->state? "true":"false";
}

int Luz::getPin()
{
	return this->pin;
}

void Luz::begin(int pin_rele)
{
	this->pin = pin_rele;
	pinMode(pin, OUTPUT);

	print("Luz iniciada en el pin ");
	Serial.println(getPin());
	// print("estado de la luz: ");
	// println(isLuzOn() ? "encendida" : "apagada");
}

bool Luz::isLuzOn()
{
	return this->state;
}

void Luz::setOutput()
{
	digitalWrite(this->pin, !this->state);
	print("Estado: ");
	println(this->state ? "Encendido" : "Apagado");
}

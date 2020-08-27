/**** Wifi ****/
/* Esta libreria se encarga de conectar un esp8266 a la red wifi */
#pragma once

#ifndef WIFI_CONEXION_H
#define WIFI_CONEXION_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ConfigM.h>
#include <FuncionesUtiles.h>
#include <Interruptor.h>

class Wifi
{
private:
  static Wifi *instance_wifi;
  Wifi();
 //~Wifi(); // destructor de clase
public:
    static Wifi* begin();
    bool establecerConexion();

};
  
#endif
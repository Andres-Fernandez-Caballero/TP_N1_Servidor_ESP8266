/**** WifiConexion ****/
/* Esta libreria se encarga de conectar un esp8266 a la red wifi */
#pragma once

#ifndef WIFI_CONEXION_H
#define WIFI_CONEXION_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ConfigM.h>
#include <FuncionesUtiles.h>

  bool iniciarConexionWifi(int led);

  bool iniciarConexionWifi();
  
#endif
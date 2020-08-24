#pragma once

#ifndef _MAU_SERVE_H

#define _MAU_SERVE_H

#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <LittleFS.h>
#include <AsyncJson.h>
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include <ConfigM.h>
#include <WifiConexion.h>
#include <FuncionesUtiles.h>
#include <Luz.h>



void iniciarServer(int led_1, int pin_rele, bool serial_port); // metodo principal inicia el servidor y todos sus servicios

void handleOtaServer(); // maneja el servicio de OTA

void handleSocket(); // maneja el servicio de web socket

#endif
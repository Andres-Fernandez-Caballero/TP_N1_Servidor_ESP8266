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
#include <Wifi.h>
#include <FuncionesUtiles.h>
#include <Interruptor.h>

class MauServer
{
private:
    static MauServer *instance_mauServer;
    AsyncWebServer *server;
    Interruptor *luz;
    Interruptor *led_testigo;

    void saludar(); // da un mensaje de bienvenida por consola
    void establecerConexion();
    MauServer(int pin_led,int pin_rele);
    //MauServer(); // constructor generico
    //~MauServer(); // destructor de clase, estos destructores arrojan error si estan descomentados...
public:
    static MauServer* getInstance(int pin_led, int pin_rele);
    Interruptor* getInterruptorLuz();
    //static MauServer* getInstance(); // en caso de necesitar una instancia sin parametros
    
};

#endif
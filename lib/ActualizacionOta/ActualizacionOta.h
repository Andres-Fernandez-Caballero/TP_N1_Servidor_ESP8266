#pragma once

#ifndef ACTUALIZACION_OTA_H
#define ACTUALIZACION_OTA_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ConfigM.h>
//#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <LittleFS.h>
#include <MauServer.h>

class ActualizacionOta
{
private:
    static ActualizacionOta *instance_OTA;
    ActualizacionOta();
    //~ActualizacionOta();
public:
    static ActualizacionOta* getInstance();
    void begin();
    void handleOta();
};

#endif
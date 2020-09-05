#pragma once

#ifndef ACTUALIZACION_OTA_H
#define ACTUALIZACION_OTA_H

#include <Arduino.h>
#include <ConfigM.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <Interruptor.h>

class ActualizacionOta
{
private:
    static ActualizacionOta *instance_OTA;
    ActualizacionOta(Interruptor luz, Interruptor led_testigo);
    //~ActualizacionOta();
public:
    static ActualizacionOta* begin(Interruptor luz, Interruptor led_testigo);
    
};

#endif
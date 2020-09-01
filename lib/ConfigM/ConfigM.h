
/*** ConfigM.h ***/
/* Libreria encargada de las constantes de configuracion globales y unificadas */

#pragma once

#ifndef _CONFIG_H

#define _CONFIG_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

/* Configuracion de puerto serie */

#define BAUD_SPEED 115200 // velocidad del monitor serie, comente esta linea para deshabilitar la salida de terminal 

/* Configuracion del Servidor */
#define SERVER_PORT 80 // puerto del servidor

/* Configuracion de WiFi */
#define IP_FIJA // comente esta linea para que el servidor elija automaticamente la direccion IP
#ifdef IP_FIJA
    // direccion ip fija
    #define IP_A 192
    #define IP_B 168
    #define IP_C 0
    #define IP_D 25  //ej: 192.168.0.25

    // direccion puerta acceso
    #define IPA_A 192
    #define IPA_B 168
    #define IPA_C 0
    #define IPA_D 1  //ej: 192.168.0.1

    //mascara de red
    #define MASK_A 255
    #define MASK_B 255
    #define MASK_C 255
    #define MASK_D 0  //ej: 255.255.255.0
#endif

#define RED_HOGAR "Mau Hogar 2.4GHz" // ssid de la red
#define PASSWORD "DorianElGris" // password de la red

//#define RED_HOGAR "wifi POP!" // ssid para el wifi del celular
//#define PASSWORD "hell0ween" // pass para wifi del celular

#define TIME_UP 10000 // limite de espera de conexion wifi medido en milisegundos

/* Configuracion OTA */
#define OTA_PORT 8266 // puerto de OTA
#define OTA_HOSTNAME "Web Server Luz"

#endif
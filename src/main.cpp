#include <Arduino.h>
#include <MauServer.h>

//#include <ESP_01_Diagrama.h>


void setup() {

     MauServer::getInstance();
}

void loop() {

    MauServer::getInstance()->manejarServicios(); 
}
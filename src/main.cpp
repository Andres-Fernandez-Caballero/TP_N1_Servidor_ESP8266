#include <Arduino.h>
#include <MauServer.h>
//#include <ESP_01_Diagrama.h>

MauServer *server;

void setup() {
    
 // iniciarServer(3,4,true);
    server = MauServer::getInstance(LED_BUILTIN,3);

}

void loop() {
    server->manejarServicios(); 
}
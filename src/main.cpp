#include <Arduino.h>
#include <MauServer.h>
//#include <ESP_01_Diagrama.h>

void setup() {
    
 // iniciarServer(3,4,true);
 MauServer::getInstance(5,LED_BUILTIN);

}

void loop() {
  
}
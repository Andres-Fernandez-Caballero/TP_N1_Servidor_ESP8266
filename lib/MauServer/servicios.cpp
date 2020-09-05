#include <MauServer.h>

void MauServer::manejarServicios(){

   
    // si tengo habilitado el servicio socket entonces envio el estado del interruptor por el mismo
    #ifdef SERVICIO_SOCKET
    
        

        Serial.println(getInterruptorLuz()->ToString());
        socket->textAll(getInterruptorLuz()->isOn()? "true" : "false");
    #endif
}
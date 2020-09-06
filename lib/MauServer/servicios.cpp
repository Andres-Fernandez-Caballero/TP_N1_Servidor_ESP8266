#include <MauServer.h>
#include <ActualizacionOta.h>


void MauServer::iniciarServicios(){
    
    ActualizacionOta::getInstance()->begin();   
}

void MauServer::manejarServicios(){

    
    #ifdef SERVICIO_OTA
        ActualizacionOta::getInstance()->handleOta();
    #endif
   
}
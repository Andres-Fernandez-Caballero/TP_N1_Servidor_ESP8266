#include <MauServer.h>
#include <ActualizacionOta.h>


void MauServer::iniciarServicios(){
    #ifdef SERVICIO_OTA
        ActualizacionOta::getInstance()->begin();
    #endif   
}

void MauServer::manejarServicios(){

    
    #ifdef SERVICIO_OTA
        ActualizacionOta::getInstance()->handleOta();
    #endif
   
}
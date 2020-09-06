#include <ActualizacionOta.h>



ActualizacionOta *ActualizacionOta::instance_OTA;

ActualizacionOta::ActualizacionOta(){
    
  #ifdef OTA_PORT  
    ArduinoOTA.setPort(OTA_PORT); // puerto del ota
  #endif

  #ifdef OTA_HOSTNAME
    ArduinoOTA.setHostname(OTA_HOSTNAME); // nombre con el que aparecera en la opcion de actualizacion
  #endif
  
  #ifdef OTA_PASSWORD // si tengo definido OTA_PASSWORD en ConfigM.h las actualizaciones se validaran con una contraseña
   ArduinoOTA.setPassword(OTA_PASSWORD);
  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
  #endif
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_littleFS
      LittleFS.end(); // cierro la lectura de archivos de la memoria flash
      type = "filesystem";
    }

    // hace algo antes de iniciar la actualizacion, en este caso apago las luces
    MauServer::getInstance()->getInterruptorLuz()->changeState(LOW);
    MauServer::getInstance()->getInterruptorLuzTestigo()->changeState(HIGH);

    Serial.println("Iniciando Actualizacion del " + type);
  });

  // que hace cuando termina de actualizar
  ArduinoOTA.onEnd([]() {
    Serial.println("\n<-- Actualizacion Terminada -->");
  });

  // muestra el prorcentaje de actualizacion
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progreso: %u%%\r", (progress / (total / 100)));
  });

  // mensaje de error cuando algo falle y fallara *_* 
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
}

ActualizacionOta *ActualizacionOta::getInstance(){
    if(instance_OTA == NULL){
        instance_OTA = new ActualizacionOta();
    } 
    return instance_OTA;
}

void ActualizacionOta::begin(){
  ArduinoOTA.begin();
  Serial.println("servicio ota inicado");
}

void ActualizacionOta::handleOta(){
  ArduinoOTA.handle();
}


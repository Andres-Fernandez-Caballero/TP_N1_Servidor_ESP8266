#include <MauServer.h>
#include <Rutas.cpp>
#include <Servicios.cpp>

MauServer *MauServer::instance_mauServer = NULL;

void MauServer::saludar()
{
    Serial.println("****************************************");
    Serial.println("Server Iniciado ^o^");
    Serial.println("--------------------");
    Serial.println("Configuracion:");
    Serial.print("Puerto del servidor -> "); Serial.println(SERVER_PORT);
    Serial.print("Ruta Metodo GET -> "); Serial.println(API_ROUTE);
    Serial.print("Ruta Metodo PATCH -> "); Serial.println(API_ROUTE);
    Serial.println("****************************************");
}

void MauServer::establecerConexion()
{
   Serial.println();  
   Serial.print("Conectando a ");
   Serial.print(RED_HOGAR);
   Serial.println(" : ");
   Serial.print(" [ ");
    Wifi::getInstance();
   while (!Wifi::getInstance()->isConected())
   {
       Serial.print(".");
       led_testigo->changeState();

       delay(200);
   }
   led_testigo->changeState(LOW);
   Serial.println(" ] ");
   
   Serial.print("conexion establecida a ");
   Serial.println(RED_HOGAR);
   Serial.print("direccion ip: ");
   Serial.println(Wifi::getInstance()->getIp());
}

Interruptor*  MauServer::getInterruptorLuz(){
    return this->luz;
}

Interruptor* MauServer::getInterruptorLuzTestigo(){
    return this->led_testigo;
}

MauServer::MauServer(int pin_led, int pin_rele)
{

/* si esta definido en configM.h activa los mensajes de consola */
#ifdef BAUD_SPEED
    Serial.begin(BAUD_SPEED);
#endif

    server = new AsyncWebServer(SERVER_PORT); // inicio el servidor asyncronico

    led_testigo = new Interruptor(pin_led); // inicio mi objeto interruptor led_testigo.
    luz = new Interruptor(pin_rele); // inicio mi objeto interruptor luz (interruptor de alta). 

    establecerConexion();

    LittleFS.begin(); // inicio la coneccion a la memoria flash del nodemcu

    iniciarServicios();
    
    server->begin(); // inicio el servidor asincronico
    
    /************ carga de rutas *************/ 
    pageRoot(); //pagina de inicio
    pageNotFound(); // ruta en caso de no encontrar un recurso
    apiGet(); // ruta api get la ruta se encuentra en ConfigM.h
    apiPatch(); // ruta api patch, actualizacion de datos la ruta se encuentra en ConfigM.h

    saludar();
}

MauServer *MauServer::getInstance()
{
    if (instance_mauServer == NULL)
    {
        int pin_led = PIN_LED_TESTIGO;
        int pin_rele = PIN_RELE;

        instance_mauServer = new MauServer(pin_led, pin_rele);
    }
    return instance_mauServer;
}
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
    #ifdef SERVICIO_SOCKET
    Serial.print("Ruta WebSocket -> "); Serial.println(SOCKET_ROUTE);
    #endif
    Serial.println("****************************************");

    

}

/* todavia no funciona TODO: evaluar si es viable
void MauServer::iniciarSocket(AsyncWebServer server, AsyncWebSocket socket){

}
*/

void MauServer::establecerConexion()
{
   print("");  
   print("Conectando a ");
   print(RED_HOGAR);
   println(" : ");
   print(" [ ");
   Wifi *wifi = Wifi::begin();
   while (!wifi->isConected())
   {
       print(".");
       led_testigo->changeState();

       delay(200);
   }
   led_testigo->changeState(LOW);
   println(" ] ");

   
   print("conexion establecida a ");
   println(RED_HOGAR);
   print("direccion ip: ");
   println(wifi->getIp());
}

Interruptor*  MauServer::getInterruptorLuz(){
    return this->luz;
}

MauServer::MauServer(int pin_led, int pin_rele)
{

/* si esta definido en configM.h activa los mensajes de consola */
#ifdef BAUD_SPEED
    Serial.begin(BAUD_SPEED);
#endif


    server = new AsyncWebServer(SERVER_PORT); // inicio el servidor asyncronico

    #ifdef SERVICIO_SOCKET // si esta descomentado en ConfigM.h el socket esta habilitado
        socket = new AsyncWebSocket(SOCKET_ROUTE);// inicio el servicio socket
    #endif

    led_testigo = new Interruptor(pin_led); // inicio mi objeto interruptor led_testigo.
    luz = new Interruptor(pin_rele); // inicio mi objeto interruptor luz (interruptor de alta). 

    establecerConexion();
    //iniciarSocket(*server, *socket); // todavia no!!!!

    LittleFS.begin(); // inicio la coneccion a la memoria flash del nodemcu

    server->begin(); // inicio el servidor asincronico
    
    /************ carga de rutas *************/ 
    pageRoot(); //pagina de inicio
    pageNotFound(); // ruta en caso de no encontrar un recurso
    apiGet(); // ruta api get la ruta se encuentra en ConfigM.h
    apiPatch(); // ruta api patch, actualizacion de datos la ruta se encuentra en ConfigM.h

    saludar();
}

MauServer *MauServer::getInstance(int pin_led, int pin_rele)
{
    if (instance_mauServer == NULL)
    {
        instance_mauServer = new MauServer(pin_led, pin_rele);
    }
    return instance_mauServer;
}
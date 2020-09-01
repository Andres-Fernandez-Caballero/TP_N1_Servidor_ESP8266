#include <MauServer.h>

MauServer *MauServer::instance_mauServer = NULL;

void MauServer::saludar()
{
    Serial.println("Server Iniciado ^o^");
}

void MauServer::establecerConexion()
{
     
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

    led_testigo = new Interruptor(pin_led); // inicio mi objeto interruptor led_testigo.
    luz = new Interruptor(pin_rele); // inicio mi objeto interruptor luz (interruptor de alta). 

    establecerConexion();

    LittleFS.begin(); // inicio la coneccion a la memoria flash del nodemcu

    server->begin(); // inicio el servidor asincronico
    
    server->serveStatic("/", LittleFS, "/").setDefaultFile("index.html"); // asigno a la ruta "/" el archivo index.html
    
    server->onNotFound([](AsyncWebServerRequest *request) { // asigno una respuesta cuando no encuentra una ruta valida
        request->send(400, "text/plain", "Not found");
    });

    // metodo GET   /* 
    server->on("/api/luz", HTTP_GET, [&](AsyncWebServerRequest *request){
        request->send(200, "application/json", getInterruptorLuz()->ToJson() );
    });
    
    // metodo PATCH
    // inserte aca

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
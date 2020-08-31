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



MauServer::MauServer(int pin_led, int pin_rele)
{

/* si esta definido en configM.h activa los mensajes de consola */
#ifdef BAUD_SPEED
    Serial.begin(BAUD_SPEED);
#endif

    server = new AsyncWebServer(SERVER_PORT); // inicio el servidor asyncronico

    led_testigo = new Interruptor(pin_led); // inicio mi objeto interruptor led_testigo.
    luz = new Interruptor(pin_rele);        // inicio mi objeto interruptor luz (interruptor de alta).

    establecerConexion();

    LittleFS.begin();

    server->begin();
    
    server->serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
    
    server->onNotFound([](AsyncWebServerRequest *request) {
        request->send(400, "text/plain", "Not found");
    });

    

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

/**************************************************/
/* variables 
globales */

AsyncWebServer server(SERVER_PORT); //inicio el objeto webserver
Luz luz;                            //creo un objeto luz

/* eventos de servidor */

// pagina de inicio
void serverHtmlRoot(char *root, char *file_path)
{
    server.serveStatic("/", LittleFS, root)
        .setDefaultFile(file_path);
}

// evento en caso de no encontrar pagina
void serverOnNotFound()
{
    server.onNotFound([](AsyncWebServerRequest *request) {
        request->send(400, "text/plain", "Not found");
    });
}

void getLuz(AsyncWebServerRequest *request)
{
    request->send(200, "text/plain", luz.getState());
}

void iniciarServer(int led_1, int pin_rele, bool serial_port)
{
    if (serial_port)
    {
        Serial.begin(BAUD_SPEED);
    }

    //iniciarConexionWifi();

    luz.begin(pin_rele);
    LittleFS.begin();

    serverHtmlRoot("/", "index.html");
    serverOnNotFound();
    server.on("/api/luz", HTTP_GET, getLuz);

    server.begin();

    println("Servidor Iniciado ^o^");
}

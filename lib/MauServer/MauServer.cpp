#include <MauServer.h>

/* variables 
globales */

AsyncWebServer server(SERVER_PORT); //inicio el objeto webserver
Luz luz; //creo un objeto luz

/* eventos de servidor */

// pagina de inicio
void serverHtmlRoot(char* root, char* file_path) {
    server.serveStatic("/", LittleFS, root)
        .setDefaultFile(file_path);
}


// evento en caso de no encontrar pagina
void serverOnNotFound() {
    server.onNotFound([](AsyncWebServerRequest* request) {
        request->send(400, "text/plain", "Not found");
    });
}

void getLuz(AsyncWebServerRequest* request){
    request->send(200, "text/plain", luz.getState());
}



void iniciarServer(int led_1, int pin_rele, bool serial_port){
    if(serial_port){
        Serial.begin(BAUD_SPEED);
    }

    iniciarConexionWifi();

    luz.begin(pin_rele);
    LittleFS.begin();

    serverHtmlRoot("/", "index.html");
    serverOnNotFound();
    server.on("/api/luz", HTTP_GET, getLuz);

    server.begin();
   
    println("Servidor Iniciado ^o^");

}

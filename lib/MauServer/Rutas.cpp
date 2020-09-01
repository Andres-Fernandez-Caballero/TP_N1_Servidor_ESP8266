#include <MauServer.h>

#define TYPE_TEXT_PLAIN "text/plain"
#define TYPE_JSON "application/json"

#define NOT_FOUND 404
#define TODO_OK 200
#define ERROR 400

void MauServer::pageRoot()
{
    server->serveStatic("/", LittleFS, "/").setDefaultFile("index.html"); // asigno a la ruta "/" el archivo index.html
}
void MauServer::pageNotFound()
{
    server->onNotFound([](AsyncWebServerRequest *request) { // asigno una respuesta cuando no encuentra una ruta valida
        request->send(NOT_FOUND, TYPE_TEXT_PLAIN, "Pagina no encontrada ERROR_404");
    });
}

void MauServer::apiGet()
{
    // metodo GET   /*
    server->on(API_ROUTE, HTTP_GET, [&](AsyncWebServerRequest *request) {
        request->send(TODO_OK, TYPE_JSON, getInterruptorLuz()->ToJson());
        //Serial.println("Metodo Get:");
        //Serial.println(getInterruptorLuz()->ToJson()); //
    });
}

void MauServer::apiPatch()
{
    // metodo PATCH
    server->on(API_ROUTE, HTTP_PATCH, [&](AsyncWebServerRequest *request) {
        String message = "Parametro no encontrado";
        int code_status = ERROR;
        if (request->hasParam("state"))
        {
            code_status = OK;
            message = request->getParam("state")->value();
            bool newState = message.equals("true") ? true : false;
            getInterruptorLuz()->changeState(newState);
            message = getInterruptorLuz()->ToJson();
        }
        request->send(code_status, TYPE_TEXT_PLAIN, message);
        //Serial.println("metodo Patch");
        //Serial.println(message);
    });
}
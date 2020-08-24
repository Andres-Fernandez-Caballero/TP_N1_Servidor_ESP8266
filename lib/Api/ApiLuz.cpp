#include <ApiLuz.h>

// la solicitud de la peticion get, esta devuelve un mensaje de exito y el estado de la luz en formato texto plano, esto lo voy a mejorar a json despues
void getLuzRequest(AsyncWebServerRequest* request){
    request->send(200, "text/plain", luz.getState());
}


// agrego al servidor el evento getApiLuz
void getApiLuz(AsyncWebServer &server ,Luz &luz){
    server.on("/api/luz", HTTP_GET, getLuzRequest);
}


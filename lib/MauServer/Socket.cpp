#include <MauServer.h>



void onEstadoLuzChanged (
    AsyncWebSocket* server, 
    AsyncWebSocketClient* client, 
    AwsEventType type, 
    void* arg, uint8_t* data, size_t len) {

    switch (type){
    
    
    case WS_EVT_CONNECT:
        println("websocket client conection recibed");
        //client->text("hola desde el Server");
       // client->text(luz.isLuzOn() ? "prendida" : "apagada");
        break;
        
        /*
    case WS_EVT_DISCONNECT:
        println("cliente desconectado");
        break;
        */
    case WS_TEXT:
        print("estado_socket: ");
        //client->text(luz.isLuzOn() ? "prendida" : "apagada");
        break;
    default:
        break;
    }
}
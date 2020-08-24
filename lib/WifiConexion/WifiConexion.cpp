#include <WifiConexion.h>

bool iniciarConexionWifi()
{
    bool response = false;

    WiFi.mode(WIFI_STA); // wifi en modo station osea el modo normal de conexion

#ifdef IP_FIJA
    IPAddress ip(192, 168, 0, IP);      //ip fija
    IPAddress gateway(192, 168, 0, 1);  // ip de la pierta de acceso
    IPAddress subnet(255, 255, 255, 0); // mascara de red

    WiFi.config(ip, gateway, subnet); // configuro la red wifi estatica
#endif
    WiFi.begin(RED_HOGAR, PASSWORD);

    println("");
    print("Conectando a: ");
    println(RED_HOGAR);

    //unsigned long tiempo = millis();
    while (WiFi.status() != WL_CONNECTED /*&& millis()-tiempo >= TIME_UP*/)
    {
        print(".");
        delay(500);
    }

    if(WiFi.status() == WL_CONNECTED){
        println("");
        print("Conectado a: ");
        println(RED_HOGAR);
        Serial.println(WiFi.localIP());
        response = true;
    }else
    {
        println("TIME OUT tiempo de conexion agotado");
    }

    return response;
}

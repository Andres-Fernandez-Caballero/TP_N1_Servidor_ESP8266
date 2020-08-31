#include <Wifi.h>

Wifi *Wifi::instance_wifi;

Wifi::Wifi()
{
    WiFi.mode(WIFI_STA); // wifi en modo station osea el modo normal de conexion

#ifdef IP_FIJA
    IPAddress ip(192, 168, 0, IP);      //ip fija
    IPAddress gateway(192, 168, 0, 1);  // ip de la pierta de acceso
    IPAddress subnet(255, 255, 255, 0); // mascara de red

    WiFi.config(ip, gateway, subnet); // configuro la red wifi estatica
#endif

 WiFi.begin(RED_HOGAR,PASSWORD);

}

Wifi *Wifi::begin()
{
    if (instance_wifi == NULL)
    {
        instance_wifi = new Wifi();
    }
    return instance_wifi;
}

bool Wifi::isConected()
{
    return WiFi.status() == WL_CONNECTED ? true : false; 
}

String Wifi::getIp(){
    return WiFi.localIP().toString();
}

#include <Wifi.h>

Wifi *Wifi::instance_wifi;

Wifi::Wifi()
{
    WiFi.mode(WIFI_STA); // wifi en modo station osea el modo normal de conexion

#ifdef IP_FIJA
    IPAddress ip(IP_A, IP_B, IP_C, IP_D);      //ip fija
    IPAddress gateway(IPA_A, IPA_B, IPA_C, IPA_D);  // ip de la pUerta de acceso
    IPAddress subnet(MASK_A, MASK_B, MASK_C, MASK_D); // mascara de red

    WiFi.config(ip, gateway, subnet); // configuro la red wifi estatica
#endif

 WiFi.begin(RED_HOGAR,PASSWORD);

}

Wifi *Wifi::getInstance()
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

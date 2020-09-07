

# TP N1 Servidor ESP8266

TP n1 para la materia Integración Tecnológica. Consiste en un servidor web basado en la plataforma Arduino.d

## Introduccion
En este trabajo practico monte un servidor web relativamente simple en un modulo wifi, use las plaquetas de desarrollo [ESP-01](https://es.wikipedia.org/wiki/ESP8266) y [NODEMCU](https://es.wikipedia.org/wiki/NodeMCU), para controlar uno de los pines de salida. Representado por un objeto "interrutor" a traves de peticiones a una api, en concreto a una peticion del tipo GET que devuelve un objeto json con el estado del "interruptor" y el su pin asociado y una peticion del tipo PATCH que resive un parametro booleano llamado state y devuelve el objeto interruptor en formato json con los valores de estado actualizados con el parametro recibido.

## Caracteristicas
* Las librerias creadas estan diseñadas con un patron Sigleton y orientadas a objetos, de esta manera me aseguro de que los objetos esten en su estado deseado al llamar a los metodos.
* Todas las variables y opciones pueden habilitarse y modificarse desde un solo archivo llamado ConfigM.h como en el software de marlin( software que controla las impresoras 3D).
* Posibilidad de actualizar a travez del aire actualizacion OTA.
* Posee una pagina web cargada dentro de la memoria flash para el control del estado del "Interruptor".
* El desarrollo esta echo utilizando la plataforma de desarrollo [platformio](https://platformio.org/).



## Instrucciones
Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu máquina

* Este proyecto esta escrito en c++ y usa la el entorno de desarrollo plataformio por lo que se debe de instar. [instrucciones de instalacion](https://docs.platformio.org/en/latest/what-is-platformio.html).

* Descargar el archivo de github [proyecto](https://github.com/Andres-Fernandez-Caballero/TP_N1_Servidor_ESP8266).

* En el archivo configM.h configure sus valores de red y parametros deseados, todas las configuraciones se encuentran ahi, bastara con solo modificar este codigo para hacer funcionar el protecto en su maquina.

* En caso de tener problemas con las bibliotecas de asyncwebserver y arduinojson instalarlas desde el "home" de platformio.

* Para compilar solo debe buscar la opcion upload y upload file system (ejecutar ambos comandos), en las opciones del panel de platformio en el editor de codigo elegido.

## Cosas que quedaron pendientes
En este proyecto y por la falta de tiempo quedo pendiente la implementacion de websocket para el refresco de informacion en tiempo real. Una pagina web funcional que llame a los metodos api.
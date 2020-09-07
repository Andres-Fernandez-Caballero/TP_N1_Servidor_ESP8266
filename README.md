

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

*este proyecto esta escrito en c++ y usa la el entorno de desarrollo plataformio por lo que se debe de instar. [instrucciones de instalacion](https://docs.platformio.org/en/latest/what-is-platformio.html).

*En el archivo configM.h configure sus valores de red y parametros deseados, todas las configuraciones se encuentran ahi, exepto el la configuracion del pin testigo y el pin del interruptor que se encuentran en el main del programa</li>
</ul>
</article>
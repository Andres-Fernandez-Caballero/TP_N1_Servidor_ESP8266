﻿//                                 ESP-01  Diagrama
//------------------------------------------------------------------------------------------------------------------------
//
//  ╔═════════════════════════════════╗              PINOUT
//  ║ │           ■■                  ║
//  ║ └────┐      ■■                  ║              *1- GND
//  ║ ┌────┘ │    ■■        o 7  o 8  ║              *2- GPIO1 / TXD
//  ║ └────┐ │    ▄         o 5  o 6  ║              *3- GPIO2
//  ║ ┌────┘ │              o 3  o 4  ║              *4- CH_EN
//  ║ └────┐ │    ████      ■ 1  o 2  ║              *5- GPIO0
//  ║ ┌────┘ │    ████                ║              *6- RST
//  ║ └──────┘                        ║              *7- GPIO3 / RXD  
//  ╚═════════════════════════════════╝              *8- VCC 
//-----------------------------------------------------------------------------------------------------------------------------


// puerto multiuso
#define GPIO_0 0  // led verde
// puerto tx y multiuso
#define GPIO_1 1  // led azul      _tx
// puerto multiuso
#define GPIO_2 2  // led rojo     
// puerto rx y multiuso
#define GPIO_3 3  // led amarillo  _rx

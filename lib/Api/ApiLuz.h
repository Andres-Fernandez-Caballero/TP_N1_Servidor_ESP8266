/*** ApiLuz.h ***/
/* Se guardan los metodos get,post, patch,update, delete de la clase Luz */

#pragma once

#ifndef API_LUZ_H
#define API_LUZ_H

#include<Arduino.h>
#include <ESPAsyncWebServer.h>
#include <Luz.h>



class ApiLuz
{
private:
    Luz luzRef;
public:
    ApiLuz(/* args */);
    ~ApiLuz();
    void getApiLuz();
    void patchApiLuz();
};


#endif

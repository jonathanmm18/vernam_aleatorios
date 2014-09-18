#ifndef VERNAM_H
#define VERNAM_H
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "funciones.h"

#include <vector>
#include <string>


class vernam
{
private:
    string mensaje;
public:
    string key;
    vernam(int);
    vernam(int, string);
    string cifrado(string);
    string decifrado(string);
    //constexpr int sizeM(string m){return 50;}

};

#endif // VERNAM_H

#ifndef ALEATORIOS_H
#define ALEATORIOS_H
#include "funciones.h"

class aleatorios
{
private:
    vector<int> tab;
    int TamSemilla;
    int TamBits;
    int NVueltas;
    int NTab;
    bool IzDer;// 0 si de derecha a izq, 1 si es de izq a derecha
    int NBloques;


    string cadena;
public:
    vector<string> bloques, b1, b2;
    aleatorios(int,int,int,int,bool,int);
    vector<string> IzqaDere(vector<string>);
    vector<string> DereaIzq(vector<string>);
    int random(int);
    string semilla(int);
    void fillTabs();
    vector<int> isTab(int);
    char XorTabs(char);
    string getAleatorio(){return this->cadena;}
};

#endif // ALEATORIOS_H

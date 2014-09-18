#include "aleatorios.h"

aleatorios::aleatorios(int s, int b, int v, int t, bool DI, int d)
{
    //DI es 0 si es de derecha a izquierda, y 1 si es de izq a derecha
    this->TamSemilla = s;
    this->TamBits = b;
    this->NVueltas = v;
    this->NTab = t;
    this->IzDer = DI;
    this->NBloques = d;
    this->fillTabs();

    this->cadena = keyGenerator<void>(this->TamBits);
    this->bloques = en_bloques<string>(this->cadena,this->NBloques);

    //separo los bloques en dos vectores
    for(int i = 0; i < this->bloques.size(); i++)
    {
        if(mod<int>(i,2)!= 0){this->b1.push_back(bloques.at(i));}
        else{this->b2.push_back(bloques.at(i));}
    }


    //realizo las vueltas
    for(int j = 0; j < this->NVueltas; j++)
    {

        //pregunto si es de derecha a izq o al revez
        if((bool)DI)
        {

            //izq-->derecha
            this->b1 = this->DereaIzq(this->b1);
            this->b2 = this->IzqaDere(this->b2);
        }else{

            //izq<--derecha
             this->b2 = this->DereaIzq(this->b2);
             this->b1 = this->IzqaDere(this->b1);
        }
        this->bloques = juntarVectors<string>(this->b1,this->b2);
        cadena = vectToString<void>(this->bloques);
    }



}

vector<string> aleatorios::DereaIzq(vector<string> b)
{


    for(int j = 0; j < b.size(); j++)
    {

        string temp1, temp2 = b.at(j);
        for(int i = 0; i < b.at(j).size(); i++)
        {
           temp1 = temp2.substr(1,temp2.length());
           temp1 += this->XorTabs(temp2[0]);
        }
        vector<int> Tabx = this->isTab(j);
       if((bool)Tabx[0])
        {

            int k = mod<int>(Tabx[1],this->NBloques);
            temp1[k] = XOR<void>(temp2[0],cadena[Tabx[1]]);
            //SI EN EL BLOQUE EXISTE UN TAB, SE SUMA EL BIT PERDIDO CON EL TAB EN LA POSICION EN LA CADENA
        }
        b[j] = temp1;

    }
    return b;

}
vector<string> aleatorios::IzqaDere(vector<string> b)
{
    for(int j = 0; j < b.size(); j++)
    {
        string temp1, temp2 = b.at(j);
        for(int i = 0; i < b.at(j).size(); i++)
        {
            temp1 = this->XorTabs(temp2[temp2.length()]);
            temp1 += temp2.substr(0,temp2.length()-1);

        }
        vector<int> Tabx = this->isTab(j);
        if((bool)Tabx[0])
        {
            int k = mod<int>(Tabx[1],this->NBloques);
            temp1[k] = XOR<void>(temp2[0],cadena[Tabx[1]]);
            //SI EN EL BLOQUE EXISTE UN TAB, SE SUMA EL BIT PERDIDO CON EL TAB EN LA POSICION EN LA CADENA
        }
        b[j] = temp1;
    }
    return b;
}

int aleatorios::random(int tam)
{
    int r = 0;
    srand(time(NULL));
       for(int j = 0; j < 20; j ++)
       {
           r = ((rand() % tam) + r )%tam;
       }
    return r;
}
void aleatorios::fillTabs()
{
    for(int i = 0; i < this->NTab ; i++)
    {
        int a = this->random(this->TamBits);
        this->tab.push_back(a);
    }

}

char aleatorios::XorTabs(char a)
{
    char res, temp = a;
    for(int i = 0; i < this->NTab; i++)
    {
        res = XOR<void>(temp,cadena[this->tab.at(i)]);
        temp = res;
    }
    return res;

}
vector<int> aleatorios::isTab(int j)
{
   vector<int> Tabx;
    for(int i = 0; i < tab.size() ; i++)
    {
        if((tab[i]/this->NBloques) == j)
        {
            Tabx.push_back(1);
            Tabx.push_back(this->cadena[tab[i]]);
            return Tabx;
        }
    }
    Tabx.push_back(0);
    return Tabx;

}


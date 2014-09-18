#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

template <typename Type>
Type mod(Type a, Type b)
{
      Type r, q;
      q = a/b;
     // if(a == 0)return b;
      if (a < 0)
      {
          if((a*-1) < b )
          {
            return r = (b) + a;
          }
          else{
          q--;
          }
      }

      return  r = a - (q*b);
}
template <typename Type>
ostream& operator << (ostream &o,const vector <Type> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        o << v[i] << ' ';

    }

    return o;
}

template<typename Type>
vector<Type> en_bloques(Type cad, int n)
{
    vector<Type> bloques;
    for(int i = 0; i < cad.size(); i = i + n)
    {
        bloques.push_back(cad.substr(i,n));
    }
    return bloques;

}

template <typename Type>
vector<int> StringToAscii(string men)
{
    vector<int> mensaje;
    for(int i = 0; i < men.size(); i++)
    {
        mensaje.push_back((int)men.at(i));
    }
    return mensaje;

}

template <typename Type>
vector<string> AsciiToBin(vector<int> men)
{
    vector<string> mensaje;
    for(unsigned int i = 0; i < men.size(); i++)
    {
        string s;

        s = bitset <8>(men[i]).to_string();
        mensaje.push_back(s);

    }
    return mensaje;
}

template <typename Type>
string BintoAscci(vector<string> men)
{
    string mensaje;
    for(unsigned int i = 0; i < men.size(); i++)
    {
        int s;
        string bin = men[i];
        bitset<16> num (bin);
        s = (int)num.to_ulong();
        mensaje+= (char)s;
        //mensaje.push_back(s);

    }
    return mensaje;
}

template <typename Type>
char XOR(char a, char b)
{
    int c;
    char d[1];
    int ia = a - '0';
    int ib = b - '0';

    c = mod<int>(ia + ib,2);
    itoa (c,d,2);

    return d[0];
}
template<typename Type>
string SumaXOR(string a, string b)
{
    string res;
    for(int i = 0; i< a.size(); i++)
    {
       res += XOR<void>(a[i],b[i]);
    }

    return res;

}

template<typename Type>
string vectToString(vector<string> cadenas)
{
    string str;
    for(int x = 0; x < cadenas.size(); x++)
    {
        str += cadenas[x];
    }
    return str;
}


template <typename Type>
string keyGenerator(int tam)
{
    vector<string> key;
    int semilla;
    string s;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    semilla = rand() % 25 + 95;

    s = bitset <8>(semilla).to_string();

    for(int i = 0;i< tam -8;i++ )
    {
        if(i == tam - 7){
          s += XOR<void>(s[0],s[i]);
        }
        else{
            s += XOR<void>(s[i+1],s[i]);
        }

    }

    return s;

}

template <typename Type>
string keyGenerator(int tam,string semilla)
{
    string s = semilla;

    for(int i = 0;i< tam -8;i++ )
    {
        if(i == tam - 7){
          s += XOR<void>(s[0],s[i]);
        }
        else{
            s += XOR<void>(s[i+1],s[i]);
        }

    }

    return s;

}
template<typename Type>
vector<Type> juntarVectors(vector<Type> a, vector<Type> b )
{
    vector<Type> c ;
    for(int i = 0; i < a.size() || i < b.size(); i++)
    {
        c.push_back(a.at(i));
        c.push_back(b.at(i));
    }
    return c;
}



//FUNCION SEMILLA IFSR

template<typename Type>
string lfsr(int tam, string semilla)
{
    string cad;
    if(semilla.empty())
    {cad = keyGenerator<void>(tam) ;}
    else
    {
     cad = semilla;
    }
    int a = tam/2;
    string res;
    int mitad = cad.size()/2;

    int tab = 1;
    vector<string> cadena;

    cadena.push_back(cad.substr(0,mitad));
    cadena.push_back(cad.substr(mitad,cad.length()));

    string temp1, temp2;

    for(int i = 0; i < a; i++){

        temp2 = cadena[0];
        temp1 = temp2.substr(1,temp2.length());
        temp1 += XOR<void>(temp2[0],temp2[tab]);
        cadena[0] = temp1;
        //cout << "IZQUIERDA: " << temp1 << endl;
    }

    temp1.clear();
    tab = temp1.length();

    for(int j = 0; j < a; j++){

        temp2 = cadena[1];
        temp1 = XOR<void>(temp2[temp2.length()],temp2[tab]);
        temp1 += temp2.substr(0,temp2.length()-1);
        cadena[1] = temp1;

        //cout << "DERECHA: " << temp1 << endl;

    }
    res = vectToString<void>(cadena);
    return res;

}





#endif // FUNCIONES_H

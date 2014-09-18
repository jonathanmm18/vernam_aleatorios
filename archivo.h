#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace  std;
ostream& operator << (ostream &o,const vector <string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        o << i << '\t' << v[i] << '\n';
    }

    return o;
}
void Write(vector <string> fuente, string fileName)
{
    ofstream myfile;
    //myfile.open ("/home/harry/build-filesC-Desktop-Debug");
    myfile.open (fileName);

    for(unsigned int i = 0; i < fuente.size() ; i++)
    {
        myfile  <<fuente[i] << '\n';

    }
        myfile.close();

}

vector <string> Read(string fileName)
{
    ifstream readfile(fileName);
    vector <string> lineas;
    string d;
    if (readfile.is_open())
     {
       while ( getline (readfile,d) )
       {
         lineas.push_back(d);
         //cout << d << endl;
       }
       readfile.close();
   }
    return lineas;
}

#endif // ARCHIVO_H


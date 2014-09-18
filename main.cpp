#include <QCoreApplication>
#include "vernam.h"
#include "archivo.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  string mensaje;

    cout << "MENSAJE: " << endl;
    getline(std::cin, mensaje);
    //vernam verm(mensaje.size());
    vernam verm(mensaje.size(),"asd");
    string ci,des;
    ci = verm.cifrado(mensaje);
    cout << "CIFRADO: " << ci << endl;
    des = verm.decifrado(ci);
    cout << "DESCIFRADO: " << des << endl;


    /*****/

    vector<string> fuente;
    fuente.push_back(ci);


    fuente.push_back(verm.key);
    string fileName("key.vern");

    Write(fuente,fileName);

   // cout <<"descifrado: " <<verm.decifrado(ci) << endl;






    return a.exec();
}

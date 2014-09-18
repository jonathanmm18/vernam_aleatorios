#include "vernam.h"
#include "aleatorios.h"
vernam::vernam(int tam)
{
    //key = lfsr<void>(tam*8,"") ;
    aleatorios al(4,tam*8,2,10,1,4);
    key = al.getAleatorio() ;
    cout << "key: " << key << endl;
    cout << endl;
}

vernam::vernam(int tam,string semilla)
{
    vector<int> ascci ;
    vector<string> binary;
    string s;


    //CAMBIAMOS DE STRING A ASCCI Y LUEGO A VECTOR DE INT Y A UN STRING DE BINARIOS
    ascci = StringToAscii<void>(semilla);
    binary = AsciiToBin<void>(ascci);
    s = vectToString<void>(binary);
    s = keyGenerator<void>(tam*8,s);

    aleatorios al(4,tam*8,2,10,1,4);
    key = al.getAleatorio() ;
    cout << "key: " << key << endl;

}
string vernam::cifrado(string m)
{
            mensaje = m;
            vector<int> ascci ;
            vector<string> binary;
            string cifrado, men;

            //CAMBIAMOS DE STRING A ASCCI Y LUEGO A VECTOR DE INT Y A UN STRING DE BINARIOS
            ascci = StringToAscii<void>(mensaje);
            binary = AsciiToBin<void>(ascci);

            men = vectToString<void>(binary);
            //GENERAMOS LA LLAVE DEL TAMAÑO DEL MENSAJE

  //          cout << "keyGenerator: " << key << endl;

           //HACEMOS EL XOR PARA CIFRAR
             cout << "mensaje: " << mensaje << endl;
             cout << "ascci: " << ascci << endl;
             cout << "bin: " << binary << endl;


             cifrado = SumaXOR<void>(men,key);
             vector<string> cifr = en_bloques<string>(cifrado,8);
             cout << "cifrado en bits: " << cifr << endl;
             cifrado = BintoAscci<void>(cifr);

  //          cout << "cifrado: " << cifrado << endl;

            return cifrado;
}
string vernam::decifrado(string cifrado)
{
   // vector<string> binary = en_bloques<string>(cifrado,8);
    vector<int> ascci ;
    vector<string> binary;

    ascci = StringToAscii<void>(cifrado);

    binary = AsciiToBin<void>(ascci);

    string des = vectToString<void>(binary);
    des =  SumaXOR<void>(des,key);

    vector<string> decifrado = en_bloques<string>(des,8);
    des = BintoAscci<void>(decifrado);


    return des;

}

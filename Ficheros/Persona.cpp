#include <iostream>
#include <fstream>
using namespace std;

/*
// Definimos una estructura para guardar datos de una persona
struct Persona
{
    char nombre[50];
    int edad;
};

int main()
{
    // Creamos un objeto Persona
    Persona p = { "Victor Dominguez", 19 };

    // Guardamos la estructura en un archivo binario
    ofstream out("persona.dat", ios::binary); // ios::binary = modo binario
    out.write((char*)&p, sizeof(Persona));    // write = escribir bytes
    out.close();

    // Leemos la estructura desde el archivo binario
    Persona q;
    ifstream in("persona.dat", ios::binary);
    in.read((char*)&q, sizeof(Persona));      // read = Leer bytes
    in.close();

    // Mostramos los datos recuperados
    cout << "Nombre: " << q.nombre << ", Edad: " << q.edad << endl;
    return 0;
}
*/
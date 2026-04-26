#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	//crear un archivo de texto para escritura 
	ofstream archivo("datos.txt");			
	archivo << "Hola como estan" << endl;
	archivo << "18-09-2006" << endl;
	archivo.close();

	ifstream leer("datos.txt");
	string linea;
	while (getline (leer, linea))
	{ //leer linea por linea
		cout << linea << endl; //mostrar en pantalla
	}
	leer.close();	//cerreamos el archivo
	return 0;
}

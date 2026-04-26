#include <iostream>
#include "search.h"
using namespace std;

int busquedaSecuencial(int arreglo[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        cout << "  -> Busqueda Secuencial: Comparando valor buscado (" << valor << ") con arreglo[" << i << "] = " << arreglo[i] << endl;
        if (arreglo[i] == valor)
        {
            return i;  // devuelve posición
        }
    }
    return -1; // no encontrado
}

int busquedaBinaria(int arreglo[], int n, int valor)
{
    int izquierda = 0;
    int derecha = n - 1;
    int medio;

    while (izquierda <= derecha)
    {
        medio = (izquierda + derecha) / 2;
        cout << "  -> Busqueda Binaria: Revisando la mitad en posicion [" << medio << "] = " << arreglo[medio] << endl;

        if (arreglo[medio] == valor)
        {
            return medio;
        }
        else if (arreglo[medio] < valor)
        {
            cout << "     El valor es mayor. Descartando la mitad izquierda.\n";
            izquierda = medio + 1;
        }
        else
        {
            cout << "     El valor es menor. Descartando la mitad derecha.\n";
            derecha = medio - 1;
        }
    }
    return -1;
}
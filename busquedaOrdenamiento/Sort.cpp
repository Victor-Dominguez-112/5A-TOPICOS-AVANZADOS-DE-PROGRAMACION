#include <iostream>
#include "sort.h"
#include "view.h" // Necesario para usar mostrarArreglo()

using namespace std;

void ordenarBurbuja(int arreglo[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "\n--- Pasada " << i + 1 << " ---\n";
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "Comparando " << arreglo[j] << " y " << arreglo[j + 1] << "... ";
            if (arreglo[j] > arreglo[j + 1])
            {
                cout << "Se intercambian!";
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
            else {
                cout << "Se quedan igual.";
            }
            cout << endl;
        }
        mostrarArreglo(arreglo, n); // Muestra cómo queda el arreglo tras cada pasada completa
    }
}

void ordenarInsercion(int arreglo[], int n)
{
    int i, j, clave;
    for (i = 1; i < n; i++)
    {
        clave = arreglo[i];
        j = i - 1;

        cout << "\nInsertando el valor " << clave << " (posicion " << i << ")\n";

        while (j >= 0 && arreglo[j] > clave)
        {
            cout << "  Moviendo " << arreglo[j] << " a la derecha.\n";
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
        mostrarArreglo(arreglo, n);
    }
}

// ... (Aplica impresiones similares en Selección, QuickSort y MergeSort) ...
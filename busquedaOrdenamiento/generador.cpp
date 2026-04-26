#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm> // Para std::random_shuffle
#include "generador.h"
using namespace std;

void generarAleatorios(int arreglo[], int tamaño, bool conRepeticion, int maxValor)
{
    // Inicializar la semilla para los números aleatorios
    srand(time(NULL));

    if (conRepeticion)
    {
        cout << "Generando " << tamaño << " numeros CON repeticion...\n";
        for (int i = 0; i < tamaño; i++)
        {
            arreglo[i] = rand() % maxValor + 1; // Números del 1 al maxValor
        }
    }
    else
    {
        cout << "Generando " << tamaño << " numeros SIN repeticion...\n";
        if (tamaño > maxValor) {
            cout << "Error: El tamaño no puede ser mayor que el rango máximo si no hay repeticiones.\n";
            return;
        }

        // Creamos un "pool" de números y los mezclamos para evitar repeticiones
        vector<int> pool;
        for (int i = 1; i <= maxValor; i++) {
            pool.push_back(i);
        }

        random_shuffle(pool.begin(), pool.end());

        for (int i = 0; i < tamaño; i++)
        {
            arreglo[i] = pool[i];
        }
    }
}
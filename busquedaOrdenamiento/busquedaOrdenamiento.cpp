#include <iostream>
using namespace std;

#include "search.h"
#include "sort.h"
#include "view.h"
#include "generador.h"
int main()
{
    int opcion;
    int metodo;
    int* arreglo = nullptr; // Apuntador dinámico para manejar tamaños variables
    int n = 0;
    int posicion, valor;
    int comparaciones = 0, intercambios = 0;

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Generar nuevo arreglo (N, N*N, N*M)" << endl;
        cout << "2. Busqueda Secuencial" << endl;
        cout << "3. Busqueda Binaria (ordena automaticamente)" << endl;
        cout << "4. Ordenar Arreglo" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int tipoTam, filas, columnas, maxVal, rep;
            bool conRepeticion;

            cout << "Tipo de tamaño:\n1. N (Lineal)\n2. N*N (Matriz Cuadrada)\n3. N*M (Matriz Rectangular)\nOpcion: ";
            cin >> tipoTam;

            if (tipoTam == 1) {
                cout << "Ingrese N: "; cin >> n;
            }
            else if (tipoTam == 2) {
                cout << "Ingrese N para matriz N*N: "; cin >> filas;
                n = filas * filas;
            }
            else {
                cout << "Ingrese N (filas): "; cin >> filas;
                cout << "Ingrese M (columnas): "; cin >> columnas;
                n = filas * columnas;
            }

            cout << "Permitir numeros repetidos? (1 = Si, 0 = No): ";
            cin >> rep;
            conRepeticion = (rep == 1);

            cout << "Cual sera el valor maximo a generar? (Ej. 100): ";
            cin >> maxVal;

            // Liberar memoria si ya existía un arreglo
            if (arreglo != nullptr) delete[] arreglo;

            // Reservar nueva memoria
            arreglo = new int[n];

            generarAleatorios(arreglo, n, conRepeticion, maxVal);
            mostrarArreglo(arreglo, n);
            break;
        }

        case 2:
            if (arreglo == nullptr) { cout << "Primero genera un arreglo.\n"; break; }
            mostrarArreglo(arreglo, n);
            valor = pedirValor();
            posicion = busquedaSecuencial(arreglo, n, valor);
            if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;

            // ... (Tus casos originales 2 y 3 pasan a ser 3 y 4 respectivamente) ...

        case 5:
            cout << "Saliendo...\n";
            if (arreglo != nullptr) delete[] arreglo; // Liberar memoria al final
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}
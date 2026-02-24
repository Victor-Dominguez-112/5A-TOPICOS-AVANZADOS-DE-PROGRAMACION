/**
 * @file main.cpp
 * @brief Punto de entrada principal para el programa Orientado a Objetos (POO).
 */
#include <iostream>
#include <chrono>
#include "Arreglo.h"
using namespace std;

// Función para medir tiempo en microsegundos
/**
 * @brief Funcion plantilla (template) para medir el tiempo de ejecucion en microsegundos.
 * * Esta version utiliza 'forward' para soportar expresiones lambda con multiples argumentos,
 * haciendola mas robusta y escalable que la version base.
 * * @tparam Func El tipo de dato deducido de la funcion/lambda a ejecutar.
 * @tparam Args Paquete de parametros deducidos (variadic templates) que recibe la funcion.
 * @param funcion La funcion o expresion lambda que se desea medir.
 * @param args Los argumentos que se pasaran a la funcion.
 * @return double El tiempo total que tardo en ejecutarse la funcion, expresado en microsegundos.
 */
template<typename Func, typename... Args>
double medirTiempo(Func funcion, Args&&... args) 
{
    auto inicio = chrono::high_resolution_clock::now();
    funcion(forward<Args>(args)...);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duracion = fin - inicio;
    return duracion.count();
}

/**
 * @brief Funcion principal que instancia un objeto de tipo Arreglo y maneja la interaccion.
 * @return int Codigo de salida estandar (0 para exito).
 */
int main() {
    Arreglo miArreglo;
    int opcion, metodo;
    int valor, posicion;
    int comparaciones = 0, intercambios = 0;

    do {
        miArreglo.mostrarMenu();
        cin >> opcion;

        switch (opcion) 
        {
        case 1: // Busqueda secuencial
            miArreglo.mostrarArreglo();
            valor = miArreglo.pedirValor();
            {
                double tiempo = medirTiempo([&]() {
                    posicion = miArreglo.busquedaSecuencial(valor);
                    });
                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                cout << "Tiempo de ejecucion: " << tiempo << " microsegundos.\n";
            }
            break;

        case 2: // Busqueda binaria (ordenar primero)
            cout << "\nOrdenando arreglo...\n";
            {
                double tiempoOrden = medirTiempo([&]() { miArreglo.ordenarBurbuja(); });
                cout << "Tiempo de ordenamiento: " << tiempoOrden << " microsegundos.\n";
            }
            miArreglo.mostrarArreglo();
            valor = miArreglo.pedirValor();
            {
                double tiempoBusq = medirTiempo([&]() { posicion = miArreglo.busquedaBinaria(valor); });
                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                cout << "Tiempo de busqueda binaria: " << tiempoBusq << " microsegundos.\n";
            }
            break;

        case 3: // Ordenamiento
            metodo = miArreglo.mostrarMenuOrdenamiento();
            comparaciones = intercambios = 0;
            if (metodo == 1) {
                double t = medirTiempo([&]() { miArreglo.ordenarBurbuja(); });
                cout << "Tiempo de Burbuja: " << t << " microsegundos.\n";
            }
            else if (metodo == 2) {
                double t = medirTiempo([&]() { miArreglo.ordenarSeleccion(); });
                cout << "Tiempo de Seleccion: " << t << " microsegundos.\n";
            }
            else if (metodo == 3) {
                double t = medirTiempo([&]() { miArreglo.ordenarInsercion(); });
                cout << "Tiempo de Insercion: " << t << " microsegundos.\n";
            }
            else if (metodo == 4) {
                double t = medirTiempo([&]() { miArreglo.quickSort(0, miArreglo.getN() - 1, comparaciones, intercambios); });
                cout << "Tiempo QuickSort: " << t << " microsegundos.\n";
                cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
            }
            else if (metodo == 5) {
                double t = medirTiempo([&]() { miArreglo.mergeSort(0, miArreglo.getN() - 1, comparaciones); });
                cout << "Tiempo MergeSort: " << t << " microsegundos.\n";
                cout << "Comparaciones: " << comparaciones << endl;
            }
            else {
                cout << "Metodo invalido.\n";
            }
            cout << "Arreglo ordenado:\n";
            miArreglo.mostrarArreglo();
            break;

        case 4: // Aleatorios con repetición
        {
            int tamaño, maxVal;
            cout << "Ingrese tamaño del arreglo: "; cin >> tamaño;
            cout << "Ingrese valor máximo: "; cin >> maxVal;
            double t = medirTiempo([&]() { miArreglo.generarAleatoriosConRepeticion(tamaño, maxVal); });
            cout << "Tiempo de generacion: " << t << " microsegundos.\n";
        }
        break;

        case 5: // Aleatorios sin repetición
        {
            int tamaño, maxVal;
            cout << "Ingrese tamaño del arreglo: "; cin >> tamaño;
            cout << "Ingrese valor máximo: "; cin >> maxVal;
            double t = medirTiempo([&]() { miArreglo.generarAleatoriosSinRepeticion(tamaño, maxVal); });
            cout << "Tiempo de generacion: " << t << " microsegundos.\n";
        }
        break;

        case 6:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}
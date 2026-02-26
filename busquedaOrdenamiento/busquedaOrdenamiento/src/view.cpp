/**
 * @file view.cpp
 * @brief Implementacion de las funciones para imprimir menus y resultados en la consola.
 */

#include <iostream>
using namespace std;
#include "view.h"

// Menú principal con nuevas opciones de generación de números
/**
 * @brief Imprime en pantalla el menu principal del sistema.
 * * Muestra las opciones disponibles para buscar, ordenar o generar arreglos.
 */
void mostrarMenu()
{
    cout << "\n=== MENU ===\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)\n";
    cout << "3. Ordenar Arreglo\n";
    cout << "4. Generar numeros aleatorios CON repeticion\n";
    cout << "5. Generar numeros aleatorios SIN repeticion\n";
    cout << "6. Salir\n";
    cout << "Seleccione opcion: ";
}

// Muestra el arreglo en pantalla
/**
 * @brief Imprime todos los elementos de un arreglo en una sola linea.
 * * @param arreglo El arreglo que se va a mostrar.
 * @param n El tamaño actual del arreglo.
 */
void mostrarArreglo(int arreglo[], int n)
{
    cout << "\nArreglo: ";
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Solicita al usuario un valor para buscar
/**
 * @brief Solicita al usuario por teclado un valor numerico para realizar una busqueda.
 * * @return int El valor ingresado por el usuario.
 */
int pedirValor()
{
    int valor;
    cout << "Ingrese valor a buscar: ";
    cin >> valor;
    return valor;
}

// Menú de métodos de ordenamiento
/**
 * @brief Imprime en pantalla el sub-menu con los algoritmos de ordenamiento disponibles.
 * * Captura la seleccion del usuario y la devuelve.
 * * @return int El numero de la opcion seleccionada (1 al 5).
 */
int mostrarMenuOrdenamiento()
{
    int opcion;
    cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
    cout << "1. Burbuja\n";
    cout << "2. Seleccion\n";
    cout << "3. Insercion\n";
    cout << "4. QuickSort\n";
    cout << "5. MergeSort\n";
    cout << "Seleccione metodo: ";
    cin >> opcion;
    return opcion;
}
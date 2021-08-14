#include <iostream>
#include "Empresa.h"
#include "Servicios.h"
#include "ABB.h"
#include "PrioritySearchTree.h"

using namespace std;

int main()
{
    unsigned int tamanioArreglo;
    ABB * Arbol = new ABB();
    Empresa * Arreglo = Procesar_Archivo_Entrada("Ranking.csv",tamanioArreglo,Arbol);
    PrioritySearchTree * ArbolPrioridad = new PrioritySearchTree();
    ArbolPrioridad->ConstruirArbol(Arreglo,0,tamanioArreglo);
    Resolver(Arreglo,Arbol,ArbolPrioridad,tamanioArreglo);
    delete [] Arreglo; //Eliminamos el arreglo para que no quede espacio ocupado en la memoria
    delete Arbol;
    delete ArbolPrioridad;
    return 0;
}




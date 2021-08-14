#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "Empresa.h"
#include "ABB.h"
#include "ListaSimple.h"
#include "PrioritySearchTree.h"

void Menu(unsigned int & Opcion);
void ObtenerPosicion(ABB * Arbol,string & razonSocial,unsigned int & Posicion);
void ObtenerInfo(Empresa * Arreglo,unsigned int & posicion,unsigned int tamanioArreglo,Empresa & Informacion);
void ListarEmpresas(Empresa * Arreglo, unsigned int tamanioArreglo);
void MostrarLista(ListaSimple<Empresa *> ListaEmpleados);
void ListarEmpresasPST(PrioritySearchTree * ArbolPrioridad,ListaSimple<Empresa *> & S, unsigned int tamanioArreglo);
void Resolver(Empresa * Arreglo,ABB * Arbol,PrioritySearchTree * ArbolPrioridad, unsigned int tamanioArreglo);
Empresa * Procesar_Archivo_Entrada(string origen, unsigned int & tamanioArreglo,ABB * & arbol); // Procesa el archivo y carga las estructuras (arreglo y árbol)

#endif // SERVICIOS_H_INCLUDED

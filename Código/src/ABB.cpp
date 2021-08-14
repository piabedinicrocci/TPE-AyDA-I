#include "ABB.h"
#include <iostream>

using namespace std;

ABB::ABB()
{
	Raiz = NULL;
}

void ABB::EliminarArbol(NodoArbol * Raiz)
{
    if(Raiz != NULL){
		EliminarArbol(Raiz->izq);
		EliminarArbol(Raiz->der);
		delete Raiz;}
}

ABB::~ABB()
{
    EliminarArbol(Raiz);
}

void ABB::crearNodo(NodoArbol * & Nuevo, Empresa * puntEmpresa)
{
    Nuevo = new NodoArbol;
    Nuevo->puntArreglo = puntEmpresa;
    Nuevo->izq = NULL;
    Nuevo->der = NULL;
}

void ABB::InsertarNodo(NodoArbol * & Raiz,Empresa * puntEmpresa)
{
    if (Raiz == NULL)
    {
       crearNodo(Nuevo,puntEmpresa);
       Raiz = Nuevo;}
    else if (Raiz->puntArreglo->obtenerRazonSocial() > puntEmpresa->obtenerRazonSocial())
        InsertarNodo(Raiz->izq,puntEmpresa);
    else
        InsertarNodo(Raiz->der,puntEmpresa);
}

void ABB::InsertarNodo(Empresa * puntEmpresa)
{
	if(Raiz == NULL){
        crearNodo(Nuevo,puntEmpresa);
        Raiz = Nuevo;}
    else{
        InsertarNodo(Raiz,puntEmpresa);
	}
}

unsigned int ABB:: obtenerPosicion(NodoArbol * & Raiz, string razonSocial)
{
    if (Raiz == NULL)
        return 0;
    else if (Raiz->puntArreglo->obtenerRazonSocial() < razonSocial)
        return obtenerPosicion(Raiz->der,razonSocial);
    else if (Raiz->puntArreglo->obtenerRazonSocial() > razonSocial)
        return obtenerPosicion(Raiz->izq,razonSocial);
    else if (Raiz->puntArreglo->obtenerRazonSocial() == razonSocial)
        return Raiz->puntArreglo->obtenerPosRanking();
}

unsigned int ABB:: obtenerPosicion(string razonSocial)
{
    if (Raiz == NULL)
        return 0;
    else
        return obtenerPosicion(Raiz,razonSocial);
}

void ABB::MostrarArbol(NodoArbol *Raiz) //MostrarArbol no se utilizó para resolver los servicios, simplemente nos permitió verificar que la carga se realizaba exitosamente
{
	if(Raiz != NULL){
		MostrarArbol(Raiz->izq);
		cout << Raiz->puntArreglo->obtenerRazonSocial() << " | ";
		MostrarArbol(Raiz->der);
	}
}

void ABB::MostrarArbol()
{
	MostrarArbol(Raiz);
}

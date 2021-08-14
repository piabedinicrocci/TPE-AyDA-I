#include "ListaSimple.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
ListaSimple<T>::ListaSimple()
{
    Primero = NULL;
}

template <typename T>
ListaSimple<T>::~ListaSimple()
{
    while(Primero != NULL){
        Borrar = Primero->sig;
        delete Primero;
		Primero = Borrar;}
    Primero = NULL;
}

template <typename T>
void ListaSimple<T>::crearNodoLista(NodoLista * & Nuevo,T & puntEmpresa)
{
    Nuevo = new NodoLista;
    Nuevo->puntArreglo = puntEmpresa;
    Nuevo->sig = NULL;
}

template <typename T>
void ListaSimple<T>::Agregar(NodoLista * & NodoSig,T & puntEmpresa)
{
    if(NodoSig == NULL){
        crearNodoLista(Nuevo,puntEmpresa);
        NodoSig = Nuevo;}
    else
        Agregar(NodoSig->sig,puntEmpresa);
}

template <typename T>
void ListaSimple<T>::Agregar(T & puntEmpresa)
{
    if(Primero == NULL){
        crearNodoLista(Nuevo,puntEmpresa);
        Primero = Nuevo;}
    else
        Agregar(Primero->sig,puntEmpresa);
}

template <typename T>
bool ListaSimple<T>::Vacia(NodoLista * Primero) const
{
    if (Primero == NULL)
        return true;
    else
        return false;
}

template <typename T>
bool ListaSimple<T>::Vacia() const
{
    return Vacia(Primero);
}

template <typename T>
void ListaSimple<T>::IniciarCursor()
{
    Cursor = Primero;
}

template <typename T>
void ListaSimple<T>::AvanzarCursor()
{
    assert(!CursorEsFinal());
    Cursor = Cursor->sig;
}

template <typename T>
bool ListaSimple<T>::CursorEsFinal() const
{
    return (Cursor==NULL);
}

template <typename T>
Empresa * ListaSimple<T>::ObtenerDesdeCursor()
{
    assert(!CursorEsFinal());
    return Cursor->puntArreglo;
}

template class ListaSimple<Empresa *>;

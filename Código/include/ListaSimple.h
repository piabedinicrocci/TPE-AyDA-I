#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Empresa.h"

template <typename T>
class ListaSimple{

public:

    ListaSimple();
    ~ListaSimple();
    void Agregar(T & puntEmpresa);
    bool Vacia() const;
    void IniciarCursor();
    void AvanzarCursor();
    bool CursorEsFinal() const;
    Empresa * ObtenerDesdeCursor();

private:

    struct NodoLista{
	T puntArreglo;
	NodoLista * sig;
    };
    void crearNodoLista(NodoLista * & Nuevo,T & puntEmpresa);
    void Agregar(NodoLista * & Primero,T & puntEmpresa);
    bool Vacia(NodoLista * Primero) const;
    NodoLista * Primero;
    NodoLista * Nuevo;
    NodoLista * Cursor;
    NodoLista * Borrar;
};

#endif // LISTASIMPLE_H

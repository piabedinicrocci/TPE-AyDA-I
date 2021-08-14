#ifndef ABB_H
#define ABB_H
#include "Empresa.h"

class ABB{

public:

	ABB();
	~ABB();
	void InsertarNodo(Empresa * puntEmpresa);
	unsigned int obtenerPosicion(string razonSocial);
	void MostrarArbol();

private:

    struct NodoArbol{
        Empresa * puntArreglo;
        NodoArbol *izq;
        NodoArbol *der;
    };
    void crearNodo(NodoArbol * & Nuevo, Empresa * puntEmpresa);
	void InsertarNodo(NodoArbol * & Raiz, Empresa * puntEmpresa);
	unsigned int obtenerPosicion(NodoArbol * & Raiz, string razonSocial);
	void MostrarArbol(NodoArbol * Raiz);
	void EliminarArbol(NodoArbol * Raiz);
	NodoArbol * Raiz;
	NodoArbol * Nuevo;
};

#endif // ABB_H

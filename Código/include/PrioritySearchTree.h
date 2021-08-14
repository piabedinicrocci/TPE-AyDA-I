#ifndef PRIORITYSEARCHTREE_H
#define PRIORITYSEARCHTREE_H
#include "Empresa.h"
#include "ListaSimple.h"


class PrioritySearchTree
{
    public:
        PrioritySearchTree();
        void ConstruirArbol(Empresa * ArregloOriginal, int inicio, int fin);
        void BuscarPST(int P, int MIN, int MAX,ListaSimple<Empresa *> & S);
        virtual ~PrioritySearchTree();

    private:
        struct NodoPST{
        Empresa * puntEmpresa;
        float Mediana;
        NodoPST * der;
        NodoPST * izq;};
        NodoPST * CrearArbol(Empresa * Arreglo[], int inicio, int fin);
        void CrearNodoPST(Empresa * Dato, float Mediana, NodoPST * & NodoNuevo);
        int ElementoMenorPrioridad(Empresa * Arreglo[], int inicio, int fin);
        void CorrimientoDerecha(Empresa * Arreglo[], int inicio, int limite, Empresa * Dato);
        float CalcularMediana(Empresa * Arreglo[], int inicio, int fin);
        void EliminarArbol(NodoPST * Raiz);
        int IzquierdaAMediana(Empresa * Arreglo[], int inicio, float Mediana);
        bool Eshoja(NodoPST * Raiz) const;
        void BuscarPST(NodoPST * Nodo,int P, int MIN, int MAX,ListaSimple<Empresa *> & S);
        int UbicarPivote(Empresa * Arreglo[], int ini, int fin);
        void OrdenarPorQuicksort(Empresa * Arreglo[], int ini, int fin);
        void CopiarArreglo(Empresa * arreglo, Empresa * auxiliar[], int tamanio_arreglo);
        NodoPST * Raiz;
        NodoPST * Nodo;
};

#endif // PRIORITYSEARCHTREE_H

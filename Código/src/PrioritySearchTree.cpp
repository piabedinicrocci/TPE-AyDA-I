#include "PrioritySearchTree.h"
#include "ListaSimple.h"
#include "Empresa.h"

PrioritySearchTree::PrioritySearchTree()
{
    Raiz = NULL;
}

void PrioritySearchTree::BuscarPST(NodoPST * Nodo ,int P, int MIN, int MAX,ListaSimple<Empresa *> & S)
{
    if(Nodo != NULL){
        if (Eshoja(Nodo)){
            if ((Nodo->puntEmpresa->obtenerPosRanking() <= P) && (MIN <= Nodo->puntEmpresa->obtenerCantEmpleados()) && (Nodo->puntEmpresa->obtenerCantEmpleados() <= MAX))
                S.Agregar(Nodo->puntEmpresa);}
        else
            if (Nodo->puntEmpresa->obtenerPosRanking() <= P){
                if ((MIN <= Nodo->puntEmpresa->obtenerCantEmpleados()) && (Nodo->puntEmpresa->obtenerCantEmpleados() <= MAX))
                    S.Agregar(Nodo->puntEmpresa);
                if (MIN < Nodo->Mediana)
                    BuscarPST(Nodo->izq,P,MIN,MAX,S);
                if (MAX >= Nodo->Mediana)
                    BuscarPST(Nodo->der,P,MIN,MAX,S);}}
}

void PrioritySearchTree::BuscarPST(int P, int MIN, int MAX, ListaSimple<Empresa *> & S)
{
    if(Raiz != NULL){
        if (Eshoja(Raiz)){
            if ((Raiz->puntEmpresa->obtenerPosRanking() <= P) && (MIN <= Raiz->puntEmpresa->obtenerCantEmpleados()) && (Nodo->puntEmpresa->obtenerCantEmpleados() <= MAX))
                S.Agregar(Raiz->puntEmpresa);}
        else
            if (Raiz->puntEmpresa->obtenerPosRanking() <= P){
                if ((MIN <= Raiz->puntEmpresa->obtenerCantEmpleados()) && (Raiz->puntEmpresa->obtenerCantEmpleados() <= MAX))
                    S.Agregar(Raiz->puntEmpresa);
                if (MIN < Raiz->Mediana)
                    BuscarPST(Raiz->izq,P,MIN,MAX,S);
                if (MAX >= Raiz->Mediana)
                    BuscarPST(Raiz->der,P,MIN,MAX,S);}}
}

int PrioritySearchTree::UbicarPivote(Empresa * Arreglo[], int ini, int fin)
{
    Empresa * Copia;
    while(ini<fin){
        while(((Arreglo[fin]->obtenerCantEmpleados()) >= (Arreglo[ini]->obtenerCantEmpleados()))&& (ini<fin))
            fin--;
        Copia=new Empresa();
        *Copia=*Arreglo[fin];
        *Arreglo[fin]=*Arreglo[ini];
        *Arreglo[ini]=*Copia;
        while((Arreglo[ini]->obtenerCantEmpleados() <= Arreglo[fin]->obtenerCantEmpleados())&& (ini<fin))
            ini++;
        Copia=new Empresa();
        *Copia=*Arreglo[ini];
        *Arreglo[ini]=*Arreglo[fin];
        *Arreglo[fin]=*Copia;}
    return ini;
}

void PrioritySearchTree::OrdenarPorQuicksort(Empresa * Arreglo[], int ini, int fin)
{
    if(ini<fin){
        int PosCorrectaPiv = UbicarPivote(Arreglo,ini,fin);
        OrdenarPorQuicksort(Arreglo,ini,PosCorrectaPiv-1);
        OrdenarPorQuicksort(Arreglo,PosCorrectaPiv+1,fin);}
}

void PrioritySearchTree::CopiarArreglo(Empresa * arreglo, Empresa * auxiliar[], int tamanio_arreglo)
{
    for (int i = 0; i < tamanio_arreglo; i++) {
        //auxiliar[i].prioridad = i + 1;
        auxiliar[i] = new Empresa();
        *auxiliar[i] = arreglo[i];
    }
}

void PrioritySearchTree::CrearNodoPST(Empresa * Dato, float Mediana,NodoPST * & NodoNuevo)
{
    NodoNuevo = new NodoPST;
    NodoNuevo->puntEmpresa = Dato;
    NodoNuevo->Mediana = Mediana;
    NodoNuevo->izq = NULL;
    NodoNuevo->der = NULL;
}

int PrioritySearchTree::ElementoMenorPrioridad(Empresa * Arreglo[], int inicio, int fin)
{
    int menor = inicio;
    inicio++;
    while (inicio <= fin) {
        if (Arreglo[inicio]->obtenerPosRanking() < Arreglo[menor]->obtenerPosRanking())
            menor = inicio;
        inicio++;}
    return menor;
}

void PrioritySearchTree::CorrimientoDerecha(Empresa * Arreglo[], int inicio, int limite, Empresa * Dato)
{
    for (limite; limite > inicio; limite--)
        Arreglo[limite] = Arreglo[limite-1];
    Arreglo[inicio] = Dato;
}

float PrioritySearchTree::CalcularMediana(Empresa * Arreglo[], int inicio, int fin)
{
    if ((fin - inicio + 1)%2 == 0)
        return (Arreglo[fin - ((fin - inicio + 1)/2)]->obtenerCantEmpleados() + Arreglo[fin - ((fin - inicio + 1)/2) + 1]->obtenerCantEmpleados())/2.0;
    else
        return Arreglo[(fin - (fin - inicio)/2)]->obtenerCantEmpleados();
}

int PrioritySearchTree::IzquierdaAMediana(Empresa * Arreglo[], int inicio, float Mediana)
{
    if (Arreglo[inicio]->obtenerCantEmpleados() < Mediana){
        int i = inicio;
        while (Arreglo[i]->obtenerCantEmpleados() < Mediana)
            i++;
        return i-1;}
    else
        return -1; //Significa que el valor en esa celda posiblemente sea igual a la mediana y en todas las celdas siguientes tambien
}


PrioritySearchTree::NodoPST* PrioritySearchTree::CrearArbol(Empresa * Arreglo[], int inicio, int fin)
{
    if (inicio <= fin)
    {
        int PosicionMenorPrioridad = ElementoMenorPrioridad(Arreglo, inicio, fin);
        CorrimientoDerecha(Arreglo, inicio, PosicionMenorPrioridad, Arreglo[PosicionMenorPrioridad]);
        float Mediana = -1;
        if (inicio < fin)
            Mediana = CalcularMediana(Arreglo, inicio + 1, fin);
        NodoPST * NodoNuevo;
        CrearNodoPST(Arreglo[inicio], Mediana,NodoNuevo);
        if (inicio < fin){
            int MenorAMediana = IzquierdaAMediana(Arreglo,inicio + 1,Mediana);
            if (MenorAMediana != -1){
                NodoNuevo->izq = CrearArbol(Arreglo, inicio + 1, MenorAMediana);
                NodoNuevo->der = CrearArbol(Arreglo, MenorAMediana + 1, fin);}
            else
                NodoNuevo->der = CrearArbol(Arreglo, inicio + 1, fin);}
        return NodoNuevo;
    }
    else
        return NULL;
}

void PrioritySearchTree::ConstruirArbol(Empresa * ArregloOriginal, int inicio, int tamanio_arreglo)
{
    Empresa * Auxiliar[tamanio_arreglo];
    CopiarArreglo(ArregloOriginal, Auxiliar, tamanio_arreglo);
    OrdenarPorQuicksort(Auxiliar, 0, tamanio_arreglo-1);
    Raiz = CrearArbol(Auxiliar, inicio, tamanio_arreglo-1);
}

bool PrioritySearchTree::Eshoja(NodoPST * Raiz) const
{
    if ((Raiz->izq == NULL) && (Raiz->der == NULL))
        return true;
    else
        return false;
}

void PrioritySearchTree::EliminarArbol(NodoPST * Raiz)
{
    if(Raiz != NULL){
		EliminarArbol(Raiz->izq);
		EliminarArbol(Raiz->der);
		delete Raiz;}
}

PrioritySearchTree::~PrioritySearchTree()
{
    EliminarArbol(Raiz);
}


#include <fstream>
#include "ABB.h"
#include "Servicios.h"
#include "ListaSimple.h"
#include "Empresa.h"
#include "PrioritySearchTree.h"

//Este procedimiento nos muestra el menu y nos pide que elijamos el servicio a realizar
void Menu(unsigned int & Opcion)
{
    cout << endl;
    cout << "BIENVENIDO A CONSULTORIA" << endl;
    cout << "1- Obtener posicion en el ranking de una empresa dada" << endl;
    cout << "2- Obtener informacion de una Empresa dada una posicion" << endl;
    cout << "3- Listar las empresas junto a su posicion en el ranking, que cuentan con un nro de empleados dentro de un rango dado" << endl;
    cout << "4- Listar una cantidad de empresas dada, en un determinado rango, utilizando un Priority Search Tree" << endl;
    cout << "5- Salir" << endl;
    cout << endl;
    cout << "Elija el servicio a realizar: ";
    cin >> Opcion;
    while ((Opcion != 1) && (Opcion != 2) && (Opcion != 3) && (Opcion != 4) && (Opcion != 5)){
        cout << endl;
        cout << "OPCION INVALIDA" << endl;
        cout << endl;
        cout << "Elija el servicio a realizar: ";
        cin >> Opcion;}
    cout << endl;
}

//Este procedimiento nos permite obtener la posicion en el ranking de una empresa determinada a partir de saber su nombre
void ObtenerPosicion(ABB * Arbol,string & razonSocial,unsigned int & PosicionEmpresa)
{
    cout << "Ingrese la razon social de la empresa a conocer su posicion: ";
    cin.ignore();
    getline(cin, razonSocial);
    cout << endl;
    PosicionEmpresa = Arbol->obtenerPosicion(razonSocial);
}
//Este procedimiento nos devuelve un objeto empresa con la información de la empresa que se encuentra en una posición dada
void ObtenerInfo(Empresa * Arreglo,unsigned int & Posicion,unsigned int tamanioArreglo,Empresa & Informacion)
{
    cout << "Ingrese la posicion de la empresa a conocer su informacion: ";
    cin >> Posicion;
    cout << endl;
    if ((Posicion > 0) && (Posicion <= tamanioArreglo))
        Informacion = Arreglo[Posicion-1];
    else
        Posicion = 0;
}

//Este procedimiento nos permite listar las empresas que cuentan con una cantidad de empleados determinada.
void ListarEmpresas(Empresa * Arreglo,ListaSimple<Empresa *> & ListaEmpleados, unsigned int tamanioArreglo)
{
    unsigned int RangoMax;
    unsigned int RangoMin;
    cout << "Ingrese el rango de la cantidad de empleados que desee" << endl;
    cout << "Minimo: ";
    cin >> RangoMin;
    cout << "Maximo: ";
    cin >> RangoMax;
    cout << endl;
    if (RangoMin <= RangoMax){
        cout << "RANGO: [" << RangoMin << "," << RangoMax << "]" << endl;
        for(unsigned int i=0; i<tamanioArreglo; i++){
            if ((Arreglo[i].obtenerCantEmpleados() >= RangoMin) && (Arreglo[i].obtenerCantEmpleados() <= RangoMax)){
                Empresa * puntEmpresa = &Arreglo[i];
                ListaEmpleados.Agregar(puntEmpresa);}}
    }else
        cout << "RANGO INVALIDO" << endl;
}

void ListarEmpresasPST(PrioritySearchTree * ArbolPrioridad,ListaSimple<Empresa *> & S, unsigned int tamanioArreglo)
{
    unsigned int Prioridad;
    unsigned int RangoMax;
    unsigned int RangoMin;
    cout <<  "Cuantas empresas del ranking se van a analizar? " << endl;
    cin >> Prioridad;
    while ((Prioridad <= 0) || (Prioridad > tamanioArreglo)){
        cout << "Ingrese una cantidad valida" << endl;
        cin >> Prioridad;}
    cout << "Ingrese el rango de la cantidad de empleados que desee" << endl;
    cout << "Minimo: ";
    cin >> RangoMin;
    cout << "Maximo: ";
    cin >> RangoMax;
    cout << endl;
    if (RangoMin <= RangoMax){
        cout << "RANGO: [" << RangoMin << "," << RangoMax << "]" << endl;
        ArbolPrioridad->BuscarPST(Prioridad,RangoMin,RangoMax,S);
    }else
        cout << "RANGO INVALIDO" << endl;
}

void MostrarLista(ListaSimple<Empresa *> ListaEmpleados) //O(n)
{
    ListaEmpleados.IniciarCursor(); //O(1)
    while (!(ListaEmpleados.CursorEsFinal())){

        Empresa * Info = (ListaEmpleados.ObtenerDesdeCursor()); //O(1)
        cout << Info->obtenerPosRanking() << " | " << Info->obtenerRazonSocial() << " | " << Info->obtenerCantEmpleados() << endl;
        ListaEmpleados.AvanzarCursor(); //O(1)
    }
}

//Este procedimiento se encarga de mostrar el menú al usuario y ejecutar la opción que este desee
void Resolver(Empresa * Arreglo, ABB * Arbol,PrioritySearchTree * ArbolPrioridad, unsigned int tamanioArreglo)
{
    unsigned int Opcion;
    Menu(Opcion);
    switch(Opcion){
            case 1: {string razonSocial; //SERVICIO 1)
                    unsigned int PosicionEmpresa;
                    ObtenerPosicion(Arbol,razonSocial,PosicionEmpresa);
                    if (PosicionEmpresa != 0)
                        cout << "La empresa " << razonSocial << " se encuentra en la posicion " << PosicionEmpresa << " del ranking." << endl;
                    else
                        cout << "La empresa no se encuentra en el listado" << endl;
                    Resolver(Arreglo,Arbol,ArbolPrioridad,tamanioArreglo);
                    break;}

            case 2: {unsigned int Posicion; //SERVICIO 2)
                    Empresa Informacion;
                    ObtenerInfo(Arreglo,Posicion,tamanioArreglo,Informacion);
                    if (Posicion != 0){
                        cout << "| RAZON SOCIAL | PAIS | CANT EMPLEADOS | RUBRO |" << endl;
                        cout << "   " << Informacion.obtenerRazonSocial() << "  |  " << Informacion.obtenerPais() << "  |  " << Informacion.obtenerCantEmpleados() << "  |  " << Informacion.obtenerRubro() << endl;}
                    else
                        cout << "La posicion ingresada no se encuentra en el ranking." << endl;
                    Resolver(Arreglo,Arbol,ArbolPrioridad,tamanioArreglo);
                    break;}

            case 3: {
                    ListaSimple<Empresa *> ListaEmpleados; //SERVICIO 3)
                    ListarEmpresas(Arreglo,ListaEmpleados,tamanioArreglo);
                    cout << endl;
                    if (ListaEmpleados.Vacia())
                        cout << "No existen empresas con el rango de cantidad de empleados especificado" << endl;
                    else{
                        cout << endl;
                        cout << "Las empresas que tienen una cantidad de empleados dentro del rango son: " << endl;
                        MostrarLista(ListaEmpleados);}
                    Resolver(Arreglo,Arbol,ArbolPrioridad,tamanioArreglo);
                    break;}
            case 4: {
                    ListaSimple<Empresa *> ListaEmpleados;
                    ListarEmpresasPST(ArbolPrioridad,ListaEmpleados,tamanioArreglo);
                    cout << endl;
                    if (ListaEmpleados.Vacia())
                        cout << "No existen empresas con el rango de cantidad de empleados especificado" << endl;
                    else{
                        cout << endl;
                        cout << "Las empresas que tienen una cantidad de empleados dentro del rango son: " << endl;
                        MostrarLista(ListaEmpleados);}
                    Resolver(Arreglo,Arbol,ArbolPrioridad,tamanioArreglo);
                    break;}

            case 5: {cout << "Hasta la proxima!" << endl;
                    break;}
    }
}


/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/
//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
Empresa * Procesar_Archivo_Entrada(string origen, unsigned int & tamanioArreglo, ABB * & Arbol)
{
    ifstream archivo(origen);
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << origen << endl;
        return NULL;}
    else {
        string linea;
        getline(archivo, linea);
        unsigned int cantEmpresas = atoi(linea.c_str());
        tamanioArreglo = cantEmpresas;
        Empresa* Arreglo = new Empresa[cantEmpresas]; //arreglo en el heap, ya no se destruye pq no está en la pila, trabajo con un bloque de memoria continuo en el heap
        cout << "Se cargaron " << cantEmpresas << " empresas." << endl;

        unsigned int posicion = 0;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string razonSocial = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string pais = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int cantEmpleados = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string rubro = linea.substr(pos_inicial, pos_final - pos_inicial);

            unsigned int posRanking = posicion + 1;

            Empresa e(razonSocial, pais, cantEmpleados, rubro, posRanking);
            Arreglo[posicion] = e; //Se carga la estructura de almacenamiento a medida que se recorre el archivo.
            Empresa * puntEmpresa = &Arreglo[posicion];
            Arbol->InsertarNodo(puntEmpresa); //Se carga la estructura de acceso que se utiliza para el 1er servicio.
            posicion++;
        }
        return Arreglo;
    }
}

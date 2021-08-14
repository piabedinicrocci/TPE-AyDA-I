#include "Empresa.h"

Empresa::Empresa()
{
    //ctor
}
Empresa::Empresa(string razonSocial, string pais, unsigned int cantEmpleados, string rubro, unsigned int posRanking)
{
    this->razonSocial = razonSocial;
    this->pais = pais;
    this->cantEmpleados = cantEmpleados;
    this->rubro = rubro;
    this->posRanking = posRanking;
}

string Empresa::obtenerRazonSocial() const
{
    return razonSocial;
}

string Empresa::obtenerPais() const
{
    return pais;
}

unsigned int Empresa::obtenerCantEmpleados() const
{
    return cantEmpleados;
}

string Empresa::obtenerRubro() const
{
    return rubro;
}

unsigned int Empresa::obtenerPosRanking() const
{
    return posRanking;
}

Empresa::~Empresa()
{
    //dtor
}

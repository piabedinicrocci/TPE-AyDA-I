#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>

using namespace std;

class Empresa{

public:

    Empresa();
    virtual ~Empresa();
    Empresa(string razonSocial, string pais, unsigned int cantEmpleados, string rubro, unsigned int posRanking);
    string obtenerRazonSocial() const;
    string obtenerPais() const;
    unsigned int obtenerCantEmpleados() const;
    string obtenerRubro() const;
    unsigned int obtenerPosRanking() const;

private:

    string razonSocial;
    string pais;
    unsigned int cantEmpleados;
    string rubro;
    unsigned int posRanking;
};

#endif // EMPRESA_H

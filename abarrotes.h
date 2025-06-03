// Clase Abarrotes
#ifndef ABARROTES_H
#define ABARROTES_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

class Abarrotes : public Producto {
private:
    string marca;
    string empaque;
    DiaCalendario fCaducidad;

public:
    Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f);

    string getMarca() const;
    string getEmpaque() const;
    DiaCalendario getFcaducidad() const;

    void setMarca(string);
    void setEmpaque(string);
    void setFcaducidad(DiaCalendario);

    void mostrarFcaducidad() const;
    void mostrarInfo() const override;
};

Abarrotes::Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f)
    : Producto(n, c, cr, u, f), marca(m), empaque(e), fCaducidad(f) {}

string Abarrotes::getMarca() const { return marca; }
string Abarrotes::getEmpaque() const { return empaque; }
DiaCalendario Abarrotes::getFcaducidad() const { return fCaducidad; }

void Abarrotes::setMarca(string m) { marca = m; }
void Abarrotes::setEmpaque(string e) { empaque = e; }
void Abarrotes::setFcaducidad(DiaCalendario f) { fCaducidad = f; }

void Abarrotes::mostrarFcaducidad() const {
    cout << "Fecha de caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

void Abarrotes::mostrarInfo() const {
    cout << "[Abarrotes] " << nombre << ", Marca: " << marca
         << ", Empaque: " << empaque << ", Cantidad: " << cantidad << " " << unidad
         << ", Caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

#endif
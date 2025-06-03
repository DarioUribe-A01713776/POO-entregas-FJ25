#ifndef CREMERIA_H
#define CREMERIA_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;


// Clase Cremeria
class Cremeria : public Producto {
private:
    DiaCalendario fCaducidad;

public:
    Cremeria(string n, float c, float cr, string u, DiaCalendario f);

    DiaCalendario getFcaducidad() const;
    void setFcaducidad(DiaCalendario);

    void mostrarFcaducidad() const;
    void mostrarInfo() const override;
};

Cremeria::Cremeria(string n, float c, float cr, string u, DiaCalendario f)
    : Producto(n, c, cr, u, f), fCaducidad(f) {}

DiaCalendario Cremeria::getFcaducidad() const { return fCaducidad; }
void Cremeria::setFcaducidad(DiaCalendario f) { fCaducidad = f; }

void Cremeria::mostrarFcaducidad() const {
    cout << "Fecha de caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

void Cremeria::mostrarInfo() const {
    cout << "[Cremeria] " << nombre << ", " << cantidad << " " << unidad << ", Caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

#endif

// cremeria.cpp
// Descripción: Implementación de la clase Cremeria.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define los métodos específicos para productos de cremería y su fecha de caducidad.


#include "cremeria.h"
#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

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
// abarrotes.cpp
// Descripción: Implementación de la clase Abarrotes.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define métodos específicos para productos del tipo abarrotes.

#include "abarrotes.h"
#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

Abarrotes::Abarrotes(string n, float c, float cr, string u, string m, DiaCalendario f)
    : Producto(n, c, cr, u, f), marca(m), fCaducidad(f) {}

string Abarrotes::getMarca() const { return marca; }
DiaCalendario Abarrotes::getFcaducidad() const { return fCaducidad; }

void Abarrotes::setMarca(string m) { marca = m; }
void Abarrotes::setFcaducidad(DiaCalendario f) { fCaducidad = f; }

void Abarrotes::mostrarFcaducidad() const {
    cout << "Fecha de caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

void Abarrotes::mostrarInfo() const {
    cout << "[Abarrotes] " << nombre << ", Marca: " << marca
         << ", Cantidad: " << cantidad << " " << unidad
         << ", Caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}
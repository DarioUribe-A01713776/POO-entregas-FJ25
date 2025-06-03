// carniceria.cpp
// Descripción: Implementación de la clase Carniceria.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define los métodos para productos cárnicos, incluyendo cálculo de vida útil.

#include "carniceria.h"
#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

Carniceria::Carniceria(string n, float c, float cr, string u, string ta, int dv, DiaCalendario f)
    : Producto(n, c, cr, u, f), tipoAnimal(ta), diasVidaUtil(dv) {}

string Carniceria::getTipoAnimal() const { return tipoAnimal; }
int Carniceria::getDiasVidaUtil() const { return diasVidaUtil; }

void Carniceria::setTipoAnimal(string ta) { tipoAnimal = ta; }
void Carniceria::setDiasVidaUtil(int dv) { diasVidaUtil = dv; }

bool Carniceria::util(const DiaCalendario& hoy) const {
    return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
}

void Carniceria::mostrarInfo() const {
    cout << "[Carniceria] " << nombre << " (" << tipoAnimal << "), "
         << cantidad << " " << unidad << ", Vida util: " << diasVidaUtil << " dias" << endl;
}
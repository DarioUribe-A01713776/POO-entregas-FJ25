// verdura.cpp
// Descripción: Implementación de la clase Verdura.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define métodos específicos para productos tipo verdura y su vida útil.

#include "verdura.h"
#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

Verdura::Verdura(string n, float c, float cr, string u, int dv, DiaCalendario f)
    : Producto(n, c, cr, u, f), diasVidaUtil(dv) {}

int Verdura::getDiasVidaUtil() const { return diasVidaUtil; }
void Verdura::setDiasVidaUtil(int dv) { diasVidaUtil = dv; }

bool Verdura::util(const DiaCalendario& hoy) const {
    return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
}

void Verdura::mostrarInfo() const {
    cout << "[Verdura] " << nombre << ", " << cantidad << " " << unidad
         << ", Vida útil: " << diasVidaUtil << " días" << endl;
}
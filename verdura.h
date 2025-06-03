#ifndef VERDURA_H
#define VERDURA_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

// Clase Verdura
class Verdura : public Producto {
private:
    int diasVidaUtil;

public:
    Verdura(string n, float c, float cr, string u, int dv, DiaCalendario f);

    int getDiasVidaUtil() const;
    void setDiasVidaUtil(int);

    bool util(const DiaCalendario&) const;
    void mostrarInfo() const override;
};

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

#endif

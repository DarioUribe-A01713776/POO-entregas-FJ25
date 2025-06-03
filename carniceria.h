#ifndef CARNICERIA_H
#define CARNICERIA_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

// Clase Carniceria
class Carniceria : public Producto {
private:
    string tipoAnimal;
    int diasVidaUtil;

public:
    Carniceria(string n, float c, float cr, string u, string ta, int dv, DiaCalendario f);

    string getTipoAnimal() const;
    int getDiasVidaUtil() const;

    void setTipoAnimal(string);
    void setDiasVidaUtil(int);

    bool util(const DiaCalendario&) const;
    void mostrarInfo() const override;
};

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

#endif

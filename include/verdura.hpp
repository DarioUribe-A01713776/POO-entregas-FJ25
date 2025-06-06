// verdura.h
// Descripción: Declaración de la clase Verdura, derivada de Producto.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Representa productos tipo verdura con control de vida útil en días.

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

#endif

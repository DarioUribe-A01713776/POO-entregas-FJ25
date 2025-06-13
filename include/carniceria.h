// carniceria.h
// Descripción: Declaración de la clase Carniceria, derivada de Producto.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Representa productos cárnicos con información sobre tipo de animal y vida útil

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

#endif

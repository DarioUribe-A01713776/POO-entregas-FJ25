// cremeria.h
// Descripción: Declaración de la clase Cremeria, derivada de Producto.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Representa productos lácteos o refrigerados con fecha de caducidad.

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

#endif

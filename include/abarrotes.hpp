// abarrotes.h
// Descripción: Declaración de la clase Abarrotes, derivada de Producto.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Representa productos de abarrotes con atributos como marca, empaque y fecha de caducidad.

// Clase Abarrotes
#ifndef ABARROTES_H
#define ABARROTES_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

class Abarrotes : public Producto {
private:
    string marca;
    string empaque;
    DiaCalendario fCaducidad;

public:
    Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f);

    string getMarca() const;
    string getEmpaque() const;
    DiaCalendario getFcaducidad() const;

    void setMarca(string);
    void setEmpaque(string);
    void setFcaducidad(DiaCalendario);

    void mostrarFcaducidad() const;
    void mostrarInfo() const override;
};

#endif
// diaCalendario.h
// Descripción: Declaración de la clase DiaCalendario para manejar fechas personalizadas.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Incluye métodos para obtener y modificar la fecha, además de sobrecarga del operador <<.

#ifndef DIACALENDARIO_H
#define DIACALENDARIO_H

#include <iostream>
using namespace std;

class DiaCalendario {
private:
    int dia;
    int mes;
    int anio;

public:
    DiaCalendario(int d = 1, int m = 1, int a = 2000) 
        : dia(d), mes(m), anio(a) {}

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int);
    void setMes(int);
    void setAnio(int); 

    bool estaDentroDeDias(const DiaCalendario& otro, int maxDias) const;
    void mostrar() const {
    cout << dia << "/" << mes << "/" << anio;
}

};

ostream& operator<<(ostream& os, const DiaCalendario& fecha);

#endif

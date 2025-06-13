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
    DiaCalendario() : dia(1), mes(1), anio(2000) {}
    DiaCalendario(int d, int m, int a) : dia(d), mes(m), anio(a) {}

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

// sobrecarga del operador << para imprimir objetos DiaCalendario.
// permite usar cout << fecha directamente con formato día/mes/año.
ostream& operator<<(ostream& os, const DiaCalendario& fecha);

#endif

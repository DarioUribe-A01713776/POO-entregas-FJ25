// diaCalendario.cpp
// Descripción: Implementación de la clase DiaCalendario.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define los métodos para gestionar fechas y la sobrecarga del operador <<.

#include "diaCalendario.h"
#include <iostream>
using namespace std;

int DiaCalendario::getDia() const{return dia;}
int DiaCalendario::getMes() const{return mes;}
int DiaCalendario::getAnio() const{return anio;}

void DiaCalendario::setDia(int d){dia = d;}
void DiaCalendario::setMes(int m){mes = m;}
void DiaCalendario::setAnio(int a){anio = a;}

bool DiaCalendario::estaDentroDeDias( const DiaCalendario& otro, int maxDias) const{
        int total1 = anio * 360 + mes * 30 + dia;
        int total2 = otro.anio * 360 + otro.mes * 30 + otro.dia;
        int diferencia = total2 - total1;
        return diferencia <= maxDias;
    }

ostream& operator<<(ostream& os, const DiaCalendario& fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
    return os;
}
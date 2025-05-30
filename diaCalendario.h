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


#endif

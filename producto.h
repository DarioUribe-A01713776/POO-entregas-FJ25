#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

// Clase Producto
class Producto {
protected:
    string nombre;  
    float cantidad;
    float cantidadRequerida;
    string unidad;
    DiaCalendario fechaEntrada;

public:
    Producto();
    Producto(string n, float c, float cr, string u, DiaCalendario f);

    string getNombre() const;
    float getCantidad() const;
    float getCantidadRequerida() const;
    string getUnidad() const;
    DiaCalendario getFechaEntrada() const;

    void setNombre(string);
    void setCantidad(float);
    void setCantidad(int); // Sobrecarga con int
    void setCantidad(float, bool); // Sobrecarga con incremento
    void setCantidadRequerida(float);
    void setUnidad(string);
    void setFechaEntrada(DiaCalendario);

    virtual void mostrarInfo() const;
};

Producto::Producto(string n, float c, float cr, string u, DiaCalendario f)
    : nombre(n), cantidad(c), cantidadRequerida(cr), unidad(u), fechaEntrada(f) {}

string Producto::getNombre() const { return nombre; }
float Producto::getCantidad() const { return cantidad; }
float Producto::getCantidadRequerida() const { return cantidadRequerida; }
string Producto::getUnidad() const { return unidad; }
DiaCalendario Producto::getFechaEntrada() const { return fechaEntrada; }

void Producto::setNombre(string n) { nombre = n; }
void Producto::setCantidad(float c) { cantidad = c; }
void Producto::setCantidad(int c) { cantidad = static_cast<float>(c); }
void Producto::setCantidad(float c, bool esIncremento) {
    if (esIncremento) cantidad += c;
    else cantidad = c;
}
void Producto::setCantidadRequerida(float cr) { cantidadRequerida = cr; }
void Producto::setUnidad(string u) { unidad = u; }
void Producto::setFechaEntrada(DiaCalendario f) { fechaEntrada = f; }

void Producto::mostrarInfo() const {
    cout << "[Producto] " << nombre << ", " << cantidad << " " << unidad << endl;
}

#endif
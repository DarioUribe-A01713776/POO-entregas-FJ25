// producto.cpp
// Descripción: Implementación de la clase Producto.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Contiene las definiciones de los métodos declarados en producto.h

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

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
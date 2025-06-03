#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>
using namespace std;

class Proveedor {
private:
    string nombre;
    string contacto;
    DiaCalendario fechaEntrega;
    Producto* productos[100];
    int numProductos;

public:
    Proveedor();
    Proveedor(string n, string c, DiaCalendario f);

    string getNombre() const;
    string getContacto() const;
    DiaCalendario getFechaEntrega() const;

    void setNombre(string);
    void setContacto(string);
    void setFechaEntrega(DiaCalendario);

    bool agregarProducto(Producto* producto);
    bool eliminarProducto(Producto* producto);
    void mostrarProductos();
};


Proveedor::Proveedor()
    : nombre(""), contacto(""), fechaEntrega(), numProductos(0) {}

Proveedor::Proveedor(string n, string c, DiaCalendario f)
    : nombre(n), contacto(c), fechaEntrega(f), numProductos(0) {}

string Proveedor::getNombre() const { return nombre; }
string Proveedor::getContacto() const { return contacto; }
DiaCalendario Proveedor::getFechaEntrega() const { return fechaEntrega; }

void Proveedor::setNombre(string n) { nombre = n; }
void Proveedor::setContacto(string c) { contacto = c; }
void Proveedor::setFechaEntrega(DiaCalendario f) { fechaEntrega = f; }

bool Proveedor::agregarProducto(Producto* producto) {
    if (numProductos < 100) {
        productos[numProductos++] = producto;
        cout << "Producto agregado con éxito.\n";
        return true;
    } else {
        cout << "No se pueden agregar más productos.\n";
        return false;
    }
}

bool Proveedor::eliminarProducto(Producto* producto) {
    for (int i = 0; i < numProductos; ++i) {
        if (productos[i] == producto) {
            for (int j = i; j < numProductos - 1; ++j) {
                productos[j] = productos[j + 1];
            }
            --numProductos;
            cout << "Producto eliminado con exito.\n";
            return true;
        }
    }
    cout << "Producto no encontrado.\n";
    return false;
}

void Proveedor::mostrarProductos() {
    cout << "Productos del proveedor: " << nombre << endl;
    for (int i = 0; i < numProductos; ++i) {
        productos[i]->mostrarInfo();
    }
}

#endif

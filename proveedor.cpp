// proveedor.cpp
// Descripción: Implementación de la clase Proveedor.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define métodos para administrar datos del proveedor y su lista de productos.

#include "proveedor.h"
#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

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
        productos[i]->mostrarInfo();   //Llama mostrarInfo() de forma polimórfica
    }
}
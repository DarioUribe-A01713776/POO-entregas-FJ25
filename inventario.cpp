// inventario.cpp
// Descripcion: Implementacion de la clase Inventario con arreglos dinamicos.
// Autor: Dario A. Uribe
// Fecha: 06/06/2025
// Notas: Define metodos para manejar productos sin vectores.

#include "inventario.h"
#include <iostream>
using namespace std;

Inventario::Inventario(int capacidadInicial)
    : numProductos(0), capacidad(capacidadInicial) {
    productos = new Producto*[capacidad];
}

Inventario::~Inventario() {
    for (int i = 0; i < numProductos; ++i) {
        delete productos[i];
    }
    delete[] productos;
}

bool Inventario::agregarProducto(Producto* p) {
    if (numProductos < capacidad) {
        productos[numProductos++] = p;
        return true;
    } else {
        cout << "Inventario lleno." << endl;
        return false;
    }
}

bool Inventario::eliminarProducto(const string& nombre) {
    for (int i = 0; i < numProductos; ++i) {
        if (productos[i]->getNombre() == nombre) {
            delete productos[i];
            for (int j = i; j < numProductos - 1; ++j) {
                productos[j] = productos[j + 1];
            }
            --numProductos;
            return true;
        }
    }
    return false;
}

Producto* Inventario::buscarProducto(const string& nombre) const {
    for (int i = 0; i < numProductos; ++i) {
        if (productos[i]->getNombre() == nombre) {
            return productos[i];
        }
    }
    return nullptr;
}

bool Inventario::actualizarStock(const string& nombre, float cantidad, bool incremento) {
    Producto* p = buscarProducto(nombre);
    if (p) {
        p->setCantidad(cantidad, incremento);
        return true;
    }
    return false;
}

void Inventario::mostrarInventario() const {
    cout << "=== Inventario ===" << endl;
    for (int i = 0; i < numProductos; ++i) {
        productos[i]->mostrarInfo();
    }
}

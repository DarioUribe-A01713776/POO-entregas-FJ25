// proveedor.cpp
// Descripción: Implementación de la clase Proveedor.
// Autor: Darío A. Uribe
// Fecha: 10/06/2025
// Notas: Define métodos para administrar datos del proveedor y su lista de productos.

#include "proveedor.h"
#include <iostream>

Proveedor::Proveedor(const std::string& nombre, const std::string& contacto, const std::string& diaEntrega,int cap)
    : nombre(nombre),
      contacto(contacto),
      diaSemanaEntrega(diaEntrega),
      capProductos(cap),
      numProductos(0)
{
    productos = new Producto*[capProductos];
    for (int i = 0; i < capProductos; ++i) {
        productos[i] = nullptr;
    }
}

Proveedor::~Proveedor() {
    delete[] productos;
}

const std::string& Proveedor::getNombre() const {
    return nombre;
}

const std::string& Proveedor::getContacto() const {
    return contacto;
}

const std::string& Proveedor::getDiaSemanaEntrega() const {
    return diaSemanaEntrega;
}

void Proveedor::mostrarProductos() const {
    std::cout << "Proveedor: " << nombre << std::endl;
    if (numProductos == 0) {
        std::cout << "  (Sin productos)" << std::endl;
    } else {
        for (int i = 0; i < numProductos; ++i) {
            if (productos[i]) {
                std::cout << "  - " << productos[i]->getNombre() << std::endl;
            }
        }
    }
}

void Proveedor::agregarProducto(Producto* p) {
    if (numProductos >= capProductos) {
        // Duplicar capacidad
        int nuevaCap = capProductos * 2;
        Producto** tmp = new Producto*[nuevaCap];
        for (int i = 0; i < numProductos; ++i) tmp[i] = productos[i];
        for (int i = numProductos; i < nuevaCap; ++i) tmp[i] = nullptr;
        delete[] productos;
        productos = tmp;
        capProductos = nuevaCap;
    }
    productos[numProductos++] = p;
}
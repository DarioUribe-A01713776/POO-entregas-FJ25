#ifndef ORDENPEDIDO_H
#define ORDENPEDIDO_H

#include "producto.h"
#include "proveedor.h"
#include "diaCalendario.h"
#include <string>
#include <iostream>

class OrdenPedido {
private: 
    int idPedido;
    Producto* productoSolicitado[100];
    Proveedor proveedor;
    DiaCalendario fechaPedido;
    DiaCalendario fechaEntrega;
    int numProductos;

public:
    // Constructores
    OrdenPedido();
    OrdenPedido(int id, Proveedor p, DiaCalendario fp, DiaCalendario fe);

    // Getters
    int getIdPedido() const;
    Proveedor getProveedor() const;
    DiaCalendario getFechaPedido() const;
    DiaCalendario getFechaEntrega() const;

    // Setters
    void setIdPedido(int id);
    void setProveedor(Proveedor p);
    void setFechaPedido(DiaCalendario fp);
    void setFechaEntrega(DiaCalendario fe);

    // Métodos funcionales
    bool agregarProducto(Producto* producto);
    bool eliminarProducto(Producto* producto);  // Comparación por puntero
    void mostrarPedido() const;
};

// Implementación de métodos

OrdenPedido::OrdenPedido()
    : idPedido(0), proveedor(), fechaPedido(), fechaEntrega(), numProductos(0) {}

OrdenPedido::OrdenPedido(int id, Proveedor p, DiaCalendario fp, DiaCalendario fe)
    : idPedido(id), proveedor(p), fechaPedido(fp), fechaEntrega(fe), numProductos(0) {}

int OrdenPedido::getIdPedido() const { return idPedido; }
Proveedor OrdenPedido::getProveedor() const { return proveedor; }
DiaCalendario OrdenPedido::getFechaPedido() const { return fechaPedido; }
DiaCalendario OrdenPedido::getFechaEntrega() const { return fechaEntrega; }

void OrdenPedido::setIdPedido(int id) { idPedido = id; }
void OrdenPedido::setProveedor(Proveedor p) { proveedor = p; }
void OrdenPedido::setFechaPedido(DiaCalendario fp) { fechaPedido = fp; }
void OrdenPedido::setFechaEntrega(DiaCalendario fe) { fechaEntrega = fe; }

bool OrdenPedido::agregarProducto(Producto* producto) {
    if (numProductos < 100) {
        productoSolicitado[numProductos++] = producto;
        std::cout << "Producto agregado con éxito.\n";
        return true;
    } else {
        std::cout << "No se pueden agregar más productos.\n";
        return false;
    }
}

bool OrdenPedido::eliminarProducto(Producto* producto) {
    for (int i = 0; i < numProductos; ++i) {
        if (productoSolicitado[i] == producto) {  // Comparación por dirección
            for (int j = i; j < numProductos - 1; ++j) {
                productoSolicitado[j] = productoSolicitado[j + 1];
            }
            --numProductos;
            std::cout << "Producto eliminado con éxito.\n";
            return true;
        }
    }
    std::cout << "Producto no encontrado.\n";
    return false;
}

void OrdenPedido::mostrarPedido() const {
    std::cout << "Pedido #" << idPedido << " - Fecha de pedido: " << fechaPedido << std::endl;
    std::cout << "Fecha de entrega: " << fechaEntrega << std::endl;
    std::cout << "Proveedor: " << proveedor.getNombre() << std::endl;
    std::cout << "Productos solicitados:" << std::endl;
    for (int i = 0; i < numProductos; ++i) {
        std::cout << "- " << productoSolicitado[i]->getNombre() << std::endl;
    }
}

#endif

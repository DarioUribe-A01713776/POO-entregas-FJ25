// ordenPedido.cpp
// Descripción: Implementación de la clase OrdenPedido.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Define métodos para gestionar pedidos, productos asociados y proveedor

#include "ordenPedido.h"
#include "producto.h"
#include "proveedor.h"
#include "diaCalendario.h"
#include <string>
#include <iostream>

using namespace std;


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
        std::cout << "Producto agregado con exito.\n";
        return true;
    } else {
        std::cout << "No se pueden agregar mas productos.\n";
        return false;
    }
}

bool OrdenPedido::eliminarProducto(Producto* producto) {
    for (int i = 0; i < numProductos; ++i) {
        if (productoSolicitado[i] == producto) {  
            for (int j = i; j < numProductos - 1; ++j) {
                productoSolicitado[j] = productoSolicitado[j + 1];
            }
            --numProductos;
            std::cout << "Producto eliminado con exito.\n";
            return true;
        }
    }
    std::cout << "Producto no encontrado.\n";
    return false;
}

//Llama mostrarInfo() de forma polimórfica
void OrdenPedido::mostrarPedido() const {
    std::cout << "Pedido #" << idPedido << " - Fecha de pedido: " << fechaPedido << std::endl;
    std::cout << "Fecha de entrega: " << fechaEntrega << std::endl;
    std::cout << "Proveedor: " << proveedor.getNombre() << std::endl;
    std::cout << "Productos solicitados:" << std::endl;
    for (int i = 0; i < numProductos; ++i) {
    productoSolicitado[i]->mostrarInfo();  
    }
}

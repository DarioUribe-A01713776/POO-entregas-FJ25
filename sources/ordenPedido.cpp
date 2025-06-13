// ordenPedido.cpp
// Descripción: Implementación de la clase OrdenPedido.
// Autor: Darío A. Uribe
// Fecha: 10/06/2025
// Notas: Define métodos para gestionar pedidos, productos asociados y proveedor

// ordenPedido.cpp
#include "ordenPedido.h"
#include <iostream>

using namespace std;

OrdenPedido::OrdenPedido(int cap)
  : idPedido(0),numProductos(0),capProductos(cap),proveedor(nullptr),fechaPedido(),fechaEntrega()
{
    productosSolicitados = new Producto*[capProductos];
    for (int i = 0; i < capProductos; ++i)
        productosSolicitados[i] = nullptr;
}

OrdenPedido::~OrdenPedido() {
    delete[] productosSolicitados;
}

OrdenPedido::OrdenPedido(int id,Proveedor* p,const DiaCalendario& fp,const DiaCalendario& fe)
  : idPedido(id),numProductos(0),capProductos(10),proveedor(p),fechaPedido(fp),fechaEntrega(fe)
{
    productosSolicitados = new Producto*[capProductos];
    for (int i = 0; i < capProductos; ++i)
        productosSolicitados[i] = nullptr;
}

void OrdenPedido::expandirProductos() {
    int nuevaCap = capProductos * 2;
    Producto** tmp = new Producto*[nuevaCap];
    for (int i = 0; i < numProductos; ++i)
        tmp[i] = productosSolicitados[i];
    for (int i = numProductos; i < nuevaCap; ++i)
        tmp[i] = nullptr;
    delete[] productosSolicitados;
    productosSolicitados = tmp;
    capProductos = nuevaCap;
}

int OrdenPedido::getIdPedido() const { return idPedido; }
Proveedor* OrdenPedido::getProveedor() const { return proveedor; }
DiaCalendario OrdenPedido::getFechaPedido() const { return fechaPedido; }
DiaCalendario OrdenPedido::getFechaEntrega() const { return fechaEntrega; }

void OrdenPedido::setIdPedido(int id) { idPedido = id; }
void OrdenPedido::setProveedor(Proveedor* p) { proveedor = p; }
void OrdenPedido::setFechaPedido(const DiaCalendario& fp) { fechaPedido = fp; }
void OrdenPedido::setFechaEntrega(const DiaCalendario& fe) { fechaEntrega = fe; }

bool OrdenPedido::agregarProducto(Producto* producto) {
    if (numProductos == capProductos)
        expandirProductos();
    productosSolicitados[numProductos++] = producto;
    cout << "Producto agregado al pedido con éxito.\n";
    return true;
}

bool OrdenPedido::eliminarProducto(Producto* producto) {
    for (int i = 0; i < numProductos; ++i) {
        if (productosSolicitados[i] == producto) {
            for (int j = i; j < numProductos - 1; ++j)
                productosSolicitados[j] = productosSolicitados[j + 1];
            productosSolicitados[--numProductos] = nullptr;
            cout << "Producto eliminado del pedido con éxito.\n";
            return true;
        }
    }
    cout << "Producto no encontrado en el pedido.\n";
    return false;
}

void OrdenPedido::mostrarPedido() const {
    cout << "Pedido #" << idPedido << "\n";
    cout << "Fecha pedido: "; fechaPedido.mostrar();
    cout << "Fecha entrega: "; fechaEntrega.mostrar();
    if (proveedor)
        cout << "Proveedor: " << proveedor->getNombre() << "\n";
    cout << "Productos solicitados:\n";
    for (int i = 0; i < numProductos; ++i) {
        productosSolicitados[i]->mostrarInfo();
    }
}

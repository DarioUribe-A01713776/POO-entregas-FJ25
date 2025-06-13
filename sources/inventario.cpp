// inventario.cpp
// Descripcion: Implementacion de la clase Inventario.
// Autor: Dario A. Uribe
// Fecha:  11/06/2025

#include "inventario.h"
#include <iostream>
#include <string>

using namespace std;

Inventario::Inventario(int capProd, int capProv, int capPed)
  : numProductos(0), capProductos(capProd),
    numProveedores(0), capProveedores(capProv),
    numPedidos(0), capPedidos(capPed)
{
    productos = new Producto*[capProductos];
    proveedores = new Proveedor*[capProveedores];
    pedidos = new OrdenPedido*[capPedidos];
    for(int i = 0; i < capProductos;   ++i) productos[i]   = nullptr;
    for(int i = 0; i < capProveedores; ++i) proveedores[i] = nullptr;
    for(int i = 0; i < capPedidos;     ++i) pedidos[i]     = nullptr;
}

Inventario::~Inventario() {
    delete[] productos;
    delete[] proveedores;
    delete[] pedidos;
}

void Inventario::expandirProductos() {
    int nuevaCap = capProductos * 2;
    auto tmp = new Producto*[nuevaCap];
    for(int i = 0; i < numProductos; ++i) tmp[i] = productos[i];
    for(int i = numProductos; i < nuevaCap; ++i) tmp[i] = nullptr;
    delete[] productos;
    productos    = tmp;
    capProductos = nuevaCap;
}

void Inventario::expandirProveedores() {
    int nuevaCap = capProveedores * 2;
    auto tmp = new Proveedor*[nuevaCap];
    for(int i = 0; i < numProveedores; ++i) tmp[i] = proveedores[i];
    for(int i = numProveedores; i < nuevaCap; ++i) tmp[i] = nullptr;
    delete[] proveedores;
    proveedores    = tmp;
    capProveedores = nuevaCap;
}

void Inventario::expandirPedidos() {
    int nuevaCap = capPedidos * 2;
    auto tmp = new OrdenPedido*[nuevaCap];
    for(int i = 0; i < numPedidos; ++i) tmp[i] = pedidos[i];
    for(int i = numPedidos; i < nuevaCap; ++i) tmp[i] = nullptr;
    delete[] pedidos;
    pedidos    = tmp;
    capPedidos = nuevaCap;
}

// --- Productos ---
void Inventario::agregarProducto(Producto* p) {
    if (numProductos == capProductos)
        expandirProductos();
    productos[numProductos++] = p;
    cout << "Producto agregado al inventario.\n";
}

bool Inventario::eliminarProducto(const string& nombre) {
    for(int i = 0; i < numProductos; ++i) {
        if (productos[i]->getNombre() == nombre) {
            for(int j = i; j < numProductos - 1; ++j)
                productos[j] = productos[j+1];
            productos[--numProductos] = nullptr;
            cout << "Producto \"" << nombre << "\" eliminado.\n";
            return true;
        }
    }
    cout << "Producto \"" << nombre << "\" no encontrado.\n";
    return false;
}

void Inventario::actualizarStock(Producto* p, float nuevaCantidad) {
    p->setCantidad(nuevaCantidad);
    cout << "Stock de \"" << p->getNombre()
         << "\" actualizado a " << nuevaCantidad << ".\n";
}

Producto* Inventario::buscarProducto(const std::string& nombre) const {
    for (int i = 0; i < numProductos; ++i) {
        if (productos[i] && productos[i]->getNombre() == nombre) {
            return productos[i];
        }
    }
    return nullptr;
}

Producto** Inventario::mostrarInventario() const {
    cout << "=== Inventario de Productos ===\n";
    for(int i = 0; i < numProductos; ++i)
        productos[i]->mostrarInfo();
    return productos;
}

// --- Proveedores ---
void Inventario::agregarProveedor(Proveedor* prov) {
    if (numProveedores == capProveedores)
        expandirProveedores();
    proveedores[numProveedores++] = prov;
    cout << "Proveedor \"" << prov->getNombre() << "\" agregado.\n";
}

bool Inventario::eliminarProveedor(Proveedor* prov) {
    for(int i = 0; i < numProveedores; ++i) {
        if (proveedores[i] == prov) {
            for(int j = i; j < numProveedores - 1; ++j)
                proveedores[j] = proveedores[j+1];
            proveedores[--numProveedores] = nullptr;
            cout << "Proveedor eliminado.\n";
            return true;
        }
    }
    cout << "Proveedor no encontrado.\n";
    return false;
}

Proveedor** Inventario::mostrarProveedores() const {
    cout << "=== Lista de Proveedores ===\n";
    for(int i = 0; i < numProveedores; ++i)
        cout << "- " << proveedores[i]->getNombre() << "\n";
    return proveedores;
}

// --- Pedidos ---
void Inventario::agregarPedido(OrdenPedido* o) {
    if (numPedidos == capPedidos)
        expandirPedidos();
    pedidos[numPedidos++] = o;
    cout << "Pedido #" << o->getIdPedido() << " agregado.\n";
}

bool Inventario::eliminarPedido(OrdenPedido* o) {
    for(int i = 0; i < numPedidos; ++i) {
        if (pedidos[i] == o) {
            for(int j = i; j < numPedidos - 1; ++j)
                pedidos[j] = pedidos[j+1];
            pedidos[--numPedidos] = nullptr;
            cout << "Pedido eliminado.\n";
            return true;
        }
    }
    cout << "Pedido no encontrado.\n";
    return false;
}

OrdenPedido** Inventario::mostrarPedidos() const {
    cout << "=== Ordenes de Pedido ===\n";
    for(int i = 0; i < numPedidos; ++i)
        pedidos[i]->mostrarPedido();
    return pedidos;
}

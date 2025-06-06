#include "inventario.h"
#include <iostream>
using namespace std;

bool Inventario::agregarProducto(Producto* p) {
    productos.push_back(p);
    cout << "Producto agregado al inventario.\n";
    return true;
}

bool Inventario::eliminarProducto(const std::string& nombre) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            productos.erase(it);
            cout << "Producto eliminado del inventario.\n";
            return true;
        }
    }
    cout << "Producto no encontrado.\n";
    return false;
}

Producto* Inventario::buscarProducto(const std::string& nombre) {
    for (Producto* p : productos) {
        if (p->getNombre() == nombre) {
            return p;
        }
    }
    return nullptr;
}

void Inventario::mostrarInventario() const {
    cout << "----- Inventario -----\n";
    for (Producto* p : productos) {
        p->mostrarInfo();
    }
    cout << "-----------------------\n";
}

void Inventario::actualizarStock(const std::string& nombre, float nuevaCantidad, bool esIncremento) {
    Producto* p = buscarProducto(nombre);
    if (p) {
        p->setCantidad(nuevaCantidad, esIncremento);
        cout << "Stock actualizado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

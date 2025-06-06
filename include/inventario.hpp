// inventario.h
// Descripcion: Declaracion de la clase Inventario con arreglos dinamicos.
// Autor: Dario A. Uribe
// Fecha: 06/06/2025
// Notas: Gestiona productos del inventario sin usar vectores, solo arreglos dinamicos.

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"
#include <string>
using namespace std;

class Inventario {
private:
    Producto** productos;
    int numProductos;
    int capacidad;

public:
    Inventario(int capacidadInicial = 100);
    ~Inventario();

    bool agregarProducto(Producto* p);
    bool eliminarProducto(const string& nombre);
    Producto* buscarProducto(const string& nombre) const;
    bool actualizarStock(const string& nombre, float cantidad, bool incremento);
    void mostrarInventario() const;

    Producto** getTodos() const;
    int getNumProductos() const;
};

#endif

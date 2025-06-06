// inventario.h
// Descripción: Declaración de la clase Inventario.
// Autor: Darío A. Uribe
// Fecha: 06/06/2025
// Notas: Representa el inventario general usando arreglos dinámicos para almacenar productos.

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
    bool eliminarProducto(string nombre);
    void mostrarInventario() const;
};

#endif

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"
#include <vector>
#include <string>

class Inventario {
private:
    std::vector<Producto*> productos;

public:
    // Métodos
    bool agregarProducto(Producto* p);
    bool eliminarProducto(const std::string& nombre);
    Producto* buscarProducto(const std::string& nombre);
    void mostrarInventario() const;
    void actualizarStock(const std::string& nombre, float nuevaCantidad, bool esIncremento = false);
};

#endif

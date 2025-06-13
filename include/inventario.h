// inventario.h
// Descripcion: Declaracion de la clase Inventario con arreglos dinamicos.
// Autor: Dario A. Uribe
// Fecha: 06/06/2025
// Notas: Gestiona productos del inventario sin usar vectores, solo arreglos dinamicos.

// inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"
#include "proveedor.h"
#include "ordenPedido.h"
#include <string>

class Inventario {
private:
    // Productos
    Producto** productos;
    int numProductos;
    int capProductos;

    // Proveedores
    Proveedor** proveedores;
    int numProveedores;
    int capProveedores;

    // Órdenes de pedido
    OrdenPedido** pedidos;
    int numPedidos;
    int capPedidos;

public:
    Inventario(int capProd = 100, int capProv = 100, int capPed = 10);
    ~Inventario();

    void expandirProductos();
    void expandirProveedores();
    void expandirPedidos();
    
    // gestión de productos
    void agregarProducto(Producto* p);
    bool eliminarProducto(const std::string& nombre);
    void actualizarStock(Producto* p, float nuevaCantidad);
    Producto* buscarProducto(const std::string& nombre) const;
    Producto** mostrarInventario() const;

    // gestión de proveedores
    void agregarProveedor(Proveedor* prov);
    bool eliminarProveedor(Proveedor* prov);
    Proveedor** mostrarProveedores() const;

    // gestión de pedidos
    void agregarPedido(OrdenPedido* o);
    bool eliminarPedido(OrdenPedido* o);
    OrdenPedido** mostrarPedidos() const;
};

#endif


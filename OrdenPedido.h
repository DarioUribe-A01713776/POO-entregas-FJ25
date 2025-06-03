// ordenPedido.h
// Descripción: Declaración de la clase OrdenPedido, que gestiona pedidos a proveedores.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Incluye productos solicitados, proveedor, fechas y métodos para manipular el pedido.


#ifndef ORDENPEDIDO_H
#define ORDENPEDIDO_H

#include "producto.h"
#include "proveedor.h"
#include "diaCalendario.h"
#include <string>
#include <iostream>

using namespace std;

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

#endif


// ordenPedido.h
// Descripción: Declaración de la clase OrdenPedido, que gestiona pedidos a proveedores.
// Autor: Darío A. Uribe
// Fecha: 10/06/2025
// Notas: Incluye productos solicitados, proveedor, fechas y métodos para manipular el pedido.

#ifndef ORDENPEDIDO_H
#define ORDENPEDIDO_H

#include "producto.h"
#include "proveedor.h"
#include "diaCalendario.h"
#include <iostream>

class OrdenPedido {
private:
    int idPedido;
    Producto** productosSolicitados;  // arreglo dinámico de punteros a Producto
    int numProductos;
    int capProductos;
    Proveedor* proveedor;             // puntero a proveedor
    DiaCalendario fechaPedido;
    DiaCalendario fechaEntrega;

    void expandirProductos();            

public:
    OrdenPedido(int cap = 10);
    ~OrdenPedido();

    
    OrdenPedido(int id, Proveedor* p,const DiaCalendario& fp, const DiaCalendario& fe);

    int getIdPedido() const;
    Proveedor* getProveedor() const;
    DiaCalendario getFechaPedido() const;
    DiaCalendario getFechaEntrega() const;

    void setIdPedido(int id);
    void setProveedor(Proveedor* p);
    void setFechaPedido(const DiaCalendario& fp);
    void setFechaEntrega(const DiaCalendario& fe);

    bool agregarProducto(Producto* producto);
    bool eliminarProducto(Producto* producto);
    void mostrarPedido() const;
};

#endif
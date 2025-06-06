// proveedor.h
// Descripción: Declaración de la clase Proveedor.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Representa un proveedor con nombre, contacto, productos y fecha de entrega.

#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "producto.h"
#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

class Proveedor {
private:
    string nombre;
    string contacto;
    DiaCalendario fechaEntrega;
    Producto* productos[100];
    int numProductos;

public:
    Proveedor();
    Proveedor(string n, string c, DiaCalendario f);

    string getNombre() const;
    string getContacto() const;
    DiaCalendario getFechaEntrega() const;

    void setNombre(string);
    void setContacto(string);
    void setFechaEntrega(DiaCalendario);

    bool agregarProducto(Producto* producto);
    bool eliminarProducto(Producto* producto);
    void mostrarProductos();
};

#endif

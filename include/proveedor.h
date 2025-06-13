// proveedor.h
// Descripción: Declaración de la clase Proveedor.
// Autor: Darío A. Uribe
// Fecha: 10/06/2025
// Notas: Representa un proveedor con nombre, contacto, productos y fecha de entrega.

#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "producto.h"
#include <string>

class Proveedor {
private:
    std::string nombre;
    std::string contacto;
    std::string diaSemanaEntrega;
    Producto** productos;
    int numProductos;
    int capProductos;
public:
    Proveedor(const std::string& nombre,const std::string& contacto,const std::string& diaEntrega,int cap = 10);
    ~Proveedor();

    // Getters
    const std::string& getNombre() const;
    const std::string& getContacto() const;
    const std::string& getDiaSemanaEntrega() const;

    void mostrarProductos() const;
    void agregarProducto(Producto* p);
};

#endif


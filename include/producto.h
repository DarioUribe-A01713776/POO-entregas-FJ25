// producto.h
// Descripción: Declaración de la clase Producto, clase base del sistema de inventario.
// Autor: Darío A. Uribe
// Fecha: 03/06/2025
// Notas: Esta clase contiene atributos y métodos comunes a todos los productos.

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

// Clase Producto
class Producto {
protected:
    string nombre;  
    float cantidad;
    float cantidadRequerida;
    string unidad;
    DiaCalendario fechaEntrada;

public:
    Producto();
    Producto(string n, float c, float cr, string u, DiaCalendario f);

    string getNombre() const;
    float getCantidad() const;
    float getCantidadRequerida() const;
    string getUnidad() const;
    DiaCalendario getFechaEntrada() const;

    void setNombre(string);
    void setCantidad(float);
    void setCantidad(int); // sobrecarga con int
    void setCantidad(float, bool); // sobrecarga con parametro adicional
    void setCantidadRequerida(float);
    void setUnidad(string);
    void setFechaEntrada(DiaCalendario);

    virtual void mostrarInfo() const; //sobreescritura de métodos
    
};
#endif
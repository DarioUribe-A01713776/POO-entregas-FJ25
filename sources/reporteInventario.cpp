// reporteInventario.cpp
// Descripción: Implementación del reporte de inventario.
// Autor: Darío A. Uribe
// Fecha: 11/06/2025

#include "reporteInventario.h"
#include <iostream>

ReporteInventario::ReporteInventario(const Inventario& inv)
    : inventario(inv) {}

void ReporteInventario::generar() const {
    std::cout << "---- Inventario ----" << std::endl;
    Producto** lista = inventario.mostrarInventario();
    for (int i = 0; lista[i] != nullptr; ++i) {
        lista[i]->mostrarInfo();
    }
    std::cout << "---------------------" << std::endl;
    delete[] lista;
}


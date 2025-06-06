// reporteInventario.cpp
// Descripción: Implementación del reporte de inventario.
// Autor: Darío A. Uribe
// Fecha: 06/06/2025
// Notas: Imprime todos los productos del inventario usando polimorfismo.

#include "reporteInventario.h"
#include <iostream>
using namespace std;

ReporteInventario::ReporteInventario(const Inventario& inv)
    : inventario(inv) {}

void ReporteInventario::generar() const {
    cout << "\n===== REPORTE DE INVENTARIO =====" << endl;
    inventario.mostrarInventario();
    cout << "=================================" << endl;
}

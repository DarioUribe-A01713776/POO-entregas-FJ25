// reporteInventario.cpp
// Descripción: Implementación del reporte de inventario.
// Autor: Darío A. Uribe
// Fecha: 06/06/2025
// Notas: Imprime todos los productos del inventario usando polimorfismo.

// reporteInventario.cpp
// Descripción: Implementación del reporte de inventario.

#include "reporteInventario.h"
#include "carniceria.h"
#include "abarrotes.h"
#include "verdura.h"
#include "cremeria.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

ReporteInventario::ReporteInventario(const Inventario& inv)
    : inventario(inv) {}

void ReporteInventario::generar() const {
    cout << "\n===== REPORTE DE INVENTARIO =====" << endl;
    inventario.mostrarInventario();
    cout << "=================================" << endl;

    ofstream archivo("reporte_inventario.csv");
    archivo << "Nombre,Cantidad,CantidadRequerida,Unidad,Categoria\n";

    Producto** lista = inventario.getTodos();
    int total = inventario.getNumProductos();

    for (int i = 0; i < total; ++i) {
        Producto* p = lista[i];
        string categoria;

        if (dynamic_cast<Carniceria*>(p)) categoria = "Carniceria";
        else if (dynamic_cast<Cremeria*>(p)) categoria = "Cremeria";
        else if (dynamic_cast<Verdura*>(p)) categoria = "Verdura";
        else if (dynamic_cast<Abarrotes*>(p)) categoria = "Abarrotes";
        else categoria = "Desconocida";

        archivo << p->getNombre() << ","
                << p->getCantidad() << ","
                << p->getCantidadRequerida() << ","
                << p->getUnidad() << ","
                << categoria << "\n";
    }

    archivo.close();
    cout << "Reporte también guardado como 'reporte_inventario.csv'.\n";
}


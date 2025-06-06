#include "producto.h"
#include "inventario.h"
#include "carniceria.h"
#include "abarrotes.h"
#include "cremeria.h"
#include "verdura.h"
#include "diaCalendario.h"
#include "reporteInventario.h"

int main() {
    // Crear fechas
    DiaCalendario entrada(1, 6, 2025);
    DiaCalendario caducidad(10, 6, 2025);

    // Crear inventario
    Inventario inventario;

    // Crear productos
    Carniceria* carne = new Carniceria("Bistec", 5, 10, "kg", "Res", 7, entrada);
    Abarrotes* arroz = new Abarrotes("Arroz", 20, 30, "kg", "Doña María", "Bolsa", caducidad);
    Cremeria* queso = new Cremeria("Queso Oaxaca", 3, 8, "kg", caducidad);
    Verdura* lechuga = new Verdura("Lechuga", 8, 12, "pzas", 4, entrada);

    // Agregar al inventario
    inventario.agregarProducto(carne);
    inventario.agregarProducto(arroz);
    inventario.agregarProducto(queso);
    inventario.agregarProducto(lechuga);

    // Generar reporte
    ReporteInventario reporte(inventario);
    reporte.generar();  // Solo imprime y guarda CSV

    // Liberar memoria
    delete carne;
    delete arroz;
    delete queso;
    delete lechuga;

    return 0;
}

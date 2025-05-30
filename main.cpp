#include "Producto.h"
#include "Proveedor.h"
#include "diaCalendario.h"
#include <iostream>
using namespace std;

int main() {
    // Crear fechas
    DiaCalendario hoy(29, 5, 2025);
    DiaCalendario entrada(25, 5, 2025);
    DiaCalendario caducidad(5, 6, 2025);

    // Crear proveedor con fecha de entrega
    DiaCalendario fechaEntrega(2, 6, 2025);
    Proveedor proveedor("La Central", "ventas@central.com", fechaEntrega);

    // Crear productos
    Carniceria carne("Carne de res", 10.0, 15.0, "kg", "Res", 7, entrada);
    Abarrotes arroz("Arroz integral", 20.0, 30.0, "kg", "Doña María", "Bolsa", caducidad);
    Cremeria queso("Queso Oaxaca", 5.0, 10.0, "kg", caducidad);
    Verdura lechuga("Lechuga romana", 8.0, 12.0, "piezas", 5, entrada);

    // Agregar productos al proveedor (agregación)
    proveedor.agregarProducto(&carne);
    proveedor.agregarProducto(&arroz);
    proveedor.agregarProducto(&queso);
    proveedor.agregarProducto(&lechuga);

    // Mostrar productos
    cout << "\nProductos actuales:\n";
    proveedor.mostrarProductos();

    // Eliminar uno (por puntero)
    proveedor.eliminarProducto(&arroz);

    // Mostrar productos después de eliminar
    cout << "\nDespués de eliminar 'Arroz integral':\n";
    proveedor.mostrarProductos();

    return 0;
}

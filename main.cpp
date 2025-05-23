#include "producto.h"
#include "diaCalendario.h"
#include <iostream>

using namespace std;

int main() {
    // Fecha para prueba
    DiaCalendario hoy(22, 5, 2025);

    // Crear objetos
    Carniceria carne("Carne de res", 10.5, 5.0, "kg", "Res", 7, DiaCalendario(20, 5, 2025));
    Abarrotes arroz("Arroz", 50, 25, "kg", "La Merced", "Saco", DiaCalendario(15, 8, 2025));
    Cremeria queso("Queso Oaxaca", 15, 10, "kg", DiaCalendario(30, 5, 2025));
    Verdura zanahoria("Zanahoria", 30, 10, "kg", 5, DiaCalendario(21, 5, 2025));

    // Mostrar la info de cada producto
    cout << "\n Inventario \n" << endl;
    carne.mostrarInfo();
    arroz.mostrarInfo();
    queso.mostrarInfo();
    zanahoria.mostrarInfo();

    // Probar sobrecarga de setCantidad
    cout << "\nProbando sobrecarga " << endl;
    carne.setCantidad(5.5, true); // suma 5.5 a la cantidad actual
    carne.setCantidad(20); // cambia a 20 usando entero
    carne.mostrarInfo();

    return 0;
}
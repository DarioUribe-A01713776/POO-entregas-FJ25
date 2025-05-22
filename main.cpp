#include "producto.h"
#include "diaCalendario.h"
#include <iostream>

using namespace std;

int main() {
    DiaCalendario hoy(22, 5, 2025);

    // Producto de Carnicería
    DiaCalendario fechaCarne(20, 5, 2025);
    Carniceria carne("Carne de res", 5.0, 10.0, "kg", "Vaca", 3, fechaCarne);
    cout << "Carnicería - " << carne.getNombre() << endl;
    cout << "¿Producto útil hoy? " << (carne.util(hoy) ? "Sí" : "No") << endl;
    cout << endl;

    // Producto de Abarrotes
    DiaCalendario fechaAbarrote(15, 5, 2025);
    Abarrotes arroz("Arroz", 2.0, 5.0, "kg", "Sello Rojo", "Bolsa", fechaAbarrote);
    cout << "Abarrotes - " << arroz.getNombre() << endl;
    cout << "Marca: " << arroz.getMarca() << endl;
    cout << "Empaque: " << arroz.getEmpaque() << endl;
    arroz.mostrarFcaducidad();
    cout << endl;

    // Producto de Cremería
    DiaCalendario fechaCrema(21, 5, 2025);
    Cremeria crema("Queso", 3.5, 6.0, "kg", fechaCrema);
    cout << "Cremería - " << crema.getNombre() << endl;
    crema.mostrarFcaducidad();
    cout << endl;

    // Producto de Verdura
    DiaCalendario fechaVerdura(20, 5, 2025);
    Verdura lechuga("Lechuga", 1.0, 2.0, "pieza", 2, fechaVerdura);
    cout << "Verdura - " << lechuga.getNombre() << endl;
    cout << "¿Producto útil hoy? " << (lechuga.util(hoy) ? "Sí" : "No") << endl;

    return 0;
}

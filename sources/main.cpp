#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cctype>

#include "producto.h"
#include "carniceria.h"
#include "abarrotes.h"
#include "cremeria.h"
#include "verdura.h"
#include "proveedor.h"
#include "ordenPedido.h"
#include "inventario.h"
#include "reporteInventario.h"
#include "reporteOrdenPedido.h"
#include "diaCalendario.h"

using namespace std;

// Convierte una cadena a minusculas
string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Lee una fecha desde consola
DiaCalendario leerFecha(const string& mensaje) {
    int d, m, a;
    cout << mensaje << "\n";
    cout << "Dia: ";      cin >> d;
    cout << "Mes: ";      cin >> m;
    cout << "Anio: ";     cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return DiaCalendario(d, m, a);
}

int main() {
    Inventario inventario;
    vector<Proveedor> proveedores;
    vector<OrdenPedido> pedidos;

    int opcion;
    cout << "==============================\n";
    cout << "SISTEMA INVENTARIO ENTRE ABUELAS\n";
    cout << "==============================\n";

    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Registrar nuevo producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Actualizar stock\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Agregar proveedor\n";
        cout << "6. Eliminar proveedor\n";
        cout << "7. Reporte proveedores\n";
        cout << "8. Armar orden de pedido\n";
        cout << "9. Reporte ordenes de pedido\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion no encontrada.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcion == 1) {
            string nombre, unidad, categoria;
            float cantidad, cantidadReq;
            cout << "Categoria (Carniceria, Abarrotes, Verdura, Cremeria): ";
            getline(cin, categoria);
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Cantidad existente: ";
            cin >> cantidad;
            cout << "Cantidad requerida: ";
            cin >> cantidadReq;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Unidad: ";
            getline(cin, unidad);

            DiaCalendario fechaEntrada = leerFecha("Ingrese fecha de entrada:");
            DiaCalendario fechaCaducidad;
            bool tieneCaducidad = false;
            string cat = toLower(categoria);
            if (cat == "abarrotes" || cat == "cremeria") {
                fechaCaducidad = leerFecha("Ingrese fecha de caducidad:");
                tieneCaducidad = true;
            }

            if (cat == "carniceria") {
                string tipoAnimal;
                int dias;
                cout << "Tipo de animal: ";
                getline(cin, tipoAnimal);
                cout << "Dias de vida util: ";
                cin >> dias;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inventario.agregarProducto(
                    new Carniceria(nombre, cantidad, cantidadReq, unidad,
                                   tipoAnimal, dias, fechaEntrada)
                );
            } else if (cat == "verdura") {
                int dias;
                cout << "Dias de vida util: ";
                cin >> dias;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inventario.agregarProducto(
                    new Verdura(nombre, cantidad, cantidadReq, unidad,
                                dias, fechaEntrada)
                );
            } else if (cat == "abarrotes" && tieneCaducidad) {
                string marca;
                cout << "Marca: ";
                getline(cin, marca);
                inventario.agregarProducto(
                    new Abarrotes(nombre, cantidad, cantidadReq, unidad,
                                  marca, fechaCaducidad)
                );
            } else if (cat == "cremeria" && tieneCaducidad) {
                inventario.agregarProducto(
                    new Cremeria(nombre, cantidad, cantidadReq, unidad,
                                  fechaCaducidad)
                );
            } else {
                cout << "Categoria no reconocida.\n";
            }
        } else if (opcion == 2) {
            string nombre;
            cout << "Nombre del producto a eliminar: ";
            getline(cin, nombre);
            inventario.eliminarProducto(nombre);
        } else if (opcion == 3) {
            string nombre;
            float cant;
            char tipo;
            cout << "Nombre del producto: ";
            getline(cin, nombre);
            cout << "Cantidad: ";
            cin >> cant;
            cout << "Es incremento? (s/n): ";
            cin >> tipo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Producto* prod = inventario.buscarProducto(nombre);
            if (prod) {
                float nuevaCant = prod->getCantidad();
                if (tolower(tipo) == 's') nuevaCant += cant;
                else nuevaCant -= cant;
                inventario.actualizarStock(prod, nuevaCant);
            } else {
                cout << "Producto no encontrado.\n";
            }
        } else if (opcion == 4) {
            ReporteInventario repInv(inventario);
            repInv.generar();
        } else if (opcion == 5) {
            string nombre, contacto, diaEntrega;
            cout << "Nombre proveedor: ";
            getline(cin, nombre);
            cout << "Contacto: ";
            getline(cin, contacto);
            cout << "Dia de entrega (Lunes, Martes, Miercoles, Jueves, Viernes): ";
            getline(cin, diaEntrega);
            proveedores.emplace_back(nombre, contacto, diaEntrega);
            cout << "Proveedor registrado.\n";
        } else if (opcion == 6) {
            string nombre;
            cout << "Nombre proveedor a eliminar: ";
            getline(cin, nombre);
            auto it = remove_if(proveedores.begin(), proveedores.end(),
                                [&](Proveedor& p) {
                                    return toLower(p.getNombre()) == toLower(nombre);
                                });
            if (it != proveedores.end()) {
                proveedores.erase(it, proveedores.end());
                cout << "Proveedor eliminado.\n";
            } else {
                cout << "Proveedor no encontrado.\n";
            }
        } else if (opcion == 7) {
            for (auto& p : proveedores) {
                cout << "Proveedor: " << p.getNombre()
                     << ", Contacto: " << p.getContacto()
                     << ", Dia de entrega: " << p.getDiaSemanaEntrega() << endl;
                p.mostrarProductos();
            }
        } else if (opcion == 8) {
            int id;
            string nombreProv;
            cout << "ID del pedido: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nombre del proveedor: ";
            getline(cin, nombreProv);
            auto it = find_if(proveedores.begin(), proveedores.end(),
                              [&](Proveedor& p) {
                                  return toLower(p.getNombre()) == toLower(nombreProv);
                              });
            if (it != proveedores.end()) {
                DiaCalendario fPedido = leerFecha("Ingrese la fecha del pedido:");
                DiaCalendario fEntrega = leerFecha("Ingrese la fecha de entrega:");
                OrdenPedido pedido(id, &(*it), fPedido, fEntrega);

                char seguir;
                do {
                    string nombreProd;
                    cout << "Producto a agregar al pedido: ";
                    getline(cin, nombreProd);
                    Producto* prod = inventario.buscarProducto(nombreProd);
                    if (prod) pedido.agregarProducto(prod);
                    else cout << "Producto no encontrado en inventario.\n";
                    cout << "Agregar otro producto? (s/n): ";
                    cin >> seguir;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (tolower(seguir) == 's');

                pedidos.push_back(pedido);
                cout << "Pedido registrado.\n";
            } else {
                cout << "Proveedor no encontrado.\n";
            }
        } else if (opcion == 9) {
            if (pedidos.empty()) {
                cout << "No hay pedidos registrados.\n";
            } else {
                OrdenPedido** arr = new OrdenPedido*[pedidos.size()];
                for (size_t i = 0; i < pedidos.size(); ++i) {
                    arr[i] = &pedidos[i];
                }
                ReporteOrdenPedido repPed(arr, pedidos.size());
                repPed.generar();
                delete[] arr;
            }
        } else if (opcion != 0) {
            cout << "Opcion no encontrada.\n";
        }
    } while (opcion != 0);

    cout << "\nGracias por usar el Sistema Entre Abuelas.\n";
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

#include "producto.h"
#include "carniceria.h"
#include "abarrotes.h"
#include "cremeria.h"
#include "verdura.h"
#include "proveedor.h"
#include "ordenPedido.h"
#include "inventario.h"
#include "reporteInventario.h"
#include "diaCalendario.h"
using namespace std;

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

int main() {
    Inventario inventario;
    vector<Proveedor> proveedores;
    vector<OrdenPedido> pedidos;

    int opcion;
    cout << "==============================\n";
    cout << " SISTEMA INVENTARIO ENTRE ABUELAS\n";
    cout << "==============================\n";

    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Registrar nuevo producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Actualizar stock\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Agregar proveedor\n";
        cout << "6. Eliminar proveedor\n";
        cout << "7. Mostrar proveedores\n";
        cout << "8. Armar orden de pedido\n";
        cout << "9. Mostrar ordenes de pedido\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, unidad, categoria;
            float cantidad, cantidadReq;
            cout << "Categoria (Carniceria, Abarrotes, Verdura, Cremeria): "; getline(cin, categoria);
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Cantidad existente: "; cin >> cantidad;
            cout << "Cantidad requerida: "; cin >> cantidadReq;
            cout << "Unidad: "; cin.ignore(); getline(cin, unidad);

            if (toLower(categoria) == "carniceria") {
                string tipoAnimal; int dias; DiaCalendario fecha;
                cout << "Tipo de animal: "; getline(cin, tipoAnimal);
                cout << "Dias de vida util: "; cin >> dias;
                fecha = DiaCalendario();
                inventario.agregarProducto(new Carniceria(nombre, cantidad, cantidadReq, unidad, tipoAnimal, dias, fecha));
            } else if (toLower(categoria) == "verdura") {
                int dias; DiaCalendario fecha;
                cout << "Dias de vida util: "; cin >> dias;
                fecha = DiaCalendario();
                inventario.agregarProducto(new Verdura(nombre, cantidad, cantidadReq, unidad, dias, fecha));
            } else if (toLower(categoria) == "abarrotes") {
                string marca, empaque; DiaCalendario fCad;
                cout << "Marca: "; cin.ignore(); getline(cin, marca);
                cout << "Empaque: "; getline(cin, empaque);
                fCad = DiaCalendario();
                inventario.agregarProducto(new Abarrotes(nombre, cantidad, cantidadReq, unidad, marca, empaque, fCad));
            } else if (toLower(categoria) == "cremeria") {
                DiaCalendario fCad;
                fCad = DiaCalendario();
                inventario.agregarProducto(new Cremeria(nombre, cantidad, cantidadReq, unidad, fCad));
            }
        }

        else if (opcion == 2) {
            string nombre;
            cout << "Nombre del producto a eliminar: "; getline(cin, nombre);
            inventario.eliminarProducto(nombre);
        }

        else if (opcion == 3) {
            string nombre; float cant; char tipo;
            cout << "Nombre del producto: "; getline(cin, nombre);
            cout << "Cantidad: "; cin >> cant;
            cout << "Es incremento? (s/n): "; cin >> tipo; cin.ignore();
            inventario.actualizarStock(nombre, cant, tipo == 's');
        }

        else if (opcion == 4) {
            ReporteInventario reporte(inventario);
            reporte.generar();
        }

        else if (opcion == 5) {
            string nombre, contacto;
            cout << "Nombre proveedor: "; getline(cin, nombre);
            cout << "Contacto: "; getline(cin, contacto);
            DiaCalendario fecha;
            proveedores.push_back(Proveedor(nombre, contacto, fecha));
            cout << "Proveedor registrado.\n";
        }

        else if (opcion == 6) {
            string nombre;
            cout << "Nombre proveedor a eliminar: "; getline(cin, nombre);
            auto it = remove_if(proveedores.begin(), proveedores.end(), [&](Proveedor& p) {
                return toLower(p.getNombre()) == toLower(nombre);
            });
            if (it != proveedores.end()) {
                proveedores.erase(it, proveedores.end());
                cout << "Proveedor eliminado.\n";
            } else cout << "Proveedor no encontrado.\n";
        }

        else if (opcion == 7) {
            for (Proveedor& p : proveedores) {
                cout << "Proveedor: " << p.getNombre() << ", Contacto: " << p.getContacto() << endl;
                p.mostrarProductos();
            }
        }

        else if (opcion == 8) {
            int id; string nombreProv; DiaCalendario fPedido, fEntrega;
            cout << "ID del pedido: "; cin >> id; cin.ignore();
            cout << "Nombre del proveedor: "; getline(cin, nombreProv);
            auto it = find_if(proveedores.begin(), proveedores.end(), [&](Proveedor& p) {
                return toLower(p.getNombre()) == toLower(nombreProv);
            });
            if (it != proveedores.end()) {
                OrdenPedido pedido(id, *it, fPedido, fEntrega);
                char seguir;
                do {
                    string nombreProd;
                    cout << "Producto a agregar al pedido: "; getline(cin, nombreProd);
                    Producto* p = inventario.buscarProducto(nombreProd);
                    if (p) pedido.agregarProducto(p);
                    else cout << "Producto no encontrado en inventario.\n";
                    cout << "Agregar otro producto? (s/n): "; cin >> seguir; cin.ignore();
                } while (seguir == 's');
                pedidos.push_back(pedido);
                cout << "Pedido registrado.\n";
            } else {
                cout << "Proveedor no encontrado.\n";
            }
        }

        else if (opcion == 9) {
            for (const OrdenPedido& p : pedidos)
                p.mostrarPedido();
        }

    } while (opcion != 0);

    cout << "\nGracias por usar el Sistema Entre Abuelas.\n";
    return 0;
}

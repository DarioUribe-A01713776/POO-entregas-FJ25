// reporteOrdenPedido.cpp
// Descripción: Implementación de ReporteOrdenPedido.
// Autor: Darío A. Uribe
// Fecha: 11/06/2025
// Notas: Recorre el arreglo de órdenes y llama a mostrarPedido() en cada una.

#include "reporteOrdenPedido.h"
#include <iostream>

ReporteOrdenPedido::ReporteOrdenPedido(OrdenPedido** arr, int count)
    : pedidos(arr), numPedidos(count) {}

void ReporteOrdenPedido::generar() const {
    std::cout << "--- Ordenes de Pedido ---" << std::endl;
    for (int i = 0; i < numPedidos; ++i) {
        pedidos[i]->mostrarPedido();
    }
    std::cout << "-------------------------" << std::endl;
}

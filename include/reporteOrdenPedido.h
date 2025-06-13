// reporteOrdenPedido.h
// Descripción: Reporte concreto que genera un resumen de las órdenes de pedido.
// Autor: Darío A. Uribe
// Fecha: 11/06/2025
// Notas: Implementa la interfaz Reporte para listar cada orden, su ID, fechas

#ifndef REPORTEORDENPEDIDO_H
#define REPORTEORDENPEDIDO_H

#include "reporte.h"
#include "ordenPedido.h"

class ReporteOrdenPedido : public Reporte {
private:
    OrdenPedido** pedidos;
    int numPedidos;
public:
    ReporteOrdenPedido(OrdenPedido** arr, int count);
    void generar() const override;
};

#endif

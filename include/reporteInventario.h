// reporteInventario.h
// Descripción: Reporte concreto que imprime el estado del inventario.
// Autor: Darío A. Uribe
// Fecha: 11/06/2025
// Notas: Implementa la clase Reporte para mostrar productos del inventario.

#ifndef REPORTEINVENTARIO_H
#define REPORTEINVENTARIO_H

#include "reporte.h"
#include "inventario.h"

class ReporteInventario : public Reporte {
private:
    const Inventario& inventario;
public:
    ReporteInventario(const Inventario& inv);
    void generar() const override;
};

#endif // REPORTEINVENTARIO_H

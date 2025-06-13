// reporte.h
// Descripción: Clase abstracta para generación de reportes del sistema.
// Autor: Darío A. Uribe
// Fecha: 11/06/2025
// Notas: Define la interfaz base para diferentes tipos de reporte.

// reporte.h
#ifndef REPORTE_H
#define REPORTE_H

class Reporte {
public:
    virtual void generar() const = 0;  // interfaz pura
    virtual ~Reporte() {}              // destructor virtual
};

#endif

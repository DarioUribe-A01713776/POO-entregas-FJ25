// reporte.h
// Descripción: Clase abstracta para generación de reportes del sistema.
// Autor: Darío A. Uribe
// Fecha: 06/06/2025
// Notas: Define la interfaz base para diferentes tipos de reporte.

#ifndef REPORTE_H
#define REPORTE_H

class Reporte {
public:
    virtual void generar() const = 0;  
    virtual ~Reporte() {}              
};

#endif

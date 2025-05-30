#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

// Clase Producto
class Producto {
protected:
    string nombre;
    float cantidad;
    float cantidadRequerida;
    string unidad;
    DiaCalendario fechaEntrada;

public:
    Producto();
    Producto(string n, float c, float cr, string u, DiaCalendario f);

    string getNombre() const;
    float getCantidad() const;
    float getCantidadRequerida() const;
    string getUnidad() const;
    DiaCalendario getFechaEntrada() const;

    void setNombre(string);
    void setCantidad(float);
    void setCantidad(int); // Sobrecarga con int
    void setCantidad(float, bool); // Sobrecarga con incremento
    void setCantidadRequerida(float);
    void setUnidad(string);
    void setFechaEntrada(DiaCalendario);

    virtual void mostrarInfo() const;
};

Producto::Producto(string n, float c, float cr, string u, DiaCalendario f)
    : nombre(n), cantidad(c), cantidadRequerida(cr), unidad(u), fechaEntrada(f) {}

string Producto::getNombre() const { return nombre; }
float Producto::getCantidad() const { return cantidad; }
float Producto::getCantidadRequerida() const { return cantidadRequerida; }
string Producto::getUnidad() const { return unidad; }
DiaCalendario Producto::getFechaEntrada() const { return fechaEntrada; }

void Producto::setNombre(string n) { nombre = n; }
void Producto::setCantidad(float c) { cantidad = c; }
void Producto::setCantidad(int c) { cantidad = static_cast<float>(c); }
void Producto::setCantidad(float c, bool esIncremento) {
    if (esIncremento) cantidad += c;
    else cantidad = c;
}
void Producto::setCantidadRequerida(float cr) { cantidadRequerida = cr; }
void Producto::setUnidad(string u) { unidad = u; }
void Producto::setFechaEntrada(DiaCalendario f) { fechaEntrada = f; }

void Producto::mostrarInfo() const {
    cout << "[Producto] " << nombre << ", " << cantidad << " " << unidad << endl;
}

// Clase Carniceria
class Carniceria : public Producto {
private:
    string tipoAnimal;
    int diasVidaUtil;

public:
    Carniceria(string n, float c, float cr, string u, string ta, int dv, DiaCalendario f);

    string getTipoAnimal() const;
    int getDiasVidaUtil() const;

    void setTipoAnimal(string);
    void setDiasVidaUtil(int);

    bool util(const DiaCalendario&) const;
    void mostrarInfo() const override;
};

Carniceria::Carniceria(string n, float c, float cr, string u, string ta, int dv, DiaCalendario f)
    : Producto(n, c, cr, u, f), tipoAnimal(ta), diasVidaUtil(dv) {}

string Carniceria::getTipoAnimal() const { return tipoAnimal; }
int Carniceria::getDiasVidaUtil() const { return diasVidaUtil; }

void Carniceria::setTipoAnimal(string ta) { tipoAnimal = ta; }
void Carniceria::setDiasVidaUtil(int dv) { diasVidaUtil = dv; }

bool Carniceria::util(const DiaCalendario& hoy) const {
    return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
}

void Carniceria::mostrarInfo() const {
    cout << "[Carniceria] " << nombre << " (" << tipoAnimal << "), "
         << cantidad << " " << unidad << ", Vida util: " << diasVidaUtil << " dias" << endl;
}

// Clase Abarrotes
class Abarrotes : public Producto {
private:
    string marca;
    string empaque;
    DiaCalendario fCaducidad;

public:
    Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f);

    string getMarca() const;
    string getEmpaque() const;
    DiaCalendario getFcaducidad() const;

    void setMarca(string);
    void setEmpaque(string);
    void setFcaducidad(DiaCalendario);

    void mostrarFcaducidad() const;
    void mostrarInfo() const override;
};

Abarrotes::Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f)
    : Producto(n, c, cr, u, f), marca(m), empaque(e), fCaducidad(f) {}

string Abarrotes::getMarca() const { return marca; }
string Abarrotes::getEmpaque() const { return empaque; }
DiaCalendario Abarrotes::getFcaducidad() const { return fCaducidad; }

void Abarrotes::setMarca(string m) { marca = m; }
void Abarrotes::setEmpaque(string e) { empaque = e; }
void Abarrotes::setFcaducidad(DiaCalendario f) { fCaducidad = f; }

void Abarrotes::mostrarFcaducidad() const {
    cout << "Fecha de caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

void Abarrotes::mostrarInfo() const {
    cout << "[Abarrotes] " << nombre << ", Marca: " << marca
         << ", Empaque: " << empaque << ", Cantidad: " << cantidad << " " << unidad
         << ", Caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

// Clase Cremeria
class Cremeria : public Producto {
private:
    DiaCalendario fCaducidad;

public:
    Cremeria(string n, float c, float cr, string u, DiaCalendario f);

    DiaCalendario getFcaducidad() const;
    void setFcaducidad(DiaCalendario);

    void mostrarFcaducidad() const;
    void mostrarInfo() const override;
};

Cremeria::Cremeria(string n, float c, float cr, string u, DiaCalendario f)
    : Producto(n, c, cr, u, f), fCaducidad(f) {}

DiaCalendario Cremeria::getFcaducidad() const { return fCaducidad; }
void Cremeria::setFcaducidad(DiaCalendario f) { fCaducidad = f; }

void Cremeria::mostrarFcaducidad() const {
    cout << "Fecha de caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

void Cremeria::mostrarInfo() const {
    cout << "[Cremeria] " << nombre << ", " << cantidad << " " << unidad << ", Caducidad: ";
    fCaducidad.mostrar();
    cout << endl;
}

// Clase Verdura
class Verdura : public Producto {
private:
    int diasVidaUtil;

public:
    Verdura(string n, float c, float cr, string u, int dv, DiaCalendario f);

    int getDiasVidaUtil() const;
    void setDiasVidaUtil(int);

    bool util(const DiaCalendario&) const;
    void mostrarInfo() const override;
};

Verdura::Verdura(string n, float c, float cr, string u, int dv, DiaCalendario f)
    : Producto(n, c, cr, u, f), diasVidaUtil(dv) {}

int Verdura::getDiasVidaUtil() const { return diasVidaUtil; }
void Verdura::setDiasVidaUtil(int dv) { diasVidaUtil = dv; }

bool Verdura::util(const DiaCalendario& hoy) const {
    return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
}

void Verdura::mostrarInfo() const {
    cout << "[Verdura] " << nombre << ", " << cantidad << " " << unidad
         << ", Vida útil: " << diasVidaUtil << " días" << endl;
}

#endif

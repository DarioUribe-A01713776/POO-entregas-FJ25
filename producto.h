#ifndef PRODUCTO_H
#define PRODUCTO_H


#include "diaCalendario.h"
#include <iostream>
#include <string>

using namespace std;

//Clase Producto 
class Producto{
    protected:
        string nombre;
        float cantidad;
        float cantidadRequerida;
        string unidad;   
        DiaCalendario fechaEntrada;

    public:
        Producto(string n, float c, float cr, string u, DiaCalendario f)
        : nombre(n), cantidad(c), cantidadRequerida(cr), unidad(u), fechaEntrada(f) {}
        
        string getNombre() const;
        float getCantidad() const;
        float getCantidadRequerida() const;
        string getUnidad() const;
        DiaCalendario getFechaEntrada() const;

        void setNombre(string);
        void setCantidad(float);
        void setCantidadRequerida(float);
        void setUnidad(string);
        void setFechaEntrada(DiaCalendario f);
};

string Producto::getNombre() const{
    return nombre;
}
float Producto::getCantidad() const{
    return cantidad;
}
float Producto::getCantidadRequerida() const{
    return cantidadRequerida;
}
string Producto::getUnidad() const{
    return unidad;
}
DiaCalendario Producto::getFechaEntrada() const{
    return fechaEntrada;
}

void Producto::setNombre(string n) {
    nombre = n;
}
void Producto::setCantidad(float c){
    cantidad = c;
}
void Producto::setCantidadRequerida(float cr){
    cantidadRequerida = cr;
}
void Producto::setUnidad(string u){
    unidad = u;
}
void Producto::setFechaEntrada(DiaCalendario f){
    fechaEntrada = f;
}

//Clase carniceria
class Carniceria: public Producto{
    private:
        string tipoAnimal;
        int diasVidaUtil;
    public:
        Carniceria(string n, float c, float cr, string u, string ta, int dv, DiaCalendario f)
        : Producto(n, c, cr, u, f), tipoAnimal(ta), diasVidaUtil(dv){}
         
        string getTipoAnimal() const;
        int getDiasVidaUtil() const;

        void setTipoAnimal(string);
        void setDiasVidaUtil(int);

        bool util(const DiaCalendario& hoy) const {
        return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
    }

};

    string Carniceria::getTipoAnimal() const{
        return tipoAnimal;
    }
    int Carniceria::getDiasVidaUtil() const{
        return diasVidaUtil;
    }

    void Carniceria::setTipoAnimal(string ta){
        tipoAnimal = ta;
    } 
    void Carniceria::setDiasVidaUtil(int dv){
        diasVidaUtil = dv;
    }

//Clase Abarrotes
class Abarrotes: public Producto{
    private: 
        string marca;
        string empaque;
        DiaCalendario fCaducidad;
    public:
        Abarrotes(string n, float c, float cr, string u, string m, string e, DiaCalendario f)
        : Producto(n, c, cr, u, f), marca(m), empaque(e), fCaducidad(f){}

        string getMarca() const;
        string getEmpaque() const;
        DiaCalendario getFcaducidad() const;
        
        void setMarca(string);
        void setEmpaque(string);
        void setFcaducidad(DiaCalendario f);

        void mostrarFcaducidad() const{
            cout << "Fecha de caducidad: ";
            fCaducidad.mostrar();
            cout << endl;
        }
};

string Abarrotes::getMarca() const{
    return marca;
}
string Abarrotes::getEmpaque() const{
    return empaque;
}
DiaCalendario Abarrotes::getFcaducidad() const{
    return fCaducidad;
}

void Abarrotes::setMarca(string m){
    marca = m;
}
void Abarrotes::setEmpaque(string e){
    empaque = e;
}
void Abarrotes::setFcaducidad(DiaCalendario f){
    fCaducidad = f;
}

//Clase Cremeria
class Cremeria : public Producto{
    private: 
        DiaCalendario fCaducidad;
    public:
        Cremeria(string n, float c, float cr, string u, DiaCalendario f)
        : Producto(n, c, cr, u, f), fCaducidad(f){}

        DiaCalendario getFcaducidad () const;
        void setFcaducidad (DiaCalendario f);

        void mostrarFcaducidad() const{
            cout << "Fecha de caducidad: ";
            fCaducidad.mostrar();
            cout << endl;
        }
};
 
DiaCalendario Cremeria::getFcaducidad() const{
    return fCaducidad;
}

void Cremeria::setFcaducidad(DiaCalendario f){
    fCaducidad = f;
}

//Clase Verdura

class Verdura : public Producto{
    private:
        int diasVidaUtil;
    public:
        Verdura(string n, float c, float cr, string u, int dv, DiaCalendario f)
        : Producto(n, c, cr, u, f), diasVidaUtil(dv){}

        int getDiasVidaUtil () const;
        void setDiasVidaUtil (int);
        
        bool util(const DiaCalendario& hoy) const {
        return fechaEntrada.estaDentroDeDias(hoy, diasVidaUtil);
    }
};

int Verdura::getDiasVidaUtil() const{
    return diasVidaUtil;
}

void Verdura::setDiasVidaUtil(int dv){
    diasVidaUtil = dv;
}

#endif
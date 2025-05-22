#ifndef PRODUCTO_H
#define PRODUCTO_H

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
    public:
        Producto(string n, float c, float cr, string u)
        : nombre(n), cantidad(c), cantidadRequerida(cr), unidad(u){}
        
        string getNombre() const;
        float getCantidad() const;
        float getCantidadRequerida() const;
        string getUnidad() const;

        void setNombre(string);
        void setCantidad(float);
        void setCantidadRequerida(float);
        void setUnidad(string);
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


//Clase carniceria

class Carniceria: public Producto{
    private:
        string tipoAnimal;
        int diasVidaUtil;
    public:
        Carniceria(string n, float c, float cr, string u, string ta, int dv)
        : Producto(n, c, cr, u), tipoAnimal(ta), diasVidaUtil(dv){}
         
        string getTipoAnimal() const;
        int getDiasVidaUtil() const;
        void setTipoAnimal(string);
        void setDiasVidaUtil(int);
        
};

#endif
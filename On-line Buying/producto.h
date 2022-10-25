#pragma once
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto{

    private:
    int codigo;
    string nombre;
    string marca;
    double precio;

    public:
    Producto();
    Producto(int codigo,string nombre,string marca,double precio);
    int getCodigo();
    string getNombre();
    string getMarca();
    double getPrecio();
    void setCodigo(int codigo);
    void setNombre(string nombre);
    void setMarca(string marca);
    void setPrecio(double precio);
    void imprimeProducto();
    
   
};

Producto::Producto(){
    codigo=0;
    nombre="Sin Nombre";
    marca="Sin Marca";
    precio=0.0;
}
Producto::Producto(int codigo,string nombre,string marca,double precio){
    this->codigo=codigo;
    this->nombre=nombre;
    this->marca=marca;
    this->precio=precio;
}
int Producto::getCodigo(){
    return codigo;
}
string Producto::getNombre(){
    return nombre;
}
string Producto::getMarca(){
    return marca;
}
double Producto::getPrecio(){
    return precio;
}

void Producto::setCodigo(int codigo){
    this->codigo=codigo;
}
void Producto::setNombre(string nombre){
    this->nombre=nombre;
}
void Producto::setMarca(string marca){
    this->marca=marca;
}
void Producto::setPrecio(double precio){
    this->precio=precio;
}
void Producto::imprimeProducto(){
        cout<<"- "<<nombre<<"     Marca: "<<marca<<"Codigo["<<codigo<<"]         Precio: $"<<precio<<endl;
}

#endif


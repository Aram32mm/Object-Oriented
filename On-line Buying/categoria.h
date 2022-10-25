#pragma once
#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>
#include "producto.h"

using namespace std;

class Categoria{

    private:
    int codigo;
    string nombre;
    Producto productos[5];
    Producto carrito[20];
    
    public:
    Categoria();
    Categoria(int codigo,string nombre);
    int getCodigo();
    string getNombre();
    void setCodigo(int codigo);
    void setNombre(string nombre);
    void imprimirCategoria();  
    void imprimirProducto(int c);
    void agregarProducto(Producto producto, int pos);
    void imprimirCarrito();
    void agregarCarrito(int pos);
    double calcularPreciofinal();



};


Categoria::Categoria(){
    codigo=0;
    nombre="Sin Categoria";
}
Categoria::Categoria(int codigo,string nombre){
    this->codigo=codigo;
    this->nombre=nombre;
}
int Categoria::getCodigo(){
    return codigo;
}
string Categoria::getNombre(){
    return nombre;
}
void Categoria::setCodigo(int codigo){
    this->codigo=codigo;
}
void Categoria::setNombre(string nombre){
    this->nombre=nombre;
}

void Categoria::imprimirCategoria(){
    cout<<"\n"<<nombre<<":\n"<<endl;
    for (int i=0;i<5;i++){
        productos[i].imprimeProducto();
    }
}

void Categoria::imprimirProducto(int c){
    productos[c].imprimeProducto();
}

void Categoria::agregarProducto(Producto producto, int pos){
    productos[pos]=producto;
}

void Categoria::agregarCarrito(int pos){
    if(carrito[pos].getPrecio() == 0){
        carrito[pos]=productos[pos];
    }else if(carrito[pos+5].getPrecio() == 0){
        carrito[pos+5]=productos[pos];
    }else if(carrito[pos+10].getPrecio() == 0){
        carrito[pos+10]=productos[pos];
    }else if(carrito[pos+15].getPrecio() == 0){
        carrito[pos+15]=productos[pos];
    }else{
        cout<<"Producto límitado a 4 ventas por cada compra registrada";
    }
}

void Categoria::imprimirCarrito(){
    for (int i=0;i<20;i++){
        if(carrito[i].getPrecio() != 0){
            carrito[i].imprimeProducto();
        }else{
            continue;
        }
    }
}

double Categoria::calcularPreciofinal(){
    double subtotal=0;
    for (int i=0;i<20;i++){
        subtotal += carrito[i].getPrecio();
    }
    return subtotal;
}



#endif
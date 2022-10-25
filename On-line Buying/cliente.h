#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;
#include "categoria.h"

class Cliente{

    private:

    string nombreUsuario;
    string correo;
    string contra;
    int cvv;

    public:

    Cliente();
    Cliente(string nombreUsuario,string correo,string contra,int cvv);
    string getNombreUsuario();
    string getCorreo();
    string getContra();
    void setNombreUsuario(string NombreUsuario);
    void setCorreo(string correo);
    void setContra(string contra);
    void pago(int cvv);

    
    
   
};


Cliente::Cliente(){
    nombreUsuario=" ";
    correo=" ";
    contra=" ";
    cvv=0;
}
Cliente::Cliente(string nombreUsuario,string correo,string contra,int cvv){
    this->nombreUsuario=nombreUsuario;
    this->correo=correo;
    this->contra=correo;
    this->cvv=cvv;

}
string Cliente::getNombreUsuario(){
    return nombreUsuario;
}
string Cliente::getCorreo(){
    return correo;
}
string Cliente::getContra(){
    return contra;
}
void Cliente::setNombreUsuario(string NombreUsuario){
    this->nombreUsuario=NombreUsuario;
}
void Cliente::setCorreo(string correo){
    this->correo=correo;
}
void Cliente::setContra(string contra){
    this->contra=correo;
}
void Cliente::pago(int cvv){
    this->cvv=cvv;
}
#endif
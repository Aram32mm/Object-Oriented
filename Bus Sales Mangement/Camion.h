#include <iostream>
#include "Pasajero.h"
using namespace std;

class Camion{

    private:
        int asientos[50];
        string destino;
        Pasajero pasajeros[50];

    public:
        Camion();
        Camion(string destino);
        string getDestino();

    

        void venderAsiento(string nombre,string apellidoP,string apellidoM,int pos);

        int boletosVendidos();

};

Camion::Camion(){
    destino="Sin Destino.";
}
Camion::Camion(string destino){
    this->destino=destino;
    for (int i=0;i<50;i++){
        asientos[i]=0;
    }
}

string Camion::getDestino(){
    return destino;
} 

void Camion::venderAsiento(string nombre,string apellidoP,string apellidoM,int pos){
    int p; p = pos -1;
    if (asientos[p]==1){
        cout<<"Asiento ya ocupado.";

    }else{
        asientos[p]=1;
        pasajeros[p]=Pasajero(nombre,apellidoP,apellidoM);
        cout<<"Agregado.";
    }
    
}
int Camion::boletosVendidos(){
    int cont=0;
    for (int i=0;i<50;i++){
        if(asientos[i]==1){
            cont +=1;
        }
    }
    return cont;
}
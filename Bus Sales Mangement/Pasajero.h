#include <iostream>
using namespace std;

class Pasajero{

    private:

        string nombre;
        string apellidoP;
        string apellidoM;

    public:
        Pasajero();
        Pasajero(string nombre,string apellidoP,string apellidoM);
        void setNombre(string nombre);
        void setApellidoP(string apellidoP);
        void setApellidoM(string apellidoM);
        string getNombre();
        string getApellidoP();
        string getApellidoM();
    
};

Pasajero::Pasajero(){
    nombre=" ";
    apellidoP=" ";
    apellidoM=" ";
}
Pasajero::Pasajero(string nombre,string apellidoP,string apellidoM){
    this->nombre=nombre;
    this->apellidoP=apellidoP;
    this->apellidoM=apellidoM;
}
void Pasajero::setNombre(string nombre){
    this->nombre=nombre;
}
void Pasajero::setApellidoP(string apellidoP){
    this->apellidoP=apellidoP;
}
void Pasajero::setApellidoM(string apellidoM){
    this->apellidoM=apellidoM;
}
string Pasajero::getNombre(){
    return nombre;
}
string Pasajero::getApellidoP(){
    return apellidoP;
}
string Pasajero::getApellidoM(){
    return apellidoM;
}
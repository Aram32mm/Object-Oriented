#include <iostream>
#include <string>
#include "Camion.h"

using namespace std;

int main(){
    string destino;
    cout<<"Ingrese el destino del camión: ";cin>>destino;
    Camion c1(destino);

    int r = 1; string respuesta = ""; //Para do-while 
    int bV = 0;
    int opcion=0; //para switch
    string nombre;
    string apellidoP;
    string apellidoM;
    int asiento;
   

        do{
            cout<<"\nQue quieres hacer? "<<endl;
            cout<<"> Agregar Pasajero     [1]"<<endl;
            cout<<"> Cerrar Camion        [2]"<<endl;


            cout<<"Seleccione el código de la opción que desea realizar: "; 
            cin>>opcion;
            switch(opcion)
            {
                case 1: 
                        cout<<"Nombre: "; cin>>nombre;
                        cout<<"Apellido Paterno: ";cin>>apellidoP;
                        cout<<"Apellido Materno: ";cin>>apellidoM;
                        cout<<"Qué asiento quieres: "; cin>>asiento;
                        c1.venderAsiento(nombre,apellidoP,apellidoM,asiento);
                        cout<<"\n";
                        break;
    
                case 2 :cout<<"Camión Cerrado"<<endl;
                        bV = c1.boletosVendidos();
                        cout<<"Boletos Vendidos: "<<bV<<endl;
                        cout<<"Monto Generado $ "<<bV*600<<endl;
                        r +=1;
                        break;
                        
                default:   
                        cout<<"Opción Inválida"<<endl;    
                        break;
        
            }

        }while (r==1);
        
    return 0;

}

    
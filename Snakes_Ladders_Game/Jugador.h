#ifndef _JUGADOR_
#define _JUGADOR_

#include <iostream>


class Jugador{
    char numJugador; //lo defino como char para hacer match con el array de casillas...
    std::string nombre;
    int posicion;
    public:
        Jugador(char num, std::string name){
            numJugador = num;
            nombre = name;
            posicion = -1;
        };

        int getPosicion(){
            return posicion;
        };
        void setPosicion(int pos){
            posicion = pos;
        };

        int tirarDado(){
            std::srand(time(NULL));
            int dado = 1 + rand()%6; //1-6
            std::cout << nombre << " sacó un " << dado << std::endl;
            return dado;
        };
        char getNumJugador(){
            return numJugador;
        };

        void printPlayer(){
            std::cout << "Nombre: " << nombre << std::endl;
            std::cout << "Número: " << numJugador << std::endl;
            std::cout << "Posición: " << posicion << std::endl<< std::endl;
        };
};

#endif
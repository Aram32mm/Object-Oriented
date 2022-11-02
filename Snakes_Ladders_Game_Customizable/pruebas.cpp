

#include <iostream>
#include "Tablero.h"
using namespace std;

int main() {
    int size = 30; //tamaño del tablero
    int numJugadores = 3; //numero de jugadores
    int serpientes = 4; //numero de serpientes
    int escalera = 4; //numero de escaleras
    int penalty = 3; // numero de casillas que retrocede el jugador si cae en serpiente
    int reward = 3; //numero de casillas que avanza el jugador si cae en escalera
    int maxTurno = 10; //numero máximo de turnos

    Tablero t(size, numJugadores,serpientes, penalty, escalera, reward);
    t.automaticGame2(numJugadores, maxTurno);
    //t.manualGame(numJugadores, maxTurno);



}
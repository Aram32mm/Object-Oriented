#include <iostream>
#include "Tablero.h"
#include "Jugador.h"
using namespace std;

void tirar(Jugador j, Tablero tablero);

int main()
{
    cout<<"Bienvenido a este Juego de Serpientes y Escaleras"<<endl;
    Tablero tablero1;
    tablero1.imprimeTablero();

    Jugador j1('1', "Jugador 1");
    j1.printPlayer();
    Jugador j2('2', "Jugador 2");
    j2.printPlayer();

    int cont = 0;
    char conti = 'C';
    
    cout<< "Presiona Enter para inciar el juego"; cin.get();

    do
    {
        cont +=1;

        if (cont % 2 != 0)
        {
            int t = j1.tirarDado();
            int nuevaPos = j1.getPosicion() + t;
            // checar si ya ganó
            if (nuevaPos >= 29)
            {
                // ganó...
                cout << "Ganó el jugador " << endl;
                j1.printPlayer();
                break;
            };
            // checar si cayó en una escalera o serpiente...
            if (tablero1.getCasilla(nuevaPos) == 'E')
            {
                // escalera
                nuevaPos += 3;
            };
            if (tablero1.getCasilla(nuevaPos) == 'S')
            {
                // serpiente
                nuevaPos -= 3;
            };
            Tablero tableroCopia;
            tableroCopia = tablero1;
            j1.setPosicion(nuevaPos);
            tableroCopia.setCasilla(j1.getNumJugador(), nuevaPos);
            tableroCopia.imprimeTablero();
            j1.printPlayer();
        }
        else if (cont % 2 == 0)
        {
            int s = j2.tirarDado();
            int nuevaPos2 = j2.getPosicion() + s;
            // checar si ya ganó
            if (nuevaPos2 >= 29)
            {
                // ganó...
                cout << "Ganó el jugador " << endl;
                j2.printPlayer();
            };
            // checar si cayó en una escalera o serpiente...
            if (tablero1.getCasilla(nuevaPos2) == 'E')
            {
                // escalera
                nuevaPos2 += 3;
            };
            if (tablero1.getCasilla(nuevaPos2) == 'S')
            {
                // serpiente
                nuevaPos2 -= 3;
            };
            Tablero tableroCopia;
            tableroCopia = tablero1;
            j2.setPosicion(nuevaPos2);
            tableroCopia.setCasilla(j2.getNumJugador(), nuevaPos2);
            tableroCopia.imprimeTablero();
            j2.printPlayer();
        }

        cout << "Presiona [C/c] para continuar o cualuquier otra letra para terminar : ";
        cin >> conti;

    } while (conti == 'c' || conti == 'C');
    cout<<"Fin del Juego. Gracias por Jugar";
}
#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Casilla.h"
#include <vector>
#include "Jugador.h"
using std::vector;

class Tablero {

    int tamaño;
    Jugador j[10];
    int winner;
    vector<Casilla> board;
    CasillaNormal c;
    Serpiente s;
    Escalera l;
    

    public:

    void setWinner(int win) {
        winner = win;
    }

    int getWinner(){
        return winner;
    }


    void imprimeTablero2() {

        for(int i = 0; i < tamaño; i++) {
            std::cout << "["<<i<<"]" << "  ";
            
         };

        std::cout << " " << std::endl;

        for(int i = 0; i < tamaño; i++) {
            std::cout << "["<<board[i].getType()<<"]" << "  ";
            
         };

         std::cout << " " << std::endl;
    
    }

    Tablero(int size, int numJugadores, int serpientes, int penalty, int escaleras, int reward) { //, int serpientes, int penalty, int reward, int turns


        setWinner(0);
        tamaño = size;



        s.setPenalty(penalty);
        l.setReward(reward);

        if(serpientes > tamaño/4) {
            serpientes = tamaño/4;
        }

        if(escaleras > tamaño/4) {
            escaleras = tamaño/4;
        }

        s.setPenalty(penalty);
        l.setReward(reward);

        //Llenamos el tablero con casillas normales 
        for(int i = 0; i < size; i++) {
            
            board.push_back(c);
        }

        // board.at(4) = s;
        // board.at(6) = s;

        std::srand((unsigned)time(0)); 
        int randomNumber = rand() % (size);

        // Este chunk de código generar numeros random al azar para serpientes y escaleras
        bool verificador;
        srand(time(NULL));
        int numerosrequeridos = serpientes + escaleras;
        int arreglo[numerosrequeridos], num = 0;

        for (int i = 0; i < numerosrequeridos; i++)
        {
            do
            {
                num = rand() % size;

                for (int i = 0; i < numerosrequeridos; i++)
                {
                    if (num == arreglo[i])
                    {
                        verificador = true;
                        break;
                    }
                    else if (num == 0)
                    {
                        verificador = true;
                        break;
                    }
                    else if (num >= size - reward)
                    {
                        verificador = true;
                        break;
                    }
                    else if (num <= penalty)
                    {
                        verificador = true;
                        break;
                    }
                    else
                    {
                        verificador = false;
                    }
                }

            } while (verificador == true);
            arreglo[i] = num;
        }
        
        // Ya tenemos nuestro arreglo con numeros al azar
        // Metemos los objetos serpientes y casillas en las posiciones

        for (int i = 0; i < numerosrequeridos; i++)
        {
            int numR = arreglo[i];
            if (i % 2 == 0)
            {
                board.at(numR) = s;
            }
            else
            {
                board.at(numR) = l;
            }
        }

        //poner a los jugadores
        
        j[numJugadores];
        
        for(int i = 0; i<numJugadores; i++) {
           j[i].setNumber(i+1);
           j[i].setPosition(-1);
          
           
        };


    };

    void automaticGame2(int numJugadores, int maxTurno) {
        
        int reward = l.getReward();
        int penalty = s.getPenalty();
        
        int turno = 1;
        int numTurno = 0;
        
        std::cout << "GAME" << std::endl;
        std::cout << "________________" << std::endl;
        srand((unsigned)time(0));

        while(turno < maxTurno) {
            
            for(int i=0; i < numJugadores; i++) {
            int dice = 1 + rand() % (6);
            
            imprimeTablero2();
    
            std::cout << "TURN: " << turno << std::endl;
            std::cout << "PLAYER: " << j[i].getNumber() << " "<< std::endl;
            std::cout << "POSITION: " << j[i].getPosition() << std::endl;
            std::cout << "DICE: " << dice << std::endl;
            std::cout << "MOVES TO:  " << j[i].getPosition() + dice << std::endl;
        
            if((j[i].getPosition() + dice) > tamaño) {
                std::cout << "THE PLAYER:" << j[i].getNumber() << "WINS THE GAME" << std::endl;
                std::cout << "END GAME" << std::endl;
                numTurno = turno;
                turno = 10;
                break;
                
                
            }

            else {
                if(board[j[i].getPosition() + dice].getType()  == 'N') {
                    std::cout << "NORMAL TILE" << std::endl;
                    std::cout << "THE PLAYER " << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice);
                    
                }

                else if(board[j[i].getPosition() + dice].getType() == 'S') {
                    std::cout << "SNAKE" << std::endl;
                    std::cout << "GO BACK " << penalty << " TILES" << std::endl;
                    std::cout << "THE PLAYER " << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice - penalty << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice - penalty);
                    
                }

                else if(board[j[i].getPosition() + dice].getType() == 'L') {
                    std::cout << "LADDER" << std::endl;
                    std::cout << "ADVANCE " << reward << " TILES" << std::endl;
                    std::cout << "THE PLAYER" << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice + reward << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice + reward);
                    
                };
                };

            
            
           
            
                };

        
         turno = turno +1;
         std::cout << "________________" << std::endl;

        }

        if(numTurno == 0) {
            std::cout << "END GAME " << std::endl;
            std::cout << "YOU RAN OUT OF TURNS" << std::endl;       
        }

        
    };

    void manualGame(int numJugadores, int maxTurno) {
        
        int reward = l.getReward();
        int penalty = s.getPenalty();
        
        int turno = 1;
        int numTurno = 0;
        
        std::cout << "GAME" << std::endl;
        std::cout << "________________" << std::endl;
        srand((unsigned)time(0));
        char continuar;

        while(turno < maxTurno) {

            std::cout << "PRESS C TO START" << std::endl;
            
            std::cin >> continuar;

            if(continuar != 'C' and continuar != 'c')  {
                turno = maxTurno;
                std::cout << "END GAME " << std::endl;
                break;
            }

            for(int i=0; i < numJugadores; i++) {
            int dice = 1 + rand() % (6);
            
            imprimeTablero2();

            std::cout << "TURN: " << turno << std::endl;
            std::cout << "PLAYER " << j[i].getNumber() << ": "<< std::endl;
            std::cout << "POSITION: " << j[i].getPosition() << std::endl;
            std::cout << "DICE: " << dice << std::endl;
            std::cout << "MOVES TO: " << j[i].getPosition() + dice << std::endl;
        
            if((j[i].getPosition() + dice) > tamaño) {
                std::cout << "THE PLAYER " << j[i].getNumber() << " WINS THE GAME " << std::endl;
                std::cout << "END GAME " << std::endl;
                numTurno = turno;
                turno = maxTurno;
                break;
                
                
            }

            else {
                if(board[j[i].getPosition() + dice].getType()  == 'N') {
                    std::cout << "NORMAL TILE" << std::endl;
                    std::cout << "THE PLAYER " << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice);
                    
                }

                else if(board[j[i].getPosition() + dice].getType() == 'S') {
                    std::cout << "SNAKE" << std::endl;
                    std::cout << "GO BACK " << penalty << " TILES" << std::endl;
                    std::cout << "THE PLAYER " << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice - penalty << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice - penalty);
                    
                }

                else if(board[j[i].getPosition() + dice].getType() == 'L') {
                    std::cout << "LADDER" << std::endl;
                    std::cout << "ADVANCE " << reward << " TILES" << std::endl;
                    std::cout << "THE PLAYER " << j[i].getNumber() << " IS NOW ON TILE " << j[i].getPosition() + dice + reward << std::endl;
                    j[i].setPosition(j[i].getPosition() + dice + reward);
                    
                };
                };

            
            
           
            
                };

        
         turno = turno +1;
         std::cout << "________________" << std::endl;

        }

        if(numTurno == 0 and continuar != 'c' and continuar != 'C') {
            std::cout << "ENDGAME " << std::endl;
            std::cout << "YOU RAN OUT OF TURNS" << std::endl;       
        }

        
    };
    
};


#endif
#ifndef _TABLERO_
#define _TABLERO_

#include <iostream>
#include <time.h>
class Tablero
{
    // Data members (son privados por default):
    char casillas[30];
    char casillasC[30];

public:
    // Constructor (debe llamarse igual a la clase):
    Tablero()
    {
        // Acciones para inicializar el objeto...
        std::srand(time(NULL));
        int tamaño = sizeof(casillas);
        int escalera1 = rand()%(tamaño-3); // 0-26
        int escalera2 = escalera1;
        while (escalera2 == escalera1)
        {
            escalera2 = rand()%(tamaño-3); // 0-26
        }
        int serpiente1 = escalera1;
        while (serpiente1 == escalera1 || serpiente1 == escalera2 || serpiente1 == escalera1 + 3 || serpiente1 == escalera2 + 3)
        {
            serpiente1 = 4 + rand()%(tamaño-5); // 4-28
        }
        int serpiente2 = escalera1;
        while (serpiente2 == escalera1 || serpiente2 == escalera2 || serpiente2 == serpiente1 || serpiente2 == escalera1 + 3 || serpiente2 == escalera2 + 3)
        {
            serpiente2 = 4 + rand()%(tamaño-5);
        }

        for (int i = 0; i < sizeof(casillas); i++)
        {
            casillas[i] = 'C';
        };

        // Sustituir las casillas de serpiente y escalera:
        casillas[escalera1] = 'E';
        casillas[escalera2] = 'E';

        casillas[serpiente1] = 'S';
        casillas[serpiente2] = 'S';

        //Crear una copia del tablero...
        for (int i = 0; i < sizeof(casillas); i++)
        {
            casillasC[i] = casillas[i];
        }
    };

    // Function member... que sea público:
    // getters & setters de 'casillas[]'
    char getCasilla(int c)
    {
        if (c >= 0 && c < 30)
        {
            return casillas[c];
        }
        else
        {
            std::cout << "Índice inválido!" << std::endl;
            return 'X';
        }
    };

    void setCasilla(char c, int i)
    {
        casillas[i] = c;
    }

    // Imprimir el tablero...
    void imprimeTablero()
    {
        //0 al 10
        for (int i = 0; i < 10; i++)
        {
            std::cout << "[" << i << "]";

        }
        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "[" << casillas[i] << "]";
        }
        std::cout << std::endl;
        //10 al 20
        for (int i = 10; i < 20; i++)
        {
            std::cout << "[" << i << "]";

        }
        std::cout << std::endl;
        for (int i = 10; i < 20; i++)
        {
            std::cout << "[" << casillas[i] << "]";
        }
        std::cout << std::endl;

        //20 al 30
        for (int i = 20; i < 30; i++)
        {
            std::cout << "[" << i << "]";

        }
        std::cout << std::endl;
        for (int i = 10; i < 15; i++)
        {
            std::cout << "[" << casillas[i] << "]";
        }
        std::cout << std::endl<< std::endl;

    };
};
#endif

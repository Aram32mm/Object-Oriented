#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {

    int position;
    int number;
    int numDice;

    public:

    Jugador() {
        position = -1;
        
    }

    int getPosition() {
        return position;
    }

    void setPosition(int pos) {
        position = pos;
    }

    int getNumber() {
        return number;
    }

    void setNumber(int number) {
        this->number = number;
    }

    int getNumDice() {
        return numDice;
    }

    void setNumDice(int numDice) {
        this->numDice = numDice;
    }

};

#endif
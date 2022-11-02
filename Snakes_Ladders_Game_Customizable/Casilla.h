#ifndef CASILLA_H
#define CASILLA_H

class Casilla {

    int numCasilla;
    
    char type;
    public:
    
    void setNumCasilla(int n) {
        numCasilla = n;
    };

    void setType(char type) {
        this->type = type;
    };

    char getType() {
        return type;
    }

   
};

class CasillaNormal : public Casilla {
    public:
        CasillaNormal() {
         setType('N');

        };
 };

class Serpiente : public Casilla {
    int penalty;

    public:

    Serpiente() {
        setType('S');
        penalty = 3;
    };

    void setPenalty(int n) {
        penalty = n;
    };

    int getPenalty() {
        return penalty;
    };

};

class Escalera : public Casilla {
    int reward;

    public:

    Escalera() {
        setType('L');
        reward = 3;
    };

    void setReward(int n) {
        reward = n;
    };

    int getReward() {
        return reward;
    };
};


#endif
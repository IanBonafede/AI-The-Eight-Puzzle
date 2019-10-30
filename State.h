#ifndef STATE_H
#define STATE_H

#include "Enums.h"

class State {
    public:
        State();
        State(Moves move, State &inState);
        void copyVec(vector<vector<int>> &inVec);
        void makeMove(Moves move);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        vector<int> getAvailableMoves(Moves last);
        void calculateManhattanDistance(vector<vector<int>> &base);
        void calculateMisplacedTiles(vector<vector<int>> &base);
        vector<vector<int>> getVec();
        int getX();
        int getY();
        int getManhattanDistance();
        int getMisplacedTiles();
        void printState();


    private:
        vector<vector<int>> vec;
        int x;
        int y;
        int manhattanDistance;
        int misplacedTiles;
};

#endif /* STATE_H */
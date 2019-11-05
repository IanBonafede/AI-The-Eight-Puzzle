#ifndef STATE_H
#define STATE_H

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
class State {
    public:
        enum Moves {NO_MOVE, UP, DOWN, LEFT, RIGHT};
        State(int move, vector<vector<int>> &inVec, int locX, int locY, vector<vector<int>> &inBase);
        void copyVec(vector<vector<int>> &inVec);
        void makeMove();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void setAvailableMoves();
        vector<int> getAvailableMoves();
        void printAvailabeMoves();
        void shuffle(int movesNum);
        int calculateManhattanDistance();
        int calculateMisplacedTiles();
        vector<vector<int>> getVec();
        int getX();
        int getY();
        int getLast();
        void printVec();
        void printLoc();
        void printManhattanDistance();
        void printMisplacedTiles();
        void printLast();


        bool operator == (State& state) const
        {   
            return (vec == state.getVec());
        }


    private:
        vector<vector<int>> vec;
        vector<vector<int>> base;
        vector<int> availableMoves;
        int last;
        int x;
        int y;
};



#endif /* STATE_H */
#ifndef NODE_H
#define NODE_H

#include <map> 
#include <iterator> 
#include <vector>
#include "Moves.h"

using namespace std;

enum Algorithms {UNIFORM_COST_SEARCH, A_STAR_MISPLACED_TILE, A_STAR_MANHATTAN_DISTANCE};

class Node {
    public:
        Node();
        Node(Moves lastMove, vector<vector<int>> &lastState, int locX, int locY, bool saveState);
        void makeMove(vector<vector<int>> &lastState);
        void copyState(vector<vector<int>> &lastState);
        void updateAvailableMoves(bool canMoveBack);
        void updateManhattanDistance();
        void printState();
        int getManhattanDistance();
        
        


    private:
        int x;
        int y;
        int manhattanDistance;
        Moves last;
        map<Moves, Node*> availableMoves;
        bool save;
        vector<vector<int>> *state;
};




#endif /* NODE_H */
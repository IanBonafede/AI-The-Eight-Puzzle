#ifndef NODE_H
#define NODE_H

#include "Enums.h"
#include "State.h"

class Node {
    public:
        Node();
        Node(Moves move, Node &inNode);
        State getState();
        void updateManhattanDistance();
        void updateMisplacedTiles();
        int getManhattanDistance();
        int getMisplacedTiles();
        
        


    private:
        State state;
        int manhattanDistance;
        int misplacedTiles;
};




#endif /* NODE_H */
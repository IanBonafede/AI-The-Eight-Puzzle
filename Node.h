#ifndef NODE_H
#define NODE_H

#include "State.cpp"
#include <algorithm>

class Node {
    public:
        
        enum Moves {NO_MOVE, UP, DOWN, LEFT, RIGHT};
        enum Algorithms {NO_ALG, UNIFORM_COST_SEARCH, A_STAR_MISPLACED_TILES, A_STAR_MANHATTAN_DISTANCE};
        Node(int move, vector<vector<int>> &inVec, int locX, int locY, vector<vector<int>> &inBase, int inDepth);
        State* getState();
        int getDepth();
        int getManhattanDistance();
        int getMisplacedTiles();
        void print(int alg);
        void shuffle(int movesNum);
        bool isEqualTo(Node &node);
        vector<Node> expand(int algo);
        void printDepth();
        void printManhattanDistance();
        void printMisplacedTiles();
        void recalculate();

        bool operator == (Node& node) const
        {   
            return (*state == *(node.getState()));
        }

    private:
        State *state;
        vector<vector<int>> base;
        int manhattanDistance;
        int misplacedTiles;
        int depth;
};


struct more_than_manhattan_distance
{
    inline bool operator() (Node& node1, Node& node2)
    {
        return (node1.getManhattanDistance() > node2.getManhattanDistance());
    }
};

struct more_than_misplaced_tiles
{
    inline bool operator() (Node& node1, Node& node2)
    {
        return (node1.getMisplacedTiles() > node2.getMisplacedTiles());
    }
};




#endif /* NODE_H */
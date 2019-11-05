#include "Node.h"







Node::Node(int move, vector<vector<int>> &inVec, int locX, int locY, vector<vector<int>> &inBase, int inDepth) {
    depth = inDepth;
    base = inBase;
    state = new State(move, inVec, locX, locY, inBase);
    recalculate();
}

void Node::recalculate() {
    manhattanDistance = state->calculateManhattanDistance();
    misplacedTiles = state->calculateMisplacedTiles();
}

State* Node::getState() {
    return state;
}

int Node::getDepth() {
    return depth;
}

int Node::getManhattanDistance() {
    return manhattanDistance;
}

int Node::getMisplacedTiles() {
    return misplacedTiles;
}

void Node::print(int alg) {
    switch(alg) {
        case NO_ALG:
            state->printLoc();
            state->printVec();
            state->printAvailabeMoves();
            break;
        case UNIFORM_COST_SEARCH:
            state->printLoc();
            state->printVec();
            state->printAvailabeMoves();
            break;
        case A_STAR_MISPLACED_TILES:
            state->printLoc();
            state->printVec();
            state->printAvailabeMoves();
            printMisplacedTiles();
            break;
        case A_STAR_MANHATTAN_DISTANCE:
            state->printLoc();
            state->printVec();
            state->printAvailabeMoves();
            printManhattanDistance();
            break;
    }
}

void Node::printDepth() {
    cout << "Depth: " << depth << endl;
}

void Node::printManhattanDistance() {
    cout << "Manhattan Distance: " << manhattanDistance << endl;
}

void Node::printMisplacedTiles() {
    cout << "Misplaced Tiles: " << misplacedTiles << endl;
}

void Node::shuffle(int movesNum) {
    state->shuffle(movesNum);
}


vector<Node> Node::expand(int algo) {
    vector<Node> expansion;
    state->setAvailableMoves();
    vector<int> availableMoves = state->getAvailableMoves();
    vector<vector<int>> vec = state->getVec();
    int x = state->getX();
    int y = state->getY();
    int newDepth = depth + 1;

    for(int i = 0; i < availableMoves.size(); i++) {
        Node tmp(availableMoves[i], vec, x, y, base, newDepth);
        expansion.push_back(tmp);
    }
    switch(algo) {
        case NO_ALG: 
            break;
        case UNIFORM_COST_SEARCH: 
            break;
        case A_STAR_MISPLACED_TILES: 
            sort(expansion.begin(), expansion.end(), more_than_misplaced_tiles());
            break;
        case A_STAR_MANHATTAN_DISTANCE: 
            sort(expansion.begin(), expansion.end(), more_than_manhattan_distance());
            break;
    }
    
    

    return expansion;
}


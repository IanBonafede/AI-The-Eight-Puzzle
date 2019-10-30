#include "State.h"


State::State() {
}

State::State(Moves move, State &inState) {
    x = inState.getX();
    y = inState.getY();
    manhattanDistance = 0;
    misplacedTiles = 0;
    vec = inState.getVec();
    makeMove(move);
}

void State::copyVec(vector<vector<int>> &inVec) {
    vector<vector<int>> tempV( inVec.size() , vector<int> (inVec[0].size()));
    for(int i = 0; i < inVec.size(); i++) {
        for(int j = 0; j < inVec[i].size(); j++) {
            tempV[i][j] = inVec[i][j];
        }
    }
    vec = tempV;
}

void State::makeMove(Moves move) {
    switch(move) {
        case NONE:  break;
        case UP:    moveUp(); break;
        case DOWN:  moveDown(); break;
        case LEFT:  moveLeft(); break;
        case RIGHT: moveRight(); break;
        default: break;
    }
}

void State::moveUp() {
    vec[y][x] = vec[y-1][x];
    vec[y-1][x] = 0;
    y = y - 1;
}

void State::moveDown() {
    vec[y][x] = vec[y+1][x];
    vec[y+1][x] = 0;
    x = x + 1;
}

void State::moveLeft() {
    vec[y][x] = vec[y][x-1];
    vec[y][x-1] = 0;
    x = x - 1;
}

void State::moveRight() {
    vec[y][x] = vec[y][x+1];
    vec[y][x+1] = 0;
    y = x + 1;
}


vector<int> State::getAvailableMoves(Moves last) {
    vector<int> availableMoves;

    if(y != 0 && last != DOWN) { // up available
        availableMoves.push_back(UP); 
    }
    if(y != vec.size() - 1 && last != UP) { // down available
        availableMoves.push_back(DOWN); 
    }
    if(x != 0 && last != RIGHT) { // left available
        availableMoves.push_back(LEFT); 
    }
    if(x != vec[0].size() - 1 && last != LEFT) { // right available
        availableMoves.push_back(RIGHT); 
    }

    return availableMoves;
}

void State::calculateManhattanDistance(vector<vector<int>> &base) {
    int correctVal = 0;
    manhattanDistance = 0;
    int k, l = 0;
    bool found = false;
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) {
            correctVal = base[i][j];
            found = false;
            k = 0;
            while (k < vec.size() && !found) { 
                l = 0;
                while (l < vec[i].size() && !found) {
                    if(correctVal == vec[k][l]) {
                        found = true;
                        l--;
                        k--;
                    }
                    l++;
                }
                k++;
            }
            if(!(i == vec.size() - 1 && j == vec[i].size() - 1) ) {
                manhattanDistance +=  abs(k - i) + abs(l - j);
            }
                
        }
    } 

}

void State::calculateMisplacedTiles(vector<vector<int>> &base) {
    misplacedTiles = 0;
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) {
            if(!(i == vec.size() - 1 && j == vec[i].size() - 1) && vec[i][j] != base[i][j]) {
                misplacedTiles +=  1;
            }
                
        }
    } 

}

vector<vector<int>> State::getVec() {
    return vec;
}
int State::getX() {
    return x;
}
int State::getY() {
    return y;
}
int State::getManhattanDistance() {
    return manhattanDistance;
}
int State::getMisplacedTiles() {
    return misplacedTiles;
}

void State::printState() {
    // Displaying the 2D vector 
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            cout << vec[i][j] << "\t"; 
        cout << endl; 
    } 
}
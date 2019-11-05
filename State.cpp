#include "State.h"

State::State(int move, vector<vector<int>> &inVec, int locX, int locY, vector<vector<int>> &inBase) {
    x = locX;
    y = locY;
    last = move;
    base = inBase;
    copyVec(inVec);
    setAvailableMoves();
    makeMove();
    setAvailableMoves();
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

void State::makeMove() {
    switch(last) {
        case NO_MOVE:  break;
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
    y = y + 1;
}

void State::moveLeft() {
    vec[y][x] = vec[y][x-1];
    vec[y][x-1] = 0;
    x = x - 1;
}

void State::moveRight() {
    vec[y][x] = vec[y][x+1];
    vec[y][x+1] = 0;
    x = x + 1;
}


void State::setAvailableMoves() {
    availableMoves.clear();

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

}

vector<int> State::getAvailableMoves() {
    return availableMoves;
}

void State::printAvailabeMoves() {
    cout << "AVAILABLE MOVES:" << endl;
    for(int i = 0; i < availableMoves.size(); i++) {
        switch(availableMoves[i]) {
            case NO_MOVE: cout << "NO_MOVE" << endl; break;
            case UP: cout << "UP" << endl; break;
            case DOWN: cout << "DOWN" << endl; break;
            case LEFT: cout << "LEFT" << endl; break;
            case RIGHT: cout << "RIGHT" << endl; break;
        }
    }
    cout << endl;
}


void State::shuffle(int movesNum) {
    for(int k = 0; k < movesNum; k++) {
        srand (time(NULL));
        last = availableMoves[rand() % availableMoves.size()];
        makeMove();
        setAvailableMoves();
    }
    last = NO_MOVE;
    setAvailableMoves();

}

int State::calculateManhattanDistance() {
    int correctVal = 0;
    int manhattanDistance = 0;
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
    return manhattanDistance;
}

int State::calculateMisplacedTiles() {
    int misplacedTiles = 0;
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) {
            if(!(i == vec.size() - 1 && j == vec[i].size() - 1) && vec[i][j] != base[i][j]) {
                misplacedTiles +=  1;
            }
                
        }
    } 
    return misplacedTiles;
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

int State::getLast() {
    return last;
}

void State::printVec() {
    cout << "Tiles:\n";
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            if(vec[i][j] == 0)
                cout << "b" << "\t"; 
            else
                cout << vec[i][j] << "\t"; 
        cout << endl; 
    } 
    cout << endl; 
}

void State::printLoc() {
    cout << "Location:\n" << "X: " << x << "\tY: " << y << endl << endl;
}

void State::printLast() {
    switch(last) {
        case NO_MOVE: cout << "NO_MOVE"; break;
        case UP: cout << "UP"; break;
        case DOWN: cout << "DOWN"; break;
        case LEFT: cout << "LEFT"; break;
        case RIGHT: cout << "RIGHT"; break;
    }
}




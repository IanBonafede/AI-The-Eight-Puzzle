#include "Node.h"


Node::Node(Moves lastMove, vector<vector<int>> &lastState, int locX, int locY, bool saveState) {
    save = saveState;
    x = locX;
    y = locY;
    last = lastMove;
    makeMove(lastState);
    updateAvailableMoves(false);
    updateManhattanDistance();
}

void Node::makeMove(vector<vector<int>> &lastState) {
    copyState(lastState);
    
    
    switch(last) {
        case NONE: break;
        case UP: 
            // cout << "up ";
            state[y][x] = state[y-1][x];
            state[y-1][x] = 0;
            y = y - 1;
            break;
        case DOWN: 
            // cout << "down ";
            state[y][x] = state[y+1][x];
            curr[y+1][x] = 0;
            x = x + 1;
            break;
        case LEFT: 
            // cout << "left ";
            state[y][x] = state[y][x-1];
            state[y][x-1] = 0;
            x = x - 1;
            break;
        case RIGHT: 
            // cout << "right ";
            state[y][x] = state[y][x+1];
            state[y][x+1] = 0;
            y = x + 1;
            break;
        default: break;
    }
}

void Node::copyState(vector<vector<int>> &lastState) {
    if(save) {
        vector<vector<int>> tempV( lastState.size() , vector<int> (lastState[0].size()));
        for(int i = 0; i < lastState.size(); i++) {
            for(int j = 0; j < lastState[i].size(); j++) {
                tempV[i][j] = lastState[i][j];
            }
        }
        state = tempV;
    }
    else {
        state = lastState;
    }
    
}

void Node::updateAvailableMoves(bool canMoveBack) {
    if(canMoveBack) {
        if(y != 0) { // up available
            availableMoves.insert(pair<Moves, Node*>(UP, NULL)); 
        }
        if(y != curr.size() - 1) { // down available
            availableMoves.insert(pair<Moves, Node*>(DOWN, NULL)); 
        }
        if(x != 0) { // left available
            availableMoves.insert(pair<Moves, Node*>(LEFT, NULL)); 
        }
        if(x != curr[0].size() - 1) { // right available
            availableMoves.insert(pair<Moves, Node*>(RIGHT, NULL)); 
        }
    }
    if(!canMoveBack) {
        if(y != 0 && last != DOWN) { // up available
            availableMoves.insert(pair<Moves, Node*>(UP, NULL)); 
        }
        if(y != curr.size() - 1 && last != UP) { // down available
            availableMoves.insert(pair<Moves, Node*>(DOWN, NULL)); 
        }
        if(x != 0 && last != RIGHT) { // left available
            availableMoves.insert(pair<Moves, Node*>(LEFT, NULL)); 
        }
        if(x != curr[0].size() - 1 && last != LEFT) { // right available
            availableMoves.insert(pair<Moves, Node*>(RIGHT, NULL)); 
        }
    }
}

void Node::updateManhattanDistance() {
    int correctVal = 0;
    int score = 0;
    int k, l = 0;
    bool found = false;
    for (int i = 0; i < curr.size(); i++) { 
        for (int j = 0; j < curr[i].size(); j++) {
            correctVal = base[i][j];
            found = false;
            k = 0;
            while (k < curr.size() && !found) { 
                l = 0;
                while (l < curr[i].size() && !found) {
                    if(correctVal == curr[k][l]) {
                        found = true;
                        l--;
                        k--;
                    }
                    l++;
                }
                k++;
            }
            if(!(i == curr.size() - 1 && j == curr[i].size() - 1) ) {
                score +=  abs(k - i) + abs(l - j);
                //cout << score + " ";
            }
                
        }
    } 


    manhattanDistance = score;
}

int Node::getManhattanDistance() {
    return manhattanDistance;
}


void Node::printState() {
    // Displaying the 2D vector 
    cout << "\n";
    for (int i = 0; i < state.size(); i++) { 
        for (int j = 0; j < state[i].size(); j++) 
            cout << state[i][j] << "\t"; 
        cout << endl; 
    } 
}
#include "main.h"

int main() {

    cout << "Welcome to Ian Bonafede's 8-Puzzle solver.\n" << 
            "By default, the problem is set to a solved 3x3 puzzle.\n";
    int ret = 0;
    int input;

    while(ret == 0) {

        printOptions();

        cin >> input;
        switch (input) {
            case 0:     ret = exitProgram(); break;
            case 1:     ret = printBase(); break;
            case 2:     ret = printCurr(); break;
            case 3:     ret = shuffle(); break;
            case 4:     ret = evaluateManhattanDistance(); break;
            case 5:     ret = inputPuzzleSize(); break;
            case 6:     ret = inputPuzzleVals(); break;
            default:    ret = exitProgram(); break;
        }
    }
  
    return 0; 
}



int printOptions() {
    for(int i = 0; i < options.size(); i++) {
        cout << options[i];
    }
    return 0;
}

int exitProgram() {
    return 1;
}

int printBase() {
    // Displaying the 2D vector 
    cout << "\n";
    for (int i = 0; i < base.size(); i++) { 
        for (int j = 0; j < base[i].size(); j++) 
            cout << base[i][j] << "\t"; 
        cout << endl; 
    } 
    return 0;
}

int printCurr() {
    // Displaying the 2D vector 
    cout << "\n";
    for (int i = 0; i < curr.size(); i++) { 
        for (int j = 0; j < curr[i].size(); j++) 
            cout << curr[i][j] << "\t"; 
        cout << endl; 
    } 
    return 0;
}

int shuffle() {
    int movesNum = 0;

    cout << "\nPlease enter number of moves.\n\n" << "$ ";
    cin >> movesNum;

    bool found = false;
    int i = 0;
    int j = 0;
    while ( i < curr.size() && !found) { 
        j = 0;
        while (j < curr[i].size() && !found) {
            if(curr[i][j] == 0) {
                found = true;
                i--;
                j--;
            }
            j++;
        }
        i++;
        
    } 
    Moves lastMove = NONE;
    Moves tempMove = NONE;
    for(int k = 0; k < movesNum; k++) {
        lastMove = tempMove;
        Moves availableMoves = getAvailableMoves(i, j, false, lastMove);
        tempMove = pickRandomMove();
        makeMove(tempMove, i, j);
    }

    return 0;
}

Moves getAvailableMoves(int i, int j, bool canMoveBack, Moves lastMove){
    availableMoves = {};
    if(canMoveBack) {
        if(i != 0) { // up available
            availableMoves.push_back(UP);
        }
        if(i != curr.size() - 1) { // down available
            availableMoves.push_back(DOWN);
        }
        if(j != 0) { // left available
            availableMoves.push_back(LEFT);
        }
        if(j != curr[0].size() - 1) { // right available
            availableMoves.push_back(RIGHT);
        }
    }
    if(!canMoveBack) {
        if(i != 0 && lastMove != DOWN) { // up available
            availableMoves.push_back(UP);
        }
        if(i != curr.size() - 1 && lastMove != UP) { // down available
            availableMoves.push_back(DOWN);
        }
        if(j != 0 && lastMove != RIGHT) { // left available
            availableMoves.push_back(LEFT);
        }
        if(j != curr[0].size() - 1 && lastMove != LEFT) { // right available
            availableMoves.push_back(RIGHT);
        }
    }
}

Moves pickRandomMove() { // will not go backwards
    srand (time(NULL));
    Moves move = availableMoves[rand() % availableMoves.size()];
    return move;
}



int evaluateManhattanDistance() {
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

    cout << "\nScore: " << score << "\n";

    return 0;
}



int makeMove(Moves move, int &i, int &j) {
    int tempNum = 0;
    switch(move) {
        case UP: 
            // cout << "up ";
            curr[i][j] = curr[i-1][j];
            curr[i-1][j] = 0;
            i = i - 1;
            break;
        case DOWN: 
            // cout << "down ";
            curr[i][j] = curr[i+1][j];
            curr[i+1][j] = 0;
            i = i + 1;
            break;
        case LEFT: 
            // cout << "left ";
            curr[i][j] = curr[i][j-1];
            curr[i][j-1] = 0;
            j = j - 1;
            break;
        case RIGHT: 
            // cout << "right ";
            curr[i][j] = curr[i][j+1];
            curr[i][j+1] = 0;
            j = j + 1;
            break;
    }
    return 0;
}



int inputPuzzleSize() {
    int rows = 0;
    int cols = 0;

    cout << "\nRows?\n\n" << "$ ";
    cin >> rows;

    cout << "\nColumns?\n\n" << "$ ";
    cin >> cols;

    vector<vector<int> > vec1( rows , vector<int> (cols));  
    vector<vector<int> > vec2( rows , vector<int> (cols));  

    base.clear();
    curr.clear();

    base = vec1;
    curr = vec2;

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(i == rows - 1 && j == cols - 1) {
                base[i][j] = 0;
                curr[i][j] = 0;
            }
            else {
                base[i][j] = i*cols + j + 1;
                curr[i][j] = i*cols + j + 1;
            }
        }
    }

    return 0;
}

int inputPuzzleVals() {
    cout << "Please input each value seperately.\n";
    for(int i = 0; i < curr.size(); i++) {
        cout << "Row " << i + 1 << "\n";
        for (int j = 0; j < curr[i].size(); j++) {
                cin >> curr[i][j];
        }
    }

    return 0;
}
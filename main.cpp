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
            case 2:     ret = printRoot(); break;
            case 3:     ret = evaluateManhattanDistanceOfRoot(); break;
            case 4:     ret = evaluateMisplacedTilesOfRoot(); break;
            case 5:     ret = inputPuzzleSize(); break;
            case 6:     ret = inputPuzzleVals(); break;
            case 7:     ret = shuffleRoot(); break;
            case 8:     ret = solveRoot(UNIFORM_COST_SEARCH); break;
            case 9:     ret = solveRoot(A_STAR_MISPLACED_TILES); break;
            case 10:    ret = solveRoot(A_STAR_MANHATTAN_DISTANCE); break;
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
    base->print(NO_ALG);
    return 0;
}

int printRoot() {
    // Displaying the 2D vector 
    root->print(NO_ALG);
    return 0;
}

int evaluateManhattanDistanceOfRoot() {
    root->print(A_STAR_MANHATTAN_DISTANCE);
    return 0;
}

int evaluateMisplacedTilesOfRoot() {
    root->print(A_STAR_MISPLACED_TILES);
    return 0;
}

int shuffleRoot() {
    int movesNum = 0;

    cout << "\nPlease enter number of moves.\n\n" << "$ ";
    cin >> movesNum;

    root->shuffle(movesNum);
    root->recalculate();

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

    baseVec.clear();

    baseVec = vec1;

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(i == rows - 1 && j == cols - 1) {
                baseVec[i][j] = 0;
            }
            else {
                baseVec[i][j] = i*cols + j + 1;
            }
        }
    }
    x = rows -1;
    y = cols - 1;


    delete base;
    delete root;
    delete ps;

    base = new Node(NO_MOVE, baseVec, x, y, baseVec, 0);

    root = new Node(NO_MOVE, baseVec, x, y, baseVec, 0);

    ps = new ProblemSolver(*root, *base);

    return 0;
}

int inputPuzzleVals() {
    vector<vector<int> > tempV( baseVec.size() , vector<int> (baseVec[0].size()));

    cout << "Please input each value seperately.\n";
    cout << tempV[0].size() << " values per row.\n";
    for(int i = 0; i < tempV.size(); i++) {
        cout << "Row " << i + 1 << "\n";
        for (int j = 0; j < tempV[i].size(); j++) {
                cin >> tempV[i][j];
                if(tempV[i][j] == 0) {
                    x = j;
                    y = j;
                }
        }
    }

    delete base;
    delete root;
    delete ps;

    base = new Node(NO_MOVE, baseVec, x, y, baseVec, 0);

    root = new Node(NO_MOVE, tempV, x, y, baseVec, 0);

    ps = new ProblemSolver(*root, *base);

    return 0;
}

int isRootEqualAnswer() {
    if(*root == *base)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    
    return 0;
}

int solveRoot(int function) {
    bool found = ps->genericSearch(function);
    ps->startWith(*root);
    return 0;
}


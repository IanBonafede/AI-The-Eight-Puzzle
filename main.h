#ifndef MAIN_H
#define MAIN_H

#include "ProblemSolver.cpp"
    

enum Moves {NO_MOVE, UP, DOWN, LEFT, RIGHT};
enum Algorithms {NO_ALG, UNIFORM_COST_SEARCH, A_STAR_MISPLACED_TILES, A_STAR_MANHATTAN_DISTANCE};


// Initializing 2D vector 
vector<vector<int>> baseVec {   { 1, 2, 3 }, 
                                { 4, 5, 6 }, 
                                { 7, 8, 0 } }; 


int x = 2;
int y = 2;

Node *base = new Node(NO_MOVE, baseVec, x, y, baseVec, 0);

Node *root = new Node(NO_MOVE, baseVec, x, y, baseVec, 0);

ProblemSolver *ps = new ProblemSolver(*root, *base);

vector<string> options    { "\nPlease enter a number for a command.\n",
                            "0: (or any other input) exit the program.\n",
                            "1: print the answer to the root node.\n",
                            "2: print the root node.\n",
                            "3: evaluate the manhattan distance of the root node.\n",
                            "4: evaluate the misplaced tiles of the root node.\n",
                            "5: input your own puzzle size.\n",
                            "6: input your own puzzle values.\n",
                            "7: shuffle the root node.\n",
                            "8: solve root using uniform cost search.\n",
                            "9: solve root using A* with misplaced tiles.\n",
                            "10: solve root using A* with manhattan distance.\n",
                            "\n",
                            "$ "};

int solveRoot(int function);
int printOptions();
int exitProgram(); 
int printBase();
int printRoot();
int evaluateManhattanDistanceOfRoot();
int evaluateMisplacedTilesOfRoot();
int inputPuzzleSize();
int inputPuzzleVals();
int shuffleRoot();
int isRootEqualAnswer();
int solve_UNIFORM_COST_SEARCH();
int solve_A_STAR_MISPLACED_TILES();
int solve_A_STAR_MANHATTAN_DISTANCE();



#endif /* MAIN_H */
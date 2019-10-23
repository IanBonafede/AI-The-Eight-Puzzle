#ifndef MAIN_H
#define MAIN_H

#include <iostream> 
#include <vector> // for 2D vector 
#include "Node.h"
#include "Moves.h"
    
using namespace std;




// Initializing 2D vector 
vector<vector<int>> base  { { 1, 2, 3 }, 
                            { 4, 5, 6 }, 
                            { 7, 8, 0 } }; 

vector<vector<int>> curr  { { 1, 2, 3 }, 
                            { 4, 5, 6 }, 
                            { 7, 8, 0 } }; 

vector<string> options    { "\nPlease enter a number for a command.\n",
                            "0: (or any other input) exit the program.\n",
                            "1: print the answer to the current state.\n",
                            "2: print the current state.\n",
                            "3: shuffle the current state.\n",
                            "4: evaluate the manhattan distance of the current state.\n",
                            "5: input your own puzzle size.\n",
                            "6: input your own puzzle values.\n",
                            "\n",
                            "$ "};


vector<Moves> availableMoves = {UP, DOWN, LEFT, RIGHT};

int printOptions();
int exitProgram(); 
int printBase();
int printCurr();
int shuffle();
int evaluateManhattanDistance();
int inputPuzzleSize();
int inputPuzzleVals();
int 

Moves getAvailableMoves(int i, int j, bool canMoveBack, Moves lastMove);
Moves pickRandomMove();
int makeMove(Moves move, int &i, int &j);




#endif /* MAIN_H */
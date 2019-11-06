#ifndef PROBLEMSOLVER_H
#define PROBLEMSOLVER_H

#include "Node.cpp"
#include <stack>

using namespace std;
class ProblemSolver {
    public:
        enum Moves {NO_MOVE, UP, DOWN, LEFT, RIGHT};
        enum Algorithms {NO_ALG, UNIFORM_COST_SEARCH, A_STAR_MISPLACED_TILES, A_STAR_MANHATTAN_DISTANCE};
        ProblemSolver(Node &root, Node &inBase);
        bool genericSearch(int alg);
        bool didVisitNode(Node &node);
        void printStats();
        void startWith(Node &root);



    private:
        stack<Node> s;
        vector<Node> visitedNodes;
        Node *base;
        int maxQueueSize;
        int nodesExpanded;
        clock_t t;
};

#endif /* PROBLEMSOLVER_H */
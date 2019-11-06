#include "ProblemSolver.h"


ProblemSolver::ProblemSolver(Node &root, Node &inBase) {
    base = &inBase;
    s.push(root);
    visitedNodes.push_back(root);
}

bool ProblemSolver::genericSearch(int alg) {

    maxQueueSize = 0;
    nodesExpanded = 0;
    int siz = 0;
    bool foundOne = false;
    int bestDepth = -1;
    int f;
    t = clock();

    

    while(!s.empty()) {
        siz = s.size();

        if(siz > maxQueueSize)
            maxQueueSize = siz;

        Node node = s.top();
        s.pop();



        cout << "Expanding node ";
        node.getState()->printLast();
        cout << " at ";
        node.printDepth();
        cout << endl;
        node.print(alg);




        if(node == *base) {
            cout << "PATH FOUND!" << endl;
            t = clock() - t;
            printStats();
            return true; 
        }


        vector<Node> expansion = node.expand(alg);
        nodesExpanded++;



        for(int i = 0; i < expansion.size(); i++) {
            // cout << "-";
            // expansion[i].getState()->printLast();
            // cout << "-" << endl;
            // expansion[i].print(alg);
            // cout << endl;
            if(!didVisitNode(expansion[i])) {
                s.push(expansion[i]);
                visitedNodes.push_back(expansion[i]);
            }
        }
    }


    t = clock() - t;
    printStats();
    return foundOne;

}

bool ProblemSolver::didVisitNode(Node &node) {
    bool visited = false;

    int i = visitedNodes.size() - 1;
    while(i >= 0 && visited == false) {
        if(node == visitedNodes[i])
            visited = true;
        i--;
    }
    return visited;
}

void ProblemSolver::printStats() {
    printf ("Time(seconds): %f\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Max queue size: %d\n", maxQueueSize);
    printf("Nodes expanded: %d\n", nodesExpanded);
}

void ProblemSolver::startWith(Node &root) {
    while(!s.empty())
        s.pop();
    s.push(root);
}
#include "Node.h"

Node::Node() {

}

Node::Node(Moves move, Node &inNode) {
    state = new State(move, inNode.getState());
}

State Node::getState() {
    return state;
}
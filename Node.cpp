#include "Node.h"

Node::Node(int d) : data(d), link(nullptr) {}

int Node::getData() {
    return data;
}

void Node::setData(int d) {
    data = d;
}

Node* Node::getLink() {
    return link;
}

void Node::setLink(Node* n) {
    link = n;
}

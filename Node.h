#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    Node(int d);
    int getData();
    void setData(int d);
    Node* getLink();
    void setLink(Node* n);
};

#endif

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* temp = cur;
        cur = cur->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    if (pos <= 1 || !head) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node* cur = head;
    int index = 1;

    while (cur->getLink() && index < pos - 1) {
        cur = cur->getLink();
        index++;
    }

    newNode->setLink(cur->getLink());
    cur->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (!head || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node* cur = head;
    int index = 1;
    while (cur->getLink() && index < pos - 1) {
        cur = cur->getLink();
        index++;
    }

    if (!cur->getLink()) return false;

    Node* toDelete = cur->getLink();
    cur->setLink(toDelete->getLink());
    delete toDelete;
    return true;
}

int LinkedList::get(int pos) {
    if (!head || pos < 1) return std::numeric_limits<int>::max();

    Node* cur = head;
    int index = 1;
    while (cur && index < pos) {
        cur = cur->getLink();
        index++;
    }

    if (!cur) return std::numeric_limits<int>::max();
    return cur->getData();
}

int LinkedList::search(int target) {
    Node* cur = head;
    int index = 1;
    while (cur) {
        if (cur->getData() == target) return index;
        cur = cur->getLink();
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    if (!head) return;

    std::cout << "[";
    Node* cur = head;
    while (cur) {
        std::cout << cur->getData();
        cur = cur->getLink();
        if (cur) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

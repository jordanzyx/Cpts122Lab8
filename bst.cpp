//
// Created by Jordan Muehlbauer on 3/12/20.
//

#include "bst.h"
#include <string.h>
#include <fstream>

void Node::destroy() {
    if(left != NULL)left->destroy();
    if(right != NULL)right->destroy();

    delete left;
    delete right;
}

bool Node::isGreaterThan(string item) {
    return data.compare(item) > 0;
}

void Node::insertOn(Node *newNode) {

    bool greaterThan = isGreaterThan(newNode->data);

    if(!greaterThan){
        if(right == NULL){right = newNode;return;}

        right->insertOn(newNode);
        return;
    }

    if(left == NULL){left = newNode;return;}
    left->insertOn(newNode);
}

void Node::print() {
    cout << data;
}

void Node::printInOrder() {
    if(left != NULL)left->printInOrder();
    print();
    if(right != NULL)right->printInOrder();
}

void Node::printPreOrder() {
    print();
    if(left != NULL)left->printPreOrder();
    if(right != NULL)right->printPreOrder();
}

void Node::printPostOrder() {
    if(left != NULL)left->printPostOrder();
    if(right != NULL)right->printPostOrder();
    print();
}

void Node::printFileInOrder(ofstream *stream) {
    if(left != NULL)left->printFileInOrder(stream);
    printFile(stream);
    if(right != NULL)right->printFileInOrder(stream);
}

void Node::printFile(ofstream *file) {
    *file << data << endl;
}

void BSTTree::insertNode(string data) {
    Node *newNode = new Node(data);

    if(isEmpty()){
        head = newNode;
        return;
    }

    head->insertOn(newNode);
}

bool BSTTree::isEmpty() {
    return head == NULL;
}

void BSTTree::inOrderTraversal() {
    head->printInOrder();
    cout << endl;
}



void BSTTree::preOrderTraversal() {
    head->printPreOrder();
    cout << endl;
}

void BSTTree::postOrderTraversal() {
    head->printPostOrder();
    cout << endl;
}

void BSTTree::destroyTree() {
    //Destroy the nodes
    head->destroy();

    //Get rid of the head
    delete &head;

    //Set the HEAD TO NULL
    head = NULL;
}

void BSTTree::inOrderToFile() {
    ofstream file("names.txt");
    head->printFileInOrder(&file);
}

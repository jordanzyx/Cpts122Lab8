//
// Created by Jordan Muehlbauer on 3/12/20.
//

#ifndef LAB8_BST_H
#define LAB8_BST_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
private:
    string data;
    Node *left;
    Node *right;
public:
    Node(string item){
        data = item;
        left = NULL;
        right = NULL;
    }
    void destroy();
    bool isGreaterThan(string item);
    void insertOn(Node *newNode);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    void printFileInOrder(ofstream *stream);
    void printFile(ofstream *file);
    void print();
};
class BSTTree {
private:
    Node *head;
public:
    void insertNode(string data);
    bool isEmpty();
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void destroyTree();
    void inOrderToFile();
    BSTTree(){
        head = NULL;
    }

};



#endif //LAB8_BST_H

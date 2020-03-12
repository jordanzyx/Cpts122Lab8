#include <iostream>
#include "fstream"
#include "bst.h"
using namespace std;

int main() {
    string data = "m";
    string item = "a";

    cout << data.compare(item) << endl;


    BSTTree *tree = new BSTTree();

    tree->insertNode("m");
    tree->insertNode("a");
    tree->insertNode("b");
    tree->insertNode("z");

    tree->inOrderTraversal();
    tree->preOrderTraversal();
    tree->postOrderTraversal();

    ifstream file("names.txt");

    BSTTree *names = new BSTTree();
    string name;
    while(getline(file,name)){
        names->insertNode(name);
    }

    names->inOrderToFile();
    names->destroyTree();



    return 0;
}

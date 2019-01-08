#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "node.h"

/*definition of the tree class*/
class BuildTree {
    Node *root;
    BuildTree() {
    root = NULL; }

    void addNode(Node *&, Node *&);
    void NewNodetoTree(char, std::string, int);
    int searchTree(char, Node *, std::string);
};

/*function that reads in the new node value*/
void BuildTree::NewNodetoTree(char ch, std::string str, int index) {
    Node *newNode = NULL;

    /*a new node is created*/
    newNode = new Node;
    newNode->value = ch;
    newNode->left = newNode->right = NULL;
    newNode->middle.push_back(str);
    newNode->lvl = index;

    /*the new node is sent to be added to the tree*/
    addNode(root, newNode);
}

/*function to insert node*/
void BuildTree::addNode(Node *&nodePtr, Node *&newNode) {

  /*If the node is empty, the new node will be added as the prim.
     Else, the node will be added to the tree*/
  if(nodePtr == NULL) {
     nodePtr = newNode;
  } else if (newNode->value < nodePtr->value) {
     addNode(nodePtr->left, newNode);
  } else {
     addNode(nodePtr->right, newNode);
  }
}

/*function to search tree for existing values*/
int BuildTree::searchTree(char x, Node *root, std::string word) {

    Node *node = root;

    int placeholder = 0;

  /*check if the node is already present in the tree.
    If it is ? the value will be added on.
    If not ? the new value will be incorporated into the tree.*/
    while(node) {
        if(nodePtr->value == x) {
	   nodePtr->middle.push_back(word);
	   return 1;
	} else if (ch < nodePtr->value) {
           nodePtr = nodePtr->left;
	   index++;
	} else {
   	   nodePtr = nodePtr->right;
	   index++;
	}
    }

    /*Sending new node to be added to tree*/
    NewNodetoTree(x, word, index);
    return 0;
}

#endif


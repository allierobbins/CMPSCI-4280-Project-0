#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <string.h>
#include <stdio.h>
#include "node.h"

/*Inorder traversal*/
void traversalInorder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		traversalInorder(nodePtr->left, fileName);
		print(nodePtr, fileName);
		traversalInorder(nodePtr->right, fileName);
	}
}

/*Preorder traversal*/
void traversalPreorder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		print(nodePtr, fileName);
		traversalPreorder(nodePtr->left, fileName);
		traversalPreorder(nodePtr->right, fileName);
	}
}

/*Postorder traversal*/
void traversalPostorder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		traversalPostorder(nodePtr->left, fileName);
		traversalPostorder(nodePtr->right, fileName);
		print(nodePtr, fileName);
	}
}

#endif


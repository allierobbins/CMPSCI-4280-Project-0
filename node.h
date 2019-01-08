#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <string.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
	vector<string> midNode;
	int lvl;
};

#endif

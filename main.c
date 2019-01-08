/****************************************
 * * 4280 - Project 0                      *
 * * Allie Robbins                         *
 * * Due September 27, 2018                *
 * ****************************************/

#include "node.h"
#include "traversals.h"
#include "buildTree.h"

/*main program*/
int main(int argc, char* argv[]) {

  /*variables used*/
  string data, name;

  /*assign names for output files*/
  string inOrderFile = "inorder";
  string preOrderFile = "preorder";
  string postOrderFile = "postorder";

  /*Create the tree*/
  BuildTree tree;

  /*Check if a file was provided*/
  if (isatty(STDIN_FILENO)) {

	/*If no file was given - request from user*/
	if(argc == 1) {
	     printf("No input file was given - please enter data manually.\n >> ");
	     getline(cin, data);

            /*Save input data to a file*/
	    FILE * screenData;
            screenData = fopen("userData.txt", w);
	    screenData << data;
            fclose(screenData);

            /*reopen file to read from it*/
	    FILE * dataFile;
	    dataFile = fopen("userData.txt", r);

            /*send data to be added to the tree*/
	    while(dataFile >> line) {
	    	int LENGTH = line.size();
	 	char lineList[LENGTH];
		strcpy(lineList, line.c_str());

		int result = tree->searchTree(lineList[0], tree->root, line);
	    }

	    /*Traverse tree in 3 styles*/
	    traversalInorder(tree->root, "out.inorder");
            traversalPreorder(tree->root, "out.preorder");
	    traversalPostorder(tree->root, "out.postorder");

	/*When a filename is given*/
	} else if(argc == 2) {

	    /*Open file*/
	    ifstream screenData;
	    screenData.open(argv[1]);

	    /*read in the data from the file and create nodes*/
	    if(screenData.good()) {
       	    string line;
	    while(screenData >> line) {
		int LENGTH = line.size();
		char lineList[LENGTH];
		strcpy(lineList, line.c_str());

		int result = tree->searchTree(lineList[0], tree->root, line);
	    }

	    /*Traverse the tree in 3 styles*/
            traversalInorder(tree->root, inOrderFile);
            traversalPreorder(tree->root, preOrderFile);
            traversalPostorder(tree->root, postOrderFile);
	

	    /*File open error*/
	} else {
	   printf("\nERROR: File could not be opened.\n");
  	}

	}

	return 0;
}


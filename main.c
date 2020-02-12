#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"
#include "tree.h"

FILE *fp;
FILE *ino;
FILE *pre;
FILE *post;
char *file;
char *basename;

int fileno(FILE *stream);

int main(int argc, char *argv[]){
	

	if(argc == 1){

		/*check if stdin is empty,if not, set stdin to file pointer*/
			
		if(isatty(fileno(stdin))==0){
			
			stdinFp(stdin);

			fp = stdin;

			basename = stdinBasename();
			
			
		}else{

			/*abort system if it is a single input*/

			printf("please enter a file, redirection or multiple words\n");
			return -1;

		}

	}

	else if(argc == 2){
	
		/*check to see if a file or single node has been entered, if file check if file is empty*/

		if(strstr(argv[1], ".")){

			returnFp(argv[1]);

			fp = fopen(argv[1], "r");

			basename = fileBasename(argv[1]);

		}else{

			/*create temp file, and write node into temp file, return temp file name.*/

			file = handleSingleNode(argv[1]);

			fp = fopen(file, "r");

			basename = "output";

		}
	}else{

		/*write to temp file and return temp file, create file output files*/

		basename = "output";

		file = handleNodeString(argc, argv);

		fp = fopen(file, "r");

	}


	if(fp == NULL)
	{
		printf("issue opening file!\n");
	}

	struct node *root = buildTree(fp);
	printPreorder(root, 0);
	printInorder(root, 0);
	printPostorder(root, 0);

	fclose(ino);
	fclose(pre);
	fclose(post);
	fclose(fp);

	
	return 0;

}

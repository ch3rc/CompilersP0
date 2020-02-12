#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

char *baseFile;
char *tempFile;

/*if stdinput return basename output*/
char *stdinBasename(){

	baseFile = "output";

	printf("filename: %s\n", baseFile); 

	return baseFile;
}


/*check to see if redirected file is empty, if file not empty rewind file so additional stream is not output*/
void stdinFp(FILE *stream){

	if((fseek(stdin, 0, SEEK_END), ftell(stdin))> 0){
		
		rewind(stdin);
	}
	else 
	{
		printf("file empty\n");
		exit(1);
	}

}


/*find first position of a period in filename entered and return basename of file*/
char *fileBasename(char *argv){
	
	char *base = malloc(sizeof(argv) + 1);

	char find = '.';

	char *firstPos = strchr(argv, find);

	int position = firstPos - argv;

	strncpy(base, argv, position);

	return base;
		
}


/*check to see if file exists, if file exists check to see if it is empty, else return file pointer*/
void returnFp(char *argv){
	
	FILE *stream;

	stream = fopen(argv, "r");

	if(stream == NULL){

		fprintf(stderr, "Problem opening file, please check spelling of file\n");
		exit(EXIT_FAILURE);

	}


	if(fseek(stream, 0,SEEK_END), ftell(stream) == 0){

		fprintf(stderr, "File is empty!\n");
		exit(EXIT_FAILURE);
	}

}


/*open temp file and write single node to temp file, return temp file name*/
char *handleSingleNode(char *argv){
	
	FILE *fp;

	tempFile = "test.txt";

	fp = fopen(tempFile, "w");

	if(fp != NULL){
		fprintf(fp, "%s", argv);
	}else{
		fprintf(stderr, "Problem occurred when writing to %s\n", tempFile);
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);

	return tempFile;
}

/*write string of nodes to temp file*/
char *handleNodeString(int argc, char *argv[]){
	
	FILE *fp;

	tempFile = "test.txt";

	fp = fopen(tempFile, "w");

	if(fp != NULL){
		
		int i;
		for(i = 1; i < argc; i++){

			fprintf(fp, "%s ", argv[i]);
		}

	}else{

		fprintf(stderr, "Problem occurred when writing to %s\n", tempFile);
		exit(EXIT_FAILURE);
	}

	fclose(fp);

	return tempFile;

}

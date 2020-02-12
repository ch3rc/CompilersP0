#ifndef NODE_H
#define NODE_H

extern FILE *fp;
extern char *file;
extern char *basename;

struct node{

	char *letters;
	char *strng;
	struct node *left, *right;
};

#endif



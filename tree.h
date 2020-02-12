#include "node.h"
#ifndef TREE_H
#define TREE_H

extern char *inorder;
extern char *preorder;
extern char *postorder;
extern FILE *ino;
extern FILE *pre;
extern FILE *post;

struct node *buildTree(FILE *stream);

struct node *insert(struct node *root, char *word);

void printInorder(struct node *root, int level);

void printPreorder(struct node *root, int level);

void printPostorder(struct node *root, int level);

struct node *newNode(char *let, char *word);

#endif

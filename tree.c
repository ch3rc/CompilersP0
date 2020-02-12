#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

FILE *ino;
FILE *pre;
FILE *post;
char *inorder;
char *preorder;
char *postorder;
char *basename;
char *inExt = ".inorder";
char *preExt = ".preorder";
char *poExt = ".postorder";


/*newNode excepts both letter and word*/
struct node *newNode(char *let, char *word)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->letters = let;
	temp->strng = word;
	temp->left = temp->right = NULL;
	return temp;
}

/*create temp to use as a way to compare letters in node
 * if node letters match temp compare node word with node 
 * string, it it does not exist add to string*/
struct node *insert(struct node *root, char *word)
{
	char *temp = malloc(sizeof(word) + 1);
	strncpy(temp, word, 2);

	if(root == NULL)
	{
		return newNode(temp, word);
	}
	else if(strcmp(root->letters, temp) > 0)
	{
		root->left = insert(root->left, word);
	}
	else if(strcmp(root->letters, temp) < 0)
	{
		root->right = insert(root->right, word);
	}
	else if(strcmp(root->letters, temp) == 0)
	{
		if(!strstr(root->strng, word))
		{
			strcat(root->strng, " ");
			strcat(root->strng, word);
		}
	}

	return root;
}

void printPreorder(struct node *root, int level)
{
	if(pre != NULL)
	{
		if(root != NULL)
		{
			fprintf(pre,"%*s%s: %s\n", level*2,"",root->letters,root->strng);
			printPreorder(root->left, level + 1);
			printPreorder(root->right, level + 1);
		}
	}
}

void printInorder(struct node *root, int level)
{	
	if(ino != NULL)
	{
		if(root != NULL)
		{
			printInorder(root->left, level + 1);
			fprintf(ino,"%*s%s: %s\n",level*2,"",root->letters,root->strng);
			printInorder(root->right, level + 1);
		}
	}
}

void printPostorder(struct node *root, int level)
{
	if(post != NULL)
	{
		if(root != NULL)
		{
			printPostorder(root->left, level + 1);
			printPostorder(root->right, level + 1);
			fprintf(post,"%*s%s: %s\n",level*2,"",root->letters,root->strng);
		}
	}
}


struct node *buildTree(FILE *stream)
{
	char buf[1024];
	char *array[50];
	struct node *root = NULL;
	int count = 0;
	int i;

	while(fscanf(stream, "%s", buf) != EOF)
	{
		array[count] = malloc(sizeof(buf) + 1);
		strcpy(array[count], buf);
		count++;
		if(count == 50)
		{
			break;
		}
	}

	root = insert(root, array[0]);
	for(i = 1; i < count; i++)
	{
		insert(root, array[i]);
	}
	
	inorder = malloc(sizeof(basename) + sizeof(inExt) + 1);
	preorder = malloc(sizeof(basename) + sizeof(preExt) + 1);
	postorder = malloc(sizeof(basename) + sizeof(poExt) + 1);

	strcpy(inorder,basename);
	strcat(inorder, inExt);
	strcpy(preorder, basename);
	strcat(preorder, preExt);
	strcpy(postorder, basename);
	strcat(postorder, poExt);

	printf("%s ,%s ,%s\n", inorder, preorder, postorder);

	ino = fopen(inorder, "a");
	pre = fopen(preorder, "a");
	post = fopen(postorder, "a");


	return root;
}
























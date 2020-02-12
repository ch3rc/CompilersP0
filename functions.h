#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern char *basename;

extern char *tempFile;

char *stdinBasename();

void stdinFp(FILE *stream);

char *fileBasename(char *argv);

void returnFp(char *argv); 

char *handleSingleNode(char *argv);

char *handleNodeString(int argc, char *argv[]);

#endif

CC = gcc
CFLAGS = -g -Wall -ansi
TARGET = P0
OBJS = main.o functions.o tree.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c functions.h node.h tree.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c
	
tree.o: tree.c tree.h node.h
	$(CC) $(CFLAGS) -c tree.c	

clean: 
	/bin/rm -f *.o $(TARGET)

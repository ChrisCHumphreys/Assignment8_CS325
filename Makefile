# File: Makefile
# Date: 03/14/18
# Author: Chris Humphreys
#   -> Adapeted from Makefile by Joshua Gearin
# Description: Makefile for the Linked List assignment

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Memory Mangagment Flags
MEMFLAGS=-fsanitize=address -fno-omit-frame-pointer

# Target
TARGET=binary_tree

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o word.o 
	$(CC) main.o word.o -o $(TARGET) $(MEMFLAGS) 

main.o: main.cpp word.h
	$(CC) $(CFLAGS) $(MEMFLAGS) main.cpp 

word.o: word.cpp word.h
	$(CC) $(CFLAGS) $(MEMFLAGS) word.cpp

clean:
	rm -f *.o *~ *.swp $(TARGET) 


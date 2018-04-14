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

$(TARGET): driver.o word.o binary_search_tree.o
	$(CC) driver.o word.o binary_search_tree.o -o $(TARGET) $(MEMFLAGS) 

driver.o: driver.cpp word.h
	$(CC) $(CFLAGS) $(MEMFLAGS) driver.cpp 

word.o: word.cpp word.h
	$(CC) $(CFLAGS) $(MEMFLAGS) word.cpp

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
	$(CC) $(CFLAGS) $(MEMFLAGS) binary_search_tree.cpp

clean:
	rm -f testFile.txt *.o *~ *.swp $(TARGET) 


#ifndef FLITA_HW1_BINARYSET_H
#define FLITA_HW1_BINARYSET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DATA_SIZE 64

typedef struct binaryNode {
    char data[DATA_SIZE];
    struct binaryNode *pointer;
} BinaryNode_t;

BinaryNode_t *createBinaryNode(char *data);

void deleteBinarySet(BinaryNode_t *head);

void printBinarySet(BinaryNode_t *head);

int isUniqueNode(BinaryNode_t *head, char *data);

int isBinary(char data[]);

int isInt(char setLenStr[DATA_SIZE]);

int binaryToDec(char *data);

#endif

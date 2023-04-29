#ifndef FLITA_HW1_BINARYSET_H
#define FLITA_HW1_BINARYSET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define DATA_SIZE 64

typedef struct binaryNode {
    char data[DATA_SIZE];
    struct binaryNode *pointer;
} BinaryNode_t;

BinaryNode_t *createBinaryNode(char *data);

void binarySetInput(BinaryNode_t **binaryHeadNode);

void deleteBinarySet(BinaryNode_t *head);

void printBinarySet(BinaryNode_t *head);

bool isUniqueNode(BinaryNode_t *head, char *data);

bool isBinary(char data[]);

bool isInt(char setLenStr[DATA_SIZE]);

void printDecimalSet(BinaryNode_t *binaryHeadNode);

int binaryToDec(char *data);

#endif

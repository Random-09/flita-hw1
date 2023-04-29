#include "binaryset.h"

BinaryNode_t *createBinaryNode(char *data) {
    BinaryNode_t *node = malloc(sizeof(BinaryNode_t));
    strcpy(node->data, data);
    node->pointer = NULL;
    return node;
}

void deleteBinarySet(BinaryNode_t *head) {
    BinaryNode_t *temporary;
    while (head != NULL) {
        temporary = head;
        head = head->pointer;
        free(temporary);
    }
}

void printBinarySet(BinaryNode_t *head) {
    BinaryNode_t *temporary = head;
    while (temporary != NULL) {
        printf("%s\n", temporary->data);
        temporary = temporary->pointer;
    }
}

int isUniqueNode(BinaryNode_t *head, char *data) {
    BinaryNode_t *temporary = head;
    while (temporary != NULL) {
        if (strcmp(temporary->data, data) == 0)
            return 0;
        temporary = temporary->pointer;
    }
    return 1;
}

int isBinary(char data[]) {
    int length = (int) strlen(data);
    short isBinary = 1;
    for (int i = 0; i < length; i++) {
        if (data[i] == '0' || data[i] == '1')
            isBinary = 1;
        else
            isBinary = 0;
    }
    return isBinary;
}

int isInt(char setLenStr[64]) {
    for (int i = 0; i < strlen(setLenStr); i++) {
        if (!isdigit(setLenStr[i]))
            return 0;
    }
    return 1;
}

int binaryToDec(char *data) {
    int pow = 1;
    int decimalNum = 0;
    for (int i = (int) strlen(data) - 1; i != -1; i--) {
        if (data[i] == '1')
            decimalNum += pow;
        pow <<= 1;
    }
    return decimalNum;
}

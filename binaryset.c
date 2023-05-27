#include "binaryset.h"

BinaryNode_t* createBinaryNode(char* data) {
    BinaryNode_t* node = malloc(sizeof(BinaryNode_t));
    strcpy(node->data, data);
    node->pointer = NULL;
    return node;
}

void binarySetInput(BinaryNode_t** binaryHeadNode) {
    char data[DATA_SIZE];
    int counter = 0;
    BinaryNode_t* binaryTemporaryNode;
    puts("Enter set components, to stop print \"stop\"");
    do {
        scanf("%s", data);
        if (isBinary(data)) {
            if (isUniqueNode(*binaryHeadNode, data)) {
                binaryTemporaryNode = createBinaryNode(data);
                binaryTemporaryNode->pointer = *binaryHeadNode;
                *binaryHeadNode = binaryTemporaryNode;
                counter++;
            } else
                puts("This number is not unique! Try again");
        }
    } while (strcmp(data, "stop") < 0);
}

void deleteBinarySet(BinaryNode_t* head) {
    BinaryNode_t* temporary;
    while (head != NULL) {
        temporary = head;
        head = head->pointer;
        free(temporary);
    }
}

void printBinarySet(BinaryNode_t* head) {
    puts("Binary set:");
    BinaryNode_t* temporary = head;
    while (temporary != NULL) {
        printf("%s\n", temporary->data);
        temporary = temporary->pointer;
    }
}

bool isUniqueNode(BinaryNode_t* head, char* data) {
    while (head != NULL) {
        if (strcmp(head->data, data) == 0)
            return false;
        head = head->pointer;
    }
    return true;
}

bool isBinary(char data[]) {
    int length = (int) strlen(data);
    bool isBinary = false;
    for (int i = 0; i < length; i++) {
        if (data[i] == '0' || data[i] == '1') {
            isBinary = true;
            return isBinary;
        }
    }
    return isBinary;
}

void printDecimalSet(BinaryNode_t* binaryHeadNode) {
    puts("Converted binary set:");
    int decimalNum;
    BinaryNode_t *currentNode = binaryHeadNode;
    while (currentNode != NULL) {
        decimalNum = binaryToDec(currentNode->data);
        currentNode = currentNode->pointer;
        printf("%d\n", decimalNum);
    }
}

int binaryToDec(char* data) {
    int pow = 1;
    int decimalNum = 0;
    for (int i = (int) strlen(data) - 1; i != -1; i--) {
        if (data[i] == '1')
            decimalNum += pow;
        pow <<= 1;
    }
    return decimalNum;
}

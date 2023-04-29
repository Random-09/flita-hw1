#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binaryset.h"

int main() {
    BinaryNode_t *binaryHeadNode = NULL;
    BinaryNode_t *binaryTemporaryNode;
    int8_t setLen, isUnique, decimalNum;
    int8_t i = 0;
    char setLenStr[DATA_SIZE],data[DATA_SIZE], binaryNum[DATA_SIZE];
    do {
        puts("Enter size of binary digit set");
        scanf("%s", setLenStr);
    } while (!isInt(setLenStr));
    setLen = (int8_t) strtol(setLenStr, NULL, 10);
    puts("Enter set components");
    while (i < setLen) {
        scanf("%s", data);
        if (isBinary(data)) {
            isUnique = (int8_t) isUniqueNode(binaryHeadNode, data);
            if (isUnique) {
                binaryTemporaryNode = createBinaryNode(data);
                binaryTemporaryNode->pointer = binaryHeadNode;
                binaryHeadNode = binaryTemporaryNode;
                i++;
            } else
                puts("This number is not unique! Try again");
        } else
            puts("Please enter a binary digit!");
    }
    puts("Binary set:");
    printBinarySet(binaryHeadNode);
    BinaryNode_t *currentNode = binaryHeadNode;
    puts("Converted binary set:");
    while (currentNode != NULL) {
        strcpy(binaryNum, currentNode->data);
        currentNode = currentNode->pointer;
        decimalNum = binaryToDec(binaryNum);
        printf("%d\n", decimalNum);
    }
    deleteBinarySet(binaryHeadNode);
    return EXIT_SUCCESS;
}

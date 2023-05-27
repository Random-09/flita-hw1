#include <stdlib.h>
#include "binaryset.h"

int main() {
    BinaryNode_t* binaryHeadNode = NULL;
    binarySetInput(&binaryHeadNode);

    printBinarySet(binaryHeadNode);
    printDecimalSet(binaryHeadNode);

    deleteBinarySet(binaryHeadNode);
    return EXIT_SUCCESS;
}

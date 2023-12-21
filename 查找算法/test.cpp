#include"BST.h"
#include"binary_search.h"
#include <iostream>
#include <cassert>
int main() {

    int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arrayLength = sizeof(sortedArray) / sizeof(sortedArray[0]);

    int targetValue = 6;

    int iterativeResult = binary_search(sortedArray, arrayLength, targetValue);
    if (iterativeResult != -1) {
        std::cout << "Iterative Binary Search: Found at index " << iterativeResult << std::endl;
    }
    else {
        std::cout << "Iterative Binary Search: Not found in the array" << std::endl;
    }

    int recursiveResult = binary_search_recursive(sortedArray, targetValue, 0, arrayLength - 1);
    if (recursiveResult != -1) {
        std::cout << "Recursive Binary Search: Found at index " << recursiveResult << std::endl;
    }
    else {
        std::cout << "Recursive Binary Search: Not found in the array" << std::endl;
    }

    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inOrderTraversal();
    int targetKey = 45;
    if (!bst.search(targetKey)) {
        bst.insert(targetKey);
        std::cout << targetKey << " not found, inserted." << std::endl;
    }
    else {
        std::cout << targetKey << " found." << std::endl;
    }
    bst.inOrderTraversal();

    return 0;
}

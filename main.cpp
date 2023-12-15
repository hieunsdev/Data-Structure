#include "./lib/sort.h"

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 4, 6, 8, 12, 91, 31, 5, 1, 6, 9, 10, 11, 12, 1};
    SortAlgorithm<int, uint16_t> sortAlgorithm(arr, (uint16_t)(sizeof(arr) / sizeof(int)));
    std::cout << "Array input: " << std::endl;
    sortAlgorithm.printArray();

    /* Deploy kind of sort algorithm */
    // sortAlgorithm.selectionSort();
    // sortAlgorithm.bubbleSort();
    // sortAlgorithm.insertSort();
    // sortAlgorithm.mergeSort();
    sortAlgorithm.quickSort();

    std::cout
        << "\nArray output: " << std::endl;
    sortAlgorithm.printArray();
    return 0;
}
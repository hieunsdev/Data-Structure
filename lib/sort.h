#ifndef _SORT_
#define _SORT_

#include <stdint.h>

#include <iostream>
#include <string>
#define DEBUG 1  // debug in fucking atomic consider

template <typename T, typename U>
class SortAlgorithm {
   private:
    T* inputArray;
    U size;
    void swapValue(T* const a, T* const b);
    void merge(const U left, const U mid, const U right);
    U partition(const U low, const U high);
    void _mergeSort(const U begin, const U end);
    void _quickSort(const U begin, const U end);

   public:
    SortAlgorithm(T* inputArray, const U size) {
        this->inputArray = inputArray;
        this->size = size;
    }

    /**
     * @brief Print array
     *
     */
    void printArray();

    /**
     * @brief Selection sort algorithm
     * @attention Time complexity: O(N^2)
     *            Space complexity: O(1)
     *
     */
    void selectionSort();

    /**
     * @brief Bubble sort algorithm
     * @attention Time complexity: O(N^2)
     *            Space complexity: O(1)
     *
     */
    void bubbleSort();

    /**
     * @brief Insert sort algorithm
     * @attention Time complexity: O(N^2)
     *            Space complexity: O(1)
     *
     */
    void insertSort();

    /**
     * @brief Merge sort algorithm
     * @attention Time complexity: O(N * log N)
     *            Space complexity: O(N)
     *
     */
    void mergeSort();

    /**
     * @brief Quick sort algorithm
     * @attention Worst case
     *                  Time complexity: O(N^2)
     *                  Space complexity: O(N)
     *            Average case
     *                  Time complexity: O(N log N)
     *                  Space complexity: O(N) // consider stack recursive worst case
     *
     */
    void quickSort();
};

/**
 * @brief Just fucking dereference between 2 pointers, not change where the pointer point
 *
 * @tparam T
 * @param a
 * @param b
 */
template <typename T, typename U>
void SortAlgorithm<T, U>::swapValue(T* const a, T* const b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T, typename U>
void SortAlgorithm<T, U>::printArray() {
    for (int32_t i = 0; i < this->size - 1; i++) {
        std::cout << this->inputArray[i] << " ,";
    }
    std::cout << this->inputArray[this->size - 1];
    std::cout << std::endl;
}

template <typename T, typename U>
void SortAlgorithm<T, U>::selectionSort() {
    T* minValue;
#if DEBUG
    uint32_t steps = 0;
#endif
    for (int32_t i = 0; i < this->size; i++) {
        minValue = &(this->inputArray[i]);
        for (int32_t j = i + 1; j < this->size; j++) {
            if (*minValue > this->inputArray[j]) {
                // T temp = this->inputArray[j];
                // this->inputArray[j] = *minValue;  // swap
                // *minValue = temp;                 // swap and dereference
                this->swapValue(minValue, &(this->inputArray[j]));
            }
#if DEBUG
            std::cout << "Step " << steps << ": " << std::endl;
            this->printArray();
            steps += 1;
#endif
        }
    }
}

template <typename T, typename U>
void SortAlgorithm<T, U>::bubbleSort() {
    bool allDone;
    T* traverser;
    U loopCount = 0;  // instead of using 2 for loop, we can use this technique
#if DEBUG
    uint32_t steps = 0;
#endif
    do {
        allDone = true;
        // we subtract loopCount because each iteration the largest element will be the last position
        // so each iteration++ we do not need consider the last position-- anymore
        for (int32_t i = 0; i < this->size - loopCount - 1; i++) {
            traverser = &(this->inputArray[i]);
            if (*traverser > this->inputArray[i + 1]) {
                allDone = false;
                this->swapValue(traverser, &(this->inputArray[i + 1]));
            }
#if DEBUG
            std::cout << "Step " << steps << ":" << std::endl;
            this->printArray();
            steps += 1;
#endif
        }
        loopCount += 1;
    } while (!allDone);
}

template <typename T, typename U>
void SortAlgorithm<T, U>::insertSort() {
    T* traverser;
#if DEBUG
    uint32_t steps = 0;
#endif
    for (int32_t i = 0; i < this->size - 1; i++) {
        traverser = &(this->inputArray[i]);
        if (*traverser > this->inputArray[i + 1]) {
            this->swapValue(traverser, &(this->inputArray[i + 1]));
            // insert phase, we fuck put the value in the right position
            for (int32_t j = i; j > 0; j--) {
                traverser = &(this->inputArray[j]);
                if (*traverser < this->inputArray[j - 1]) {
                    this->swapValue(traverser, &(this->inputArray[j - 1]));
                }
#if DEBUG
                std::cout << "Step " << steps << " (" << *traverser << " position " << j << "): " << std::endl;
                this->printArray();
                steps += 1;
#endif
            }
        }
    }
}

template <typename T, typename U>
void SortAlgorithm<T, U>::merge(const U left, const U mid, const U right) {
    const U sizeOfLeftArray = mid - left + 1;
    const U sizeOfRightArray = right - mid;

    T* leftArray = new T(sizeOfLeftArray);
    T* rightArray = new T(sizeOfRightArray);

// assign all element of splited array
#if DEBUG
    std::cout << "\tLeft array = ";
#endif
    for (int32_t i = 0; i < sizeOfLeftArray; i++) {
        *(leftArray + i) = this->inputArray[left + i];
#if DEBUG
        std::cout << *(leftArray + i) << ", ";
#endif
    }
#if DEBUG
    std::cout << "\n\tRight array = ";
#endif
    for (int32_t i = 0; i < sizeOfRightArray; i++) {
        *(rightArray + i) = this->inputArray[mid + i + 1];
#if DEBUG
        std::cout << *(rightArray + i) << ", ";
#endif
    }

    // sort left and right arrays into input array
    U indexOfInputArray = left, indexOfLeftArray = 0, indexOfRightArray = 0;
    while (indexOfLeftArray < sizeOfLeftArray && indexOfRightArray < sizeOfRightArray) {
        if (leftArray[indexOfLeftArray] < rightArray[indexOfRightArray]) {
            this->inputArray[indexOfInputArray] = *(leftArray + indexOfLeftArray);
            indexOfLeftArray += 1;
        } else {
            this->inputArray[indexOfInputArray] = *(rightArray + indexOfRightArray);
            indexOfRightArray += 1;
        }
        indexOfInputArray += 1;
    }

    // push the remain elements of the left and right arrays into input array
    while (indexOfLeftArray < sizeOfLeftArray) {
        this->inputArray[indexOfInputArray] = leftArray[indexOfLeftArray];
        indexOfInputArray += 1;
        indexOfLeftArray += 1;
    }
    while (indexOfRightArray < sizeOfRightArray) {
        this->inputArray[indexOfInputArray] = rightArray[indexOfRightArray];
        indexOfRightArray += 1;
        indexOfInputArray += 1;
    }

#if DEBUG
    std::cout << "\n\tMerged array = ";
    for (int32_t i = 0; i < indexOfInputArray; i++) {
        std::cout << this->inputArray[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "\tResult after merge = ";
    for (int32_t i = 0; i < this->size; i++) {
        std::cout << this->inputArray[i] << ", ";
    }
    std::cout << std::endl;
#endif

    // free heap of 2 dynamic arrays
    delete[] leftArray;
    delete[] rightArray;
}

template <typename T, typename U>
void SortAlgorithm<T, U>::_mergeSort(const U begin, const U end) {
    if (begin < end) {
        const U mid = begin + (end - begin) / 2;
#if DEBUG
        uint32_t steps = 0;
        std::cout << "\nStep " << steps << " (mid = " << mid << ", begin = " << begin << ", end = " << end << std::endl;
        std::cout << "Split left into (" << begin << ", " << mid << ")" << std::endl;
        steps += 1;
#endif
        mergeSort(begin, mid);
#if DEBUG
        std::cout << "End split left (" << begin << ", " << mid << ")" << std::endl;
        std::cout << "Split right into (" << mid + 1 << ", " << end << ")" << std::endl;
#endif
        mergeSort(mid + 1, end);
#if DEBUG
        std::cout << "End split left (" << mid + 1 << ", " << end << ")" << std::endl;
        std::cout << "Start merge (left = " << begin << ", mid = " << mid << ", right = " << end << ")" << std::endl;
#endif
        this->merge(begin, mid, end);
    }
}

template <typename T, typename U>
void SortAlgorithm<T, U>::mergeSort() {
    this->_mergeSort(0, this->size - 1);
}

template <typename T, typename U>
U SortAlgorithm<T, U>::partition(const U low, const U high) {
    const T pivot = this->inputArray[low];

    U traverIndex = high + 1;
#if DEBUG
    std::cout << "\tTake pivot = " << pivot << ", low = " << low << ", high = " << high << std::endl;
    uint32_t steps = 0;
    std::cout << "\tStart divide base on pivot:" << std::endl;
#endif
    // divide lower and higer to left and right side
    for (int32_t i = high; i >= low + 1; i--) {
        if (this->inputArray[i] > pivot) {
            traverIndex -= 1;
            this->swapValue(&this->inputArray[i], &this->inputArray[traverIndex]);
#if DEBUG
            std::cout << "\t\tStep " << steps << " = ";
            this->printArray();
            steps += 1;
#endif
        }
    }
    // swap pivot into right place after divide into lower and higher partition
    this->swapValue(&this->inputArray[low], &this->inputArray[traverIndex - 1]);
#if DEBUG
    std::cout << "\tStep (final swap of partition) " << steps << " = ";
    this->printArray();
    steps += 1;

    std::cout << "== > Return value = " << traverIndex - 1 << ", value = " << this->inputArray[traverIndex - 1] << std::endl;
#endif
    return traverIndex - 1;
}

template <typename T, typename U>
void SortAlgorithm<T, U>::quickSort() {
    this->_quickSort(0, this->size - 1);
}

template <typename T, typename U>
void SortAlgorithm<T, U>::_quickSort(U begin, U end) {
    if (begin < end) {
        U pivotPosition = this->partition(begin, end);

        // handle lower partition
        this->_quickSort(begin, pivotPosition - 1);
        // handle greater partition
        this->_quickSort(pivotPosition + 1, end);
    }
}

#endif  // _SORT_
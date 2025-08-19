#include <iostream>
#include "src/912-sort-array.cpp"

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int nums[] = {5, 2, 9, 1, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    std::cout << "Original array: ";
    printArray(nums, numsSize);

    int* sortedArray = sortArray(nums, numsSize, &returnSize);

    std::cout << "Sorted array: ";
    printArray(sortedArray, returnSize);

    return 0;
}
#include <algorithm>
#include <iostream>

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// heapify which is to make sure largest two elements are in top 3
void heapify(int *nums, int n, int i) {
  // get it's child nodes
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;
  if (l < n && nums[l] > nums[largest]) {
    largest = l;
  }
  if (r < n && nums[r] > nums[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(&nums[i], &nums[largest]);
    heapify(nums, n, largest);
  }
}

void buildHeap(int *nums, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n) {
    buildHeap(nums, n, l);
  }
  if (r < n) {
    buildHeap(nums, n, r);
  }
  if (l < n || r < n) {
    heapify(nums, n, i);
  }
}

void heapSort(int *nums, int n) {
  // n/2 number of ndoes that are not leaf
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(nums, n, i);
  }
  // heap sort
  for (int i = n - 1; i >= 0; i--) {
    // printf("nums: %d\n",nums[0]);
    swap(&nums[0], &nums[i]);
    heapify(nums, i, 0);
  }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
  heapSort(nums, numsSize);
  *returnSize = numsSize;
  return nums;
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int nums[] = {5, 2, 3, 1};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;

  std::cout << "Original array: ";
  printArray(nums, numsSize);

  int *sortedArray = sortArray(nums, numsSize, &returnSize);

  std::cout << "Sorted array: ";
  printArray(sortedArray, returnSize);

  return 0;
}

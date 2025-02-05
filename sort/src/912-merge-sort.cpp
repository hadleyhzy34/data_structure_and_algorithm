#include <algorithm>
#include <iostream>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge(int *nums, int *tmp, int l, int m, int r) {
  int ldx = l;
  int rdx = m + 1;
  for (int i = l; i <= r; i++) {
    if (ldx > m) {
      tmp[i] = nums[rdx++];
    } else if (rdx > r) {
      tmp[i] = nums[ldx++];
    } else if (nums[ldx] <= nums[rdx]) {
      tmp[i] = nums[ldx++];
    } else {
      tmp[i] = nums[rdx++];
    }
  }
  for (int i = l; i <= r; i++) {
    tmp[i] = nums[i];
  }
}

// merge sort function
void mergeSort(int *nums, int *tmp, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(nums, tmp, l, m);
    mergeSort(nums, tmp, m + 1, r);
    merge(nums, tmp, l, m, r);
  }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
  int *tmp = (int *)malloc(numsSize * sizeof(int));
  mergeSort(nums, tmp, 0, numsSize - 1);
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
  int nums[] = {5,2,3,1};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;

  std::cout << "Original array: ";
  printArray(nums, numsSize);

  int *sortedArray = sortArray(nums, numsSize, &returnSize);

  std::cout << "Sorted array: ";
  printArray(sortedArray, returnSize);

  return 0;
}

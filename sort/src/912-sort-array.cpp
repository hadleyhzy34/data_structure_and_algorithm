#include <algorithm>
#include <iostream>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// // Partition function to rearrange elements around a pivot
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high]; // Choosing the last element as the pivot
//     int i = (low - 1); // Index of smaller element

//     for (int j = low; j <= high - 1; j++) {
//         // If current element is smaller than or equal to pivot
//         if (arr[j] <= pivot) {
//             i++; // Increment index of smaller element
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

struct pair{
    int x;
    int y;
};

struct pair partition(int *nums, int l, int r) {
  int pivot = nums[l];
  int i = l, j = l, k = r;
  while (j <= k) {
    if (nums[j] < pivot) {
      swap(&nums[i], &nums[j]);
      i++;
      j++;
    } else if (nums[j] > pivot) {
      swap(&nums[j], &nums[k]);
      k--;
    } else {
      j++;
    }
  }
  struct pair p = {i,k};
  return p;
}

// QuickSort function
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        struct pair p = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, p.x-1);
        quickSort(arr, p.y+1, high);
    }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
  quickSort(nums, 0, numsSize - 1);
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
  int nums[] = {110, 100, 0};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;

  std::cout << "Original array: ";
  printArray(nums, numsSize);

  int *sortedArray = sortArray(nums, numsSize, &returnSize);

  std::cout << "Sorted array: ";
  printArray(sortedArray, returnSize);

  return 0;
}

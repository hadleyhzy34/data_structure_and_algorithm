#include <iostream>
#include <string.h>
#include <vector>

class NumArray {
public:
  NumArray(std::vector<int> &nums) {
    n = nums.size();
    this->num = nums;
    arr = std::vector<int>(4 * n, 0);
    build(arr, nums, 1, 0, n - 1);
  }

  void build(std::vector<int> &arr, std::vector<int> &nums, int idx, int l,
             int r) {
    if (l == r) {
      arr[idx] = nums[l];
    } else {
      int m = (l + r) / 2;
      build(arr, nums, 2 * idx, l, m);
      build(arr, nums, 2 * idx + 1, m + 1, r);
      arr[idx] = arr[2 * idx] + arr[2 * idx + 1];
    }
  }

  void update(int index, int val) {
    int c = val - num[index];
    num[index] += c;
    update(arr, 1, 0, n - 1, index, c);
  }

  void update(std::vector<int> &arr, int nIdx, int l, int r, int idx, int val) {
    if (l == r) {
      arr[nIdx] += val;
    } else {
      int m = (l + r) / 2;
      if (l <= idx && idx <= m) {
        update(arr, nIdx * 2, l, m, idx, val);
      } else {
        update(arr, nIdx * 2 + 1, m + 1, r, idx, val);
      }
      arr[nIdx] = arr[nIdx * 2] + arr[nIdx * 2 + 1];
    }
  }

  int sumRange(int left, int right) {
    return sumRange(arr, 1, 0, n - 1, left, right);
  }

  int sumRange(std::vector<int> &arr, int nIdx, int l, int r, int left,
               int right) {
    if (l > right || r < left) {
      return 0;
    }
    if (l >= left && r <= right) {
      return arr[nIdx];
    }
    int m = (l + r) / 2;
    return sumRange(arr, nIdx * 2, l, m, left, right) +
           sumRange(arr, nIdx * 2 + 1, m + 1, r, left, right);
  }

private:
  std::vector<int> arr;
  std::vector<int> num;
  int n;
};

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

class Solution {
public:
  int reversePairs(std::vector<int> &nums) {
    int n = nums.size();

    // sparse segment tree, value
    std::set<long long> numSet;
    for (auto i = 0; i < n; i++) {
      int threshold = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
      numSet.insert(nums[i]);
      numSet.insert(threshold);
    }
    int size = numSet.size();

    std::vector<int> st(4 * size, 0);

    int cnt = 0;
    for (auto p : numSet) {
      cmpIdx[p] = cnt++;
    }

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      int idx = cmpIdx[nums[i]];
      int threshold = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
      int tdx = cmpIdx[threshold];
      res += querySegmentTree(st, 0, 0, size - 1, tdx);
      updateSegmentTree(st, 0, 0, size - 1, idx);
    }
    return res;
  }

  // iterative approach on updateSegmentTree
  void updateSegmentTree(std::vector<int> &segmentTree, int idx, int lower,
                         int upper, int cur) {
    while (lower <= upper) {
      segmentTree[idx]++;
      if (lower == upper)
        break;
      int m = lower + (upper - lower) / 2;
      if (cur <= m) {
        upper = m;
        idx = 2 * idx + 1;
      } else {
        lower = m + 1;
        idx = 2 * idx + 2;
      }
    }
  }

  // Recursive approach for querying the segment tree
  int querySegmentTree(std::vector<int> &segmentTree, int idx, int l, int r,
                       int tdx) {
    if (l > r || tdx < l || tdx > r) {
      return 0;
    }
    int ans = 0;
    while (l <= r) {
      if (l == r) {
        return segmentTree[idx] + ans;
      }
      int m = l + (r - l) / 2;
      if (tdx <= m) {
        idx = 2 * idx + 1;
        r = m;
      } else {
        idx = 2 * idx + 2;
        l = m + 1;
        ans += segmentTree[2 * idx + 1];
      }
    }
    return ans;
  }

private:
  std::unordered_map<long long, int> cmpIdx;
};
class Solution1 {
public:
  int reversePairs(std::vector<int> &nums) {
    int n = nums.size();

    // sparse segment tree, value
    std::set<long long> numSet;
    for (auto i = 0; i < n; i++) {
      int threshold = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
      numSet.insert(nums[i]);
      numSet.insert(threshold);
    }
    int size = numSet.size();

    std::vector<int> st(4 * size, 0);

    int cnt = 0;
    for (auto p : numSet) {
      cmpIdx[p] = cnt++;
    }

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      int idx = cmpIdx[nums[i]];
      int threshold = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
      int tdx = cmpIdx[threshold];
      res += querySegmentTree(st, 0, 0, size - 1, tdx);
      updateSegmentTree(st, 0, 0, size - 1, idx);
    }
    return res;
  }

  // iterative approach on updateSegmentTree
  void updateSegmentTree(std::vector<int> &segmentTree, int idx, int lower,
                         int upper, int cur) {
    while (lower <= upper) {
      segmentTree[idx]++;
      if (lower == upper)
        break;
      int m = lower + (upper - lower) / 2;
      if (cur <= m) {
        upper = m;
        idx = 2 * idx + 1;
      } else {
        lower = m + 1;
        idx = 2 * idx + 2;
      }
    }
  }

  // Recursive approach for querying the segment tree
  int querySegmentTree(std::vector<int> &segmentTree, int idx, int l, int r,
                       int tdx) {
    if (l > r || tdx < l || tdx > r) {
      return 0;
    }
    int ans = 0;
    while (l <= r) {
      if (l == r) {
        return segmentTree[idx] + ans;
      }
      int m = l + (r - l) / 2;
      if (tdx <= m) {
        idx = 2 * idx + 1;
        r = m;
      } else {
        idx = 2 * idx + 2;
        l = m + 1;
        ans += segmentTree[2 * idx + 1];
      }
    }
    return ans;
  }

private:
  std::unordered_map<long long, int> cmpIdx;
};
int main() {
  Solution solution;

  // std::vector<int> nums = {5, 2, 6, 1};
  // std::vector<int> nums = {-1};
  // std::vector<int> nums = {-1, -1};
  std::vector<int> nums = {-5, -5};
  int result = solution.reversePairs(nums);

  std::cout << result << std::endl;

  return 0;
}

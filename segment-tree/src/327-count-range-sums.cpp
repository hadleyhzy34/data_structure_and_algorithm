#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  int countRangeSum(std::vector<int> &nums, int lower, int upper) {
    int n = nums.size();

    // prefix sum
    std::vector<int> pfx;
    for (auto num : nums) {
      if (pfx.empty()) {
        pfx.push_back(num);
      } else {
        pfx.push_back(pfx.back() + num);
      }
    }

    // shift
    int smallest = *std::min_element(pfx.begin(), pfx.end());

    for (auto i = 0; i < n; i++) {
      pfx[i] = pfx[i] - smallest;
    }

    int largest = *std::max_element(pfx.begin(), pfx.end());

    // build segment tree
    std::vector<int> st(4 * n, 0);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (upper + pfx[i] >= 0) {
        res += querySegmentTree(st, 0, 0, largest,
                                std::min(largest, upper + pfx[i]));
        if (lower + pfx[i] - 1 > 0) {
          res -= querySegmentTree(st, 0, 0, largest, lower + pfx[i] - 1);
        }
      }
      updateSegmentTree(st, 0, 0, largest, pfx[i]);
    }
    //-1 idx
    int sft = 0 - smallest;
    if (upper + sft >= 0) {
      res +=
          querySegmentTree(st, 0, 0, largest, std::min(largest, upper + sft));
      if (lower + sft - 1 > 0) {
        res -= querySegmentTree(st, 0, 0, largest, lower + sft - 1);
      }
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
  //
  int querySegmentTree(std::vector<int> &segmentTree, int idx, int lower,
                       int upper, int cur) {
    if (lower > upper || cur < lower || cur > upper) {
      return 0;
    }
    int ans = 0;
    while (lower <= upper) {
      if (lower == upper) {
        ans += segmentTree[idx];
        break;
      }
      int m = lower + (upper - lower) / 2;
      if (cur <= m) {
        upper = m;
        idx = 2 * idx + 1;
      } else {
        ans += segmentTree[idx * 2 + 1];
        lower = m + 1;
        idx = 2 * idx + 2;
      }
    }
    return ans;
  }
};

class Solution1 {
public:
  int countRangeSum(std::vector<int> &nums, int lower, int upper) {
    int n = nums.size();

    // prefix sum
    std::vector<long long> pfx = {0};
    for (auto num : nums) {
      pfx.push_back(pfx.back() + num);
    }

    // sparse segment tree, value
    std::set<long long> pfxSet;
    for (auto i = 0; i <= n; i++) {
      pfxSet.insert(pfx[i]);
      pfxSet.insert(pfx[i] - lower);
      pfxSet.insert(pfx[i] - upper);
    }
    int size = pfxSet.size();

    std::vector<int> st(4 * size, 0);

    int cnt = 0;
    for (auto p : pfxSet) {
      cmpIdx[p] = cnt++;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
      int lIdx = cmpIdx[pfx[i] - upper];
      int uIdx = cmpIdx[pfx[i] - lower];
      int idx = cmpIdx[pfx[i]];
      res += querySegmentTree(st, 0, 0, size - 1, lIdx, uIdx);
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
  //
  //   int querySegmentTree(std::vector<int> &segmentTree, int idx, int l, int
  //   r,
  //                        int lIdx, int uIdx) {
  //                         std::cout<<idx<<" "<<l<<" "<<r<<" "<<lIdx<<"
  //                         "<<uIdx<<std::endl;
  //     if (l > r || lIdx > uIdx || lIdx > r || uIdx < l) {
  //             return 0;
  //         }
  //     if (l == lIdx && r == uIdx) {
  //       return segmentTree[idx];
  //     }
  //     // int m = lIdx + (uIdx - lIdx) / 2;
  //     int m = l + (r - l) / 2;
  //     return querySegmentTree(segmentTree, idx * 2 + 1, l, m, lIdx,
  //     std::min(m,uIdx)) +
  //            querySegmentTree(segmentTree, idx * 2 + 2, m + 1, r, std::max(m
  //            + 1,lIdx), uIdx);
  //   }

  // Recursive approach for querying the segment tree
  int querySegmentTree(std::vector<int> &segmentTree, int idx, int l, int r,
                       int lIdx, int uIdx) {
    if (l > r || lIdx > uIdx || lIdx > r || uIdx < l) {
      return 0;
    }
    if (lIdx <= l && uIdx >= r) {
      return segmentTree[idx];
    }
    int m = l + (r - l) / 2;
    return querySegmentTree(segmentTree, idx * 2 + 1, l, m, lIdx,
                            std::min(m, uIdx)) +
           querySegmentTree(segmentTree, idx * 2 + 2, m + 1, r,
                            std::max(m + 1, lIdx), uIdx);
  }

private:
  std::unordered_map<long long, int> cmpIdx;
};

int main() {
  Solution solution;

  // std::vector<int> nums = {5, 2, 6, 1};
  // std::vector<int> nums = {-1};
  std::vector<int> nums = {-2, 5, -1};
  int lower = -2;
  int upper = 2;
  int result = solution.countRangeSum(nums, lower, upper);

  std::cout << result << std::endl;

  return 0;
}

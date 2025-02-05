#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

/*early version of data compression
    // data compression
    std::set<std::pair<int, int>> nset;
    for (auto i = 0; i < nums.size(); i++) {
      nset.insert(std::make_pair(nums[i], i));
    }
    int cnt = -1;
    int pre = INT_MIN;
    for (auto key : nset) {
      if (key.first != pre) {
        nums[key.second] = (++cnt);
      } else {
        nums[key.second] = cnt;
      }
      pre = key.first;
    }
*/

class Solution {
public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    int n = nums.size();
    // data compression
    std::set<int> uniqNums(nums.begin(), nums.end());
    std::unordered_map<int, int> compressNums;
    int cnt = 0;
    for (auto num : uniqNums) {
      compressNums[num] = cnt++;
    }
    for (int i = 0; i < n; i++) {
      nums[i] = compressNums[nums[i]];
    }

    // build segment tree
    std::vector<int> st(4 * n, 0);
    std::vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      res[i] = querySegmentTree(st, 0, 0, n - 1, nums[i]);
      updateSegmentTree(st, 0, 0, n - 1, nums[i]);
    }
    return res;
  }
  // void updateSegmentTree(std::vector<int> &segmentTree, int idx, int lower,
  //                        int upper, int cur) {
  //   // printf("idx:%d,lower:%d,upper:%d,cur:%d\n", idx, lower, upper, cur);
  //   if (lower > upper || cur < lower || cur > upper) {
  //     return;
  //   }
  //   if (lower == upper) {
  //     segmentTree[idx]++;
  //     return;
  //   }
  //   int m = lower + (upper - lower) / 2;
  //   updateSegmentTree(segmentTree, idx * 2 + 2, m + 1, upper, cur);
  //   updateSegmentTree(segmentTree, idx * 2 + 1, lower, m, cur);
  //   segmentTree[idx] = segmentTree[idx * 2 + 1] + segmentTree[idx * 2 + 2];
  // }

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
  // int querySegmentTree(std::vector<int> &segmentTree, int idx, int lower,
  //                      int upper, int cur) {
  //   if (lower > upper || cur - 1 < lower || cur - 1 > upper) {
  //     return 0;
  //   }
  //   if (upper == cur - 1) {
  //     return segmentTree[idx];
  //   } else {
  //     int m = lower + (upper - lower) / 2;
  //     if (cur - 1 > m) {
  //       int l = segmentTree[idx * 2 + 1];
  //       int r = querySegmentTree(segmentTree, idx * 2 + 2, m + 1, upper,
  //       cur); return l + r;
  //     } else {
  //       return querySegmentTree(segmentTree, idx * 2 + 1, lower, m, cur);
  //     }
  //   }
  // }
  //
  int querySegmentTree(std::vector<int> &segmentTree, int idx, int lower,
                       int upper, int cur) {
    if (lower > upper || cur - 1 < lower || cur - 1 > upper) {
      return 0;
    }
    int ans = 0;
    while (lower <= upper) {
      if (lower == upper) {
        ans += segmentTree[idx];
        break;
      }
      int m = lower + (upper - lower) / 2;
      if (cur - 1 <= m) {
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

int main() {
  Solution solution;

  // std::vector<int> nums = {5, 2, 6, 1};
  // std::vector<int> nums = {-1};
  std::vector<int> nums = {-1, -1};
  std::vector<int> result = solution.countSmaller(nums);

  for (const auto &num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

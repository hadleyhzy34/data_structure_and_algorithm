#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  int smallestDistancePair(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    // matrice edges(n);
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < i; j++) {
    //     edges[i].push_back(std::abs(nums[j] - nums[i]));
    //   }
    // }
    int s = 0;
    int l = nums[n - 1] - nums[0];
    while (s < l) {
      int m = s + (l - s) / 2;
      //   int cnt = countLQ(nums, m, n);
      int cnt = countPairs(nums, m);
      if (k <= cnt) {
        l = m;
      } else {
        s = m + 1;
      }
    }
    return s;
  }

  int countLQ(std::vector<int> &nums, int val, int n) {
    int cnt = 0;

    int rdx = n - 1;
    int cdx = n - 2;

    while (rdx > 0) {
      int cur = std::abs(nums[rdx] - nums[cdx]);
      if (cur <= val) {
        if (cdx == 0) {
          cnt += rdx;
          rdx--;
        } else {
          cdx--;
        }
      } else {
        cnt += (rdx - 1 - (cdx + 1) + 1);
        rdx--;
        cdx = (cdx + 1 >= rdx - 1) ? rdx - 1 : (cdx + 1);
        // cnt += (rdx - 1 - (cdx + 1) + 1);
      }
    }
    return cnt;
  }
  int countPairs(std::vector<int> &nums, int val) {
    int cnt = 0;
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
      while (j < i && nums[i] - nums[j] > val) {
        j++;
      }
      cnt += (i - j + 1 - 1);
    }
    return cnt;
  }
};
int main() {
  std::vector<int> a = {62, 100, 4};
  Solution sol;
  sol.smallestDistancePair(a, 2);
  return 0;
}

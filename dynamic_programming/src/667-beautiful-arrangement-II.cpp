#include <iostream>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution1 {
public:
  std::vector<int> constructArray(int n, int k) {
    std::vector<int> nums;
    std::string cur(n, '0');
    backTrack(1, n, cur, k, nums);
    return res;
  }

  bool backTrack(int pos, const int n, std::string &cur, int k,
                 std::vector<int> &nums) {
    if (pos == n + 1) {
      if (dset.size() == k) {
        res = nums;
        umap[cur] = false;
        return true;
      }
    }
    if (umap.find(cur) != umap.end()) {
      return umap[cur];
    }
    for (int i = 1; i <= n; i++) {
      if (cur[i - 1] == '0') {
        if (nums.empty()) {
          nums.push_back(i);
          cur[i - 1] = '1';
          if (backTrack(pos + 1, n, cur, k, nums)) {
            return true;
          }
          cur[i - 1] = '0';
          nums.pop_back();
        } else {
          int last = nums.back();
          int diff = std::abs(i - last);
          if (dset.find(diff) != dset.end()) {
            nums.push_back(i);
            cur[i - 1] = '1';
            if (backTrack(pos + 1, n, cur, k, nums)) {
              return true;
            }
            cur[i - 1] = '0';
            nums.pop_back();
          } else {
            dset.insert(diff);
            nums.push_back(i);
            cur[i - 1] = '1';
            if (backTrack(pos + 1, n, cur, k, nums)) {
              return true;
            }
            cur[i - 1] = '0';
            dset.erase(diff);
            nums.pop_back();
          }
        }
      }
    }

    umap[cur] = false;
    return false;
  }

private:
  std::vector<int> res;
  std::unordered_map<std::string, bool> umap;
  std::unordered_set<int> dset;
};

class Solution {
public:
  std::vector<int> constructArray(int n, int k) {
    std::vector<int> res;
    int s = 1;
    int l = n;
    for (int i = 0; i < k; i++) {
      if (i % 2 == 0) {
        res.push_back(s++);
      } else {
        res.push_back(l--);
      }
    }
    for (int i = s; i <= l; i++) {
      res.push_back(i);
    }
    return res;
  }
};

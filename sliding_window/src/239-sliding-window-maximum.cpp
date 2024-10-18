#include <iostream>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
    std::priority_queue<int> l;
    std::priority_queue<int, std::vector<int>, std::greater<int>> r;

    std::unordered_map<int, int> umap;
    std::vector<double> res;
    int iLen = (k & 1) ? k / 2 + 1 : k / 2;
    for (int i = 0; i < k; i++) {
      l.push(nums[i]);
    }
    for (int i = 0; i < k / 2; i++) {
      r.push(l.top());
      l.pop();
    }
    for (auto i = k; i < nums.size(); i++) {
      int balance = 0;
      // push elements
      if (l.empty() || nums[i] <= l.top()) {
        l.push(nums[i]);
        balance++;
      } else {
        r.push(nums[i]);
        balance--;
      }

      // remove elements nums[i-k]
      if (i >= k) {
        if (nums[i - k] <= l.top()) {
          balance--;
          if (l.top() != nums[i - k]) {
            umap[nums[i - k]]++;
          } else {
            l.pop();
            umap[nums[i - k]]--;
          }
        } else {
          balance++;
          if (r.top() != nums[i - k]) {
            umap[nums[i - k]]++;
          } else {
            r.pop();
            umap[nums[i - k]]--;
          }
        }
      }

      // remove top elements that are already out side of range
      while (!l.empty() && umap[l.top()] > 0) {
        umap[l.top()]--;
        l.pop();
      }

      while (!r.empty() && umap[r.top()] > 0) {
        umap[r.top()]--;
        r.pop();
      }

      // balance between two heapq
      if (balance == 2) {
        r.push(l.top());
        l.pop();
      } else if (balance == -2) {
        l.push(r.top());
        r.pop();
      }

      if (k & 1) {
        res.push_back((double)l.top());
      } else {
        res.push_back(((double)l.top() + (double)r.top()) / 2);
      }
    }
    return res;
  }
};

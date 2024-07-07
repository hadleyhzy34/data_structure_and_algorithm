#include <functional>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
    std::priority_queue<int> l;
    std::priority_queue<int, std::vector<int>, std::greater<int>> r;

    std::vector<double> res;
    for (auto i = 0; i < nums.size(); i++) {
      if (i < k) {
      }
    }

    void test(std::priority_queue & num) {
      printf("\n");
      return;
    }
    void insertNum(int num, std::priority_queue<int> &l,
                   std::priority_queue<int> &r) {
      // std::priority_queue<int, std::vector<int>, std::greater<int>> &r) {
      if (l.size() == 0 || num <= l.top()) {
        l.push(num);
        if (l.size() > r.size() + 1) {
          r.push(l.top());
          l.pop();
        }
      } else {
        r.push(num);
        if (r.size() > l.size()) {
          l.push(l.top());
          r.pop();
        }
      }
    }

    void removeNum(int num, std::priority_queue<int> &)
  };

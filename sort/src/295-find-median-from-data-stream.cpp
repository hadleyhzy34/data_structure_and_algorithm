#include <functional>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (l.size() == r.size()) {
      if (num < r.top()) {
        l.push(num);
      } else {
        r.push(num);
        int tmp = r.top();
        r.pop();
        l.push(tmp);
      }
    } else {
      if (num > r.top()) {
        r.push(num);
      } else {
        l.push(num);
        int tmp = l.top();
        l.pop();
        r.push(tmp);
      }
    }
  }

  double findMedian() {
    if (r.size() == l.size()) {
      return (double(r.top()) + double(l.top())) / 2;
    } else {
      return double(r.top());
    }
  }

private:
  int size = 0;
  std::priority_queue<int> r;
  std::priority_queue<int, std::vector<int>, std::greater<int>> l;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

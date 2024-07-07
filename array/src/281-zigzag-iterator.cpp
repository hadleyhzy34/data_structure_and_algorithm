#include <iostream>
#include <string.h>
#include <vector>

class ZigzagIterator {
public:
  ZigzagIterator(std::vector<int> &v1, std::vector<int> &v2) {
    len1 = v1.size();
    len2 = v2.size();
    lv = v1;
    rv = v2;
  }

  int next() {
    if (l % 2 == 0) {
      int res = lv[lPtr++];
      l++;
      return res;
    } else {
      int res = rv[rPtr++];
      l++;
      return res;
    }
  }

  bool hasNext() {
    if (l % 2 == 0) {
      return (lPtr < lv.size()) ? true : false;
    } else {
      return (rPtr < rv.size()) ? true : false;
    }
  }

private:
  int l = 0;
  int lPtr = 0;
  int rPtr = 0;
  int len1, len2;
  std::vector<int> lv;
  std::vector<int> rv;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

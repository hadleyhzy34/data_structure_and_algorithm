#include <iostream>
#include <string.h>

class Solution {
public:
  int hammingDistance(int x, int y) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      if (((x >> i) & 1) != ((y >> i) & 1)) {
        res++;
      }
    }
    return res;
  }

  int hammingDistancePopCount(int x, int y) {
    return __builtin_popcount(x ^ y);
  }

  int hammingDistancePopShift(int x, int y) {
    int res = 0;
    int z = x ^ y;
    while (z) {
      res += z & 1;
      z >>= 1;
    }
    return res;
  }

  int hammingDistanceBK(int x, int y) {
    int res = 0;
    int z = x ^ y;
    while (z) {
      // remove right most 1s
      z = z & (z - 1);
      res++;
    }
    return res;
  }

private:
};

int main(int argc, char *argv[]) { return 0; }

class Solution {
public:
  int getSum(int a, int b) {
    int res = 0;
    int c = 0;
    while (a || b) {
      if (a) {
        c += (a & 1);
        a >>= 1;
      }
      if (b) {
        c += (b & 1);
        b >>= 1;
      }
      if (c == 0) {
        res = res << 1;
      } else if (c == 1) {
        res = res << 1;
        c = 0;
      } else if (c == 2) {
        res = res << 1 | 1;
        c = 0;
      } else if (c == 3) {
        res = res << 1 | 2;
        c = 1;
      }
    }
    return res;
  }
};

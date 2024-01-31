#include <iostream>
#include <vector>

double myPow(double x, int n) {
  double res = 1;
  int sign = (n > 0) ? 1 : 0;
  n = (n > 0) ? n : -n;
  if (n > 0) {
    // pre = x^cnt, initial: pre = x^0 = 1.0
    double pre = 1.0;
    while (n) {
      res *= (n & 1) ? pre * x : 1;
      n >>= 1;
      pre = pre * x;
    }
  }
  return (sign == 1) ? res : 1 / res;
}

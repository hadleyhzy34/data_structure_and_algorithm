#include <iostream>
#include <math.h>

bool checkPerfectNumber(int num) {
  if (num == 1)
    return false;
  int i = 2;
  int res = 1;

  for (i; i * i <= num; i++) {
    if (num % i == 0) {
      res += i;
      res += (num / i);
    }
  }
  return res == num;
}

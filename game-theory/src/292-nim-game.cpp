#include <iostream>
#include <vector>

/* bool winNim(int n, bool turn) { */
/*   if (n <= 3) { */
/*     return turn; */
/*   } */
/*   bool f = winNim(n - 1, !turn); */
/*   bool s = winNim(n - 2, !turn); */
/*   bool t = winNim(n - 3, !turn); */
/**/
/*   if (turn) { */
/*     return f || s || t; */
/*   } else { */
/*     return ~(f || s || t); */
/*   } */
/* } */

// recursion based method
bool winNim(int n) {
  if (n <= 3) {
    return true;
  }
  bool f = winNim(n - 1);
  bool s = winNim(n - 2);
  bool t = winNim(n - 3);

  return ~(f || s || t);
}

bool canWinNim(int n) {
  bool turn = true;
  return winNim(n);
}

// dynamic programming based method
bool canWinNim_v0(int n) {
  int dp[n];
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  for (auto i = 3; i <= n; i++) {
    if ((!dp[i - 1]) || (!dp[i - 2]) || (!dp[i - 3])) {
      dp[i] = 1;
    } else {
      dp[i] = 0;
    }
  }
  return dp[n - 1];
}

// math
bool canWinNim_v1(int n) { return !(n % 4 == 0); }

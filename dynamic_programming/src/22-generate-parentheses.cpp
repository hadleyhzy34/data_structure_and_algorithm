#include <iostream>
#include <stack>
#include <string>
#include <vector>

void dfs(std::string s, int l, int r, int n, std::vector<std::string> &res) {
  if (l == n && r == n) {
    res.push_back(s);
    return;
  }
  if (l == r) {
    dfs(s + "(", l + 1, r, n, res);
  } else if (l > r) {
    dfs(s + ")", l, r + 1, n, res);
    if (l != n) {
      dfs(s + "(", l + 1, r, n, res);
    }
  }
}

std::vector<std::string> generateParenthese(int n) {
  int l = 0;
  int r = 0;
  std::vector<std::string> res;
  std::string curString = "";
  dfs(curString, l, r, n, res);
  return res;
}

std::vector<std::string> generatebracket(int n) {
  int l = 0;
  int r = 0;

  std::vector<std::vector<std::string>> dp;

  for (auto l = 0; l <= n; l++) {
    for (auto r = 0; r <= l; r++) {
      std::vector<std::string> res;
    }
  }
  std::vector<std::string> res;
  std::string curString = "";
  dfs(curString, l, r, n, res);
  return res;
}

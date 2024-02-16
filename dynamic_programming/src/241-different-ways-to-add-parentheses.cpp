/*
Given a string expression of numbers and operators, return all possible results
from computing all the different possible ways to group numbers and operators.
You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer
and the number of different results does not exceed 104.



Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
*/
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

void dfs(std::string expression, int idx, int curL, int curR,
         std::vector<int> &res) {}

std::vector<int> diffWaysToCompute(std::string expression) {
  int n = expression.length();
  std::vector<std::string> res;
  int nums = 0;
  for (auto e : expression) {
    if (e == '+' || e == '-' || e == '*' || e == '/') {
      nums++;
    }
  }
  std::vector<int> res;
}

void dfs(std::vector<std::string> &res, std::string expression, std::string cur,
         int idx, int num, int l, int r, int n) {
  if (expression[idx] == '+' || expression[idx] == '-' ||
      expression[idx] == '*' || expression[idx] == '/') {
    dfs(res, expression, cur + expression[idx], idx + 1, num + 1, l, r, n);
  }
  if (l == n && r == n) {
    res.push_back(expression);
    return;
  }
  std::string tmp = "";
  for (int i = 1; l + i <= n; i++) {
    tmp.push_back('(');
    dfs(res, expression, cur + tmp + expression[idx], idx + 1, num, l + 1, r,
        n);
  }
  tmp = "";
  for (int i = 1; r + i <= num; i++) {
    tmp.push_back(')');
    dfs(res, expression, cur + expression[idx] + tmp, idx + 1, num, l, r + 1,
        n);
  }
}

std::vector<int> diffWaysToCompute_v0(std::string expression) {
  int n = expression.length();

  int nums = 0;
  for (auto e : expression) {
    if (e == '+' || e == '-' || e == '*' || e == '/') {
      nums++;
    }
  }

  int dp[n][n];
  for (auto l = 1; l < n; l += 2) {
    for (auto i = 0; i < n; i += 2) {
      dp[i][l] =
    }
  }
}

class Solution1 {
public:
  vector<int> diffWaysToCompute(string expression) {
    std::stack<int> left;
    std::stack<char> sign;
    std::vector<int> res;
    int n = expression.length();
    std::vector<std::string> rt;
    int nums = 0;
    for (auto e : expression) {
      if (e == '+' || e == '-' || e == '*' || e == '/') {
        nums++;
      }
    }

    dfs(rt, expression, "", 0, 0, nums, 0, 0, n);
    return res;
  }

  void rec(std::vector<int> &res, int cur, std::string expression,
           std::stack<int> &left, std::stack<int> &right,
           std::stack<char> &sign, int idx, int num, int nums, int l, int r,
           int n) {
    if (expression[idx] == '+' || expression[idx] == '-' ||
        expression[idx] == '*' || expression[idx] == '/') {
      sign.push(expression[idx]);
      rec(res, cur, expression, left, right, sign, idx + 1, num + 1, nums, l, r,
          n);
      return;
    }
    if (idx == n && idx == n && l == nums && r == nums) {
      res.push_back(cur);
      return;
    }

    std::string tmp = "";
    if(expression.substr(idx,2)
    left.push(expression[idx]);

    for (int i = 1; l + i <= nums; i++) {
      tmp.push_back('(');
      dfs(res, expression, cur + tmp + expression[idx], idx + 1, num, nums,
          l + i, r, n);
    }
    tmp = "";
    for (int i = 1; r + i <= l; i++) {
      tmp.push_back(')');
      // std::cout<<cur+expression[idx]<<std::endl;
      dfs(res, expression, cur + expression[idx] + tmp, idx + 1, num, nums, l,
          r + i, n);
    }
  }
  void dfs(std::vector<std::string> &res, std::string expression,
           std::string cur, int idx, int num, int nums, int l, int r, int n) {
    if (expression[idx] == '+' || expression[idx] == '-' ||
        expression[idx] == '*' || expression[idx] == '/') {
      dfs(res, expression, cur + expression[idx], idx + 1, num + 1, nums, l, r,
          n);
      return;
    }
    if (idx == n && idx == n && l == nums && r == nums) {
      std::cout << cur << std::endl;
      res.push_back(cur);
      return;
    }
    std::string tmp = "";
    for (int i = 1; l + i <= nums; i++) {
      tmp.push_back('(');
      dfs(res, expression, cur + tmp + expression[idx], idx + 1, num, nums,
          l + i, r, n);
    }
    tmp = "";
    for (int i = 1; r + i <= l; i++) {
      tmp.push_back(')');
      // std::cout<<cur+expression[idx]<<std::endl;
      dfs(res, expression, cur + expression[idx] + tmp, idx + 1, num, nums, l,
          r + i, n);
    }
  }
};

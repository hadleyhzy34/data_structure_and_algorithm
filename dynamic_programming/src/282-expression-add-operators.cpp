#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<std::string> addOperators(std::string num, int target) {
    std::string cStr(num.length() + num.length() + 1, '0');
    cStr[0] = num[0];
    int curSum = 0;
    int lastVal = num[0] - '0';
    backTrack(num, cStr, 1, target, curSum, lastVal);
    return res;
  }
  void backTrack(std::string num, int ndx, std::string &cStr, int cdx,
                 int target, int curSum, int lastVal) {
    if (ndx == num.length()) {
      if (curSum + lastVal == target) {
        res.push_back(cStr);
      }
      return;
    }
    // current operator: +
    cStr[cdx++] = '+';
    cStr[cdx++] = num[ndx];
    backTrack(num, ndx + 1, cStr, cdx, target, curSum + lastVal,
              num[ndx] - '0');
    cdx -= 2;

    // current operator: -
    cStr[cdx++] = '-';
    cStr[cdx++] = num[ndx];
    backTrack(num, ndx + 1, cStr, cdx, target, curSum + lastVal,
              -(num[ndx] - '0'));
    cdx -= 2;

    // current operator: *
    cStr[cdx++] = '*';
    cStr[cdx++] = num[ndx];
    backTrack(num, ndx + 1, cStr, cdx, target, curSum,
              lastVal * (num[ndx] - '0'));
    cdx -= 2;

    if (num[ndx] != '0') {
      // current operator: *
      cStr[cdx++] = '*';
      cStr[cdx++] = num[ndx];
      backTrack(num, ndx + 1, cStr, cdx, target, curSum,
                lastVal / (num[ndx] - '0'));
      cdx -= 2;
    }
    std::cout << num << " " << cStr << " " << idx << " " << target << std::endl;
    return;
  }

private:
  std::vector<std::string> res;
};

int main() {
  Solution sol;

  // Test case 1: Basic test
  // std::vector<int> num1 = {1, 2, 3};
  std::string num1 = "123";
  int target1 = 6;
  std::vector<std::string> result1 = sol.addOperators(num1, target1);
  std::cout << "Test case 1 results:" << std::endl;
  for (const auto &expr : result1) {
    std::cout << expr << std::endl;
  }

  // Test case 2: Multiple solutions
  // std::vector<int> num2 = {2, 3, 4};
  std::string num2 = "234";
  int target2 = 10;
  std::vector<std::string> result2 = sol.addOperators(num2, target2);
  std::cout << "\nTest case 2 results:" << std::endl;
  for (const auto &expr : result2) {
    std::cout << expr << std::endl;
  }

  // Test case 3: No solution
  // std::vector<int> num3 = {1, 2};
  std::string num3 = "12";
  int target3 = 100;
  std::vector<std::string> result3 = sol.addOperators(num3, target3);
  std::cout << "\nTest case 3 results:" << std::endl;
  if (result3.empty()) {
    std::cout << "No solutions found" << std::endl;
  }

  return 0;
}

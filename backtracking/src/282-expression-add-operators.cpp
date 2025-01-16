#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<std::string> addOperators(std::string num, int target) {
    if (num.empty())
      return res;
    std::string cStr(num.length() * 2, '0');
    cStr[0] = num[0];
    bt(num, 1, cStr, 1, 0, 1, num[0] - '0', target);
    return res;
  }

private:
  std::vector<std::string> res;
  void bt(const std::string &num, int nIdx, std::string &cur, int cIdx,
          int addSum, int mulSum, long curNum, int target) {
    if (nIdx == num.length()) {
      if (addSum + mulSum * curNum == target) {
        res.push_back(cur.substr(0, cIdx));
      }
      return;
    }
    // concatenate to current number
    if (cur[cIdx - 1] != '0') {
      curNum =
          curNum * 10 + (curNum >= 0) ? (num[nIdx] - '0') : -(num[nIdx] - '0');
      if (curNum <= INT_MAX) {
        cur[cIdx] = num[nIdx];
        bt(num, nIdx + 1, cur, cIdx + 1, addSum, mulSum, curNum, target);
        cur[cIdx] = '0';
      }
      curNum /= 10;
    }
    // add '+' operator
    cur[cIdx] = '+';
    cur[cIdx + 1] = num[nIdx];
    bt(num, nIdx + 1, cur, cIdx + 2, addSum + mulSum * curNum, 1,
       num[nIdx] - '0', target);
    cur[cIdx] = '0';
    cur[cIdx + 1] = '0';

    // add '-' operator
    cur[cIdx] = '-';
    cur[cIdx + 1] = num[nIdx];
    bt(num, nIdx + 1, cur, cIdx + 2, addSum + mulSum * curNum, 1,
       -(num[nIdx] - '0'), target);
    cur[cIdx] = '0';
    cur[cIdx + 1] = '0';

    // add * operator
    cur[cIdx] = '*';
    cur[cIdx + 1] = num[nIdx];
    bt(num, nIdx + 1, cur, cIdx + 2, addSum, mulSum * curNum, num[nIdx] - '0',
       target);
    cur[cIdx] = '0';
    cur[cIdx + 1] = '0';
  }
};

// Test function to print results
void printResults(const std::vector<std::string> &results) {
  std::cout << "Results: [";
  for (size_t i = 0; i < results.size(); i++) {
    std::cout << "\"" << results[i] << "\"";
    if (i < results.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int main() {
  Solution solution;

  // Test Case 1
  std::cout << "Test Case 1:" << std::endl;
  std::string num1 = "123";
  int target1 = 6;
  std::cout << "Input: num = \"" << num1 << "\", target = " << target1
            << std::endl;
  auto results1 = solution.addOperators(num1, target1);
  printResults(results1);
  std::cout << std::endl;

  // Test Case 2
  std::cout << "Test Case 2:" << std::endl;
  std::string num2 = "232";
  int target2 = 8;
  std::cout << "Input: num = \"" << num2 << "\", target = " << target2
            << std::endl;
  auto results2 = solution.addOperators(num2, target2);
  printResults(results2);
  std::cout << std::endl;

  // Test Case 3
  std::cout << "Test Case 3:" << std::endl;
  std::string num3 = "105";
  int target3 = 5;
  std::cout << "Input: num = \"" << num3 << "\", target = " << target3
            << std::endl;
  auto results3 = solution.addOperators(num3, target3);
  printResults(results3);
  std::cout << std::endl;

  // Test Case 4
  std::cout << "Test Case 4:" << std::endl;
  std::string num4 = "00";
  int target4 = 0;
  std::cout << "Input: num = \"" << num4 << "\", target = " << target4
            << std::endl;
  auto results4 = solution.addOperators(num4, target4);
  printResults(results4);
  std::cout << std::endl;

  // Test Case 5
  std::cout << "Test Case 5:" << std::endl;
  std::string num5 = "3456237490";
  int target5 = 9191;
  std::cout << "Input: num = \"" << num5 << "\", target = " << target5
            << std::endl;
  auto results5 = solution.addOperators(num5, target5);
  printResults(results5);

  return 0;
}

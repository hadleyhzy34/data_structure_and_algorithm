#include <cctype>
#include <iostream>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>

class Solution {
public:
  std::string fractionAddition(std::string expression) {
    std::vector<int> numerator;
    std::vector<int> denominator;
    std::string res;
    for (int i = 0; i < expression.length(); i++) {
      bool pos = true;
      if (expression[i] == '+' || expression[i] == '-') {
        pos = expression[i++] == '+' ? true : false;
      }
      int num = 0;
      while (std::isdigit(expression[i])) {
        num = num * 10 + (expression[i++] - '0');
      }
      i++;
      int dem = 0;
      while (std::isdigit(expression[i])) {
        dem = dem * 10 + (expression[i++] - '0');
      }
      i--;
      num = (pos) ? num : -num;
      numerator.push_back(num);
      denominator.push_back(dem);
    }
    int gcdNum = lcm(denominator);
    // int gcdNum = 1;
    // for (int i = 0; i < denominator.size(); i++) {
    //   gcdNum = (gcdNum * denominator[i]) / std::gcd(gcdNum, denominator[i]);
    // }
    for (int i = 0; i < numerator.size(); i++) {
      int factor = std::abs(gcdNum / denominator[i]);
      numerator[i] = numerator[i] * factor;
    }
    int resNum = std::accumulate(numerator.begin(), numerator.end(), 0);
    if (resNum == 0) {
      gcdNum = 1;
    } else {
      int t = std::gcd(resNum, gcdNum);
      resNum = resNum / t;
      gcdNum = gcdNum / t;
    }
    return std::to_string(resNum) + "/" + std::to_string(gcdNum);
  }

private:
  int lcd(int a, int b) { return (a * b) / std::gcd(a, b); }
  int lcm(const std::vector<int> &nums) {
    return std::accumulate(nums.begin(), nums.end(), 1, lcd);
  }
  // int lcm(const std::vector<int> &nums) {
  //   return std::accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
  //     return (a * b) / std::gcd(a, b);
  //   });
  // }
  int gcd(int a, int b) {
    if (a == 0) {
      return b;
    } else if (b == 0) {
      return a;
    } else if (a > b) {
      return gcd(a - b, b);
    } else {
      return gcd(b - a, a);
    }
  }
};

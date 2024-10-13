/*Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all
the given inputs.



Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"


Constraints:

-231 <= numerator, denominator <= 231 - 1
denominator != 0*/

#include <iostream>
#include <string.h>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::string fractionToDecimal(int numerator, int denominator) {
    std::unordered_set<std::string> umap;
    std::string res = "";
    std::string cur;
    while (numerator / denominator == 0 || numerator % denominator != 0) {
      int tmp = numerator / denominator;
      cur += std::to_string(tmp);
      if (umap.count(cur)) {
        return "0," + cur;
      } else {
        umap.insert(cur);
      }
    }
    res = "0." + cur;
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }

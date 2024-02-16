/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::vector<std::string> sArray(numRows);
    int cnt = 0;

    for (auto i = 0; i < s.length(); i++) {
      if (cnt < numRows) {
        sArray[cnt].push_back(s[i]);
      } else {
        // std::cout<<i<<" "<<cnt<<" "<<numRows - 1 - (cnt - numRows +
        // 1)<<std::endl;
        sArray[numRows - 1 - (cnt - numRows + 1)].push_back(s[i]);
      }
      if (cnt < ((numRows - 2) * 2 + 2 - 1)) {
        cnt++;
      } else {
        cnt = 0;
      }
    }

    std::string res = "";
    for (auto s : sArray) {
      res += s;
    }
    return res;
  }
};

#include "src/392-is_subsequence.cpp"
#include <iostream>
#include <string.h>

int main(int argc, char *argv[]) {
  Solution test = Solution();
  std::string s = "abc";
  std::string t = "ahbgdc";
  /* test.isSubsequence(s, t); */
  std::cout << test.isSubsequence(s, t) << std::endl;

  return 0;
}

#include <iostream>

bool repeatedSubstringPattern(std::string s) {
  std::string pattern(s);
  s = s + s;
  int len = pattern.length();
  // number of letters that duplicated from beginning
  int next[len];
  next[0] = -1;
  for (int i = 1; i < len; i++) {
    int cur = next[i - 1];
    while (cur != -1 && pattern[i] != pattern[cur + 1]) {
      cur = next[next[i - 1]];
    }
    next[i] = (cur == -1 && pattern[i] != pattern[cur + 1]) ? -1 : cur + 1;
  }
  int j = 0;
  for (int i = 1; i < s.length(); i++) {
    if (pattern[j] == s[i]) {
      j++;
      if (j == s.length() && i != s.length() - 1) {
        return true;
      }
    } else {
      while (j != 0 && pattern[j] != s[i]) {
        j = next[j - 1] + 1;
      }
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  std::string s = "abab";
  std::cout << "test: " << repeatedSubstringPattern(s);
  return 0;
}

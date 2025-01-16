#include <iostream>
#include <string.h>

class Solution {
public:
  std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                       int maxWidth) {
    std::vector<std::string> res;
    int i = 0;
    int n = words.size();
    while (i < n) {
      int len = 0;
      int num = 0;
      int j = i;
      while (i < n && len + words[i].length() + (num + 1 - 1) < maxWidth) {
        len += words[i].length();
        i++;
        num++;
      }
      i--;
      std::string cur = "";
      if (i == n - 1) {
        while (j <= i) {
          cur += words[j++];
          cur += " ";
        }
        cur.pop_back();
        cur += std::string(maxWidth - cur.length(),' ');
      } else {
        while (j <= i) {
          cur += words[j];
          if (j < i) {
            std::cout<<maxWidth<<" "<<len<<" "<<num-1<<std::endl;
            cur += ((num==1)?" ":std::string((maxWidth - len) / (num - 1), ' '));
          } else {
            cur += ((num==1)?" ":std::string((maxWidth - len) % (num - 1),' '));
          }
          j++;
        }
      }
      i++;
      res.push_back(cur);
    }
    return res;
  }
};
int main() {
  Solution sol;
  std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  std::vector<std::string> result = sol.fullJustify(words, maxWidth);

  for (const std::string &line : result) {
    std::cout << "\"" << line << "\"" << std::endl;
  }

  return 0;
}

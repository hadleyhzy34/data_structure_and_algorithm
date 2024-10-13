#include <iostream>
#include <string.h>
#include <vector>
class Solution {
public:
  int characterReplacement(std::string s, int k) {
    int res = 1;
    std::unordered_map<char, int> umap;
    umap[s[0]]++;
    int pre = 0;
    char cur = s[0];
    int maxLen = 1;
    for (auto i = 1; i < s.length(); i++) {
      umap[s[i]]++;
      if (umap[s[i]] > maxLen) {
        cur = s[i];
      }
      if (s[i] == cur) {
        while (pre - 1 >= 0 && i - pre + 1 + 1 - umap[s[i]] >= k) {
          pre--;
          umap[s[pre]]++;
        }
        res = std::max(res, i - pre + 1);
      } else {
        if (maxLen >= i - pre + 1 - k) {
          res = std::max(res, i - pre + 1);
        } else {
          while (maxLen < i - pre + 1 - k) {
            umap[s[pre]]--;
            pre++;
            if (s[pre] == cur) {
              maxLen--;
            }
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  // case 1
  std::string s = "AABABBA";
  int k = 1;
  Solution solve = Solution();
  solve.characterReplacement(s, k);
  return 0;
}

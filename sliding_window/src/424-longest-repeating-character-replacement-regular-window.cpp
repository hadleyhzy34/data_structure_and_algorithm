#include <iostream>
#include <string.h>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    int res = 1;
    // count character frequency in current window
    std::unordered_map<char, int> umap;
    umap[s[0]]++;
    // left pointer of window
    int pre = 0;
    // most frequent character in current window
    char cur = s[0];
    // frequency of most frequent character
    int maxCnt = 1;
    for (auto i = 1; i < s.length(); i++) {
      umap[s[i]]++;
      // update maxCnt
      if (umap[s[i]] > maxCnt) {
        cur = s[i];
        maxCnt = umap[s[i]];
      }
      // if s[i] is the same as the most frequent character, then we could move
      // left pointer to left
      if (s[i] == cur) {
        while (pre - 1 >= 0 &&
               (s[i] == s[pre - 1] || i - pre + 1 + 1 - umap[s[i]] <= k)) {
          pre--;
          umap[s[pre]]++;
        }
        res = std::max(res, i - pre + 1);
      } else { // else we possibly move left pointer to right
        if (maxCnt >= i - pre + 1 - k) {
          res = std::max(res, i - pre + 1);
        } else {
          while (maxCnt < i - pre + 1 - k) {
            umap[s[pre]]--;
            if (s[pre] == cur) {
              maxCnt--;
            }
            pre++;
          }
        }
      }
    }
    return res;
  }
};

/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <iostream>
#include <string>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    int res = 1;
    std::unordered_map<char, int> umap;
    int pre = 0;
    char cur;
    for (int i = 0; i < s.length(); i++) {
      umap[s[i]]++;
      if (umap[cur] >= i - pre + 1 - k) {
        res = std::max(res, i - pre + 1);
      } else {
        if (umap[s[i]] >= i - pre + 1 - k) {
          cur = s[i];
          res = std::max(res, i - pre + 1);
        } else {
          while (pre <= i && umap[cur] < i - pre + 1 - k) {
            if (umap[s[pre]] >= i - pre + 1 - k) {
              cur = s[pre];
              break;
            }
            umap[s[++pre]]--;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end

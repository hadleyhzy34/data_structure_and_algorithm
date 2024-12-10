#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int findSubstringInWraproundString(std::string s) {
    int n = s.length();
    int res = 0;
    int dp_cur[26];
    int dp_max[26];
    memset(dp_cur, 0, sizeof(dp_cur));
    memset(dp_max, 0, sizeof(dp_max));
    dp_cur[s[0] - 'a'] = 1;
    dp_max[s[0] - 'a'] = 1;
    res = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] - s[i - 1] == 1 || s[i] - s[i - 1] == 'a' - 'z') {
        dp_cur[s[i] - 'a'] = dp_cur[s[i - 1] - 'a'] + 1;
        if (dp_max[s[i] - 'a'] < dp_cur[s[i] - 'a']) {
          res += dp_cur[s[i] - 'a'] - dp_max[s[i] - 'a'];
          dp_max[s[i] - 'a'] = dp_cur[s[i] - 'a'];
        }
      } else {
        if (dp_max[s[i] - 'a'] == 0) {
          res++;
          dp_max[s[i] - 'a'] = 1;
        }
        dp_cur[s[i] - 'a'] = 1;
      }
    }
    return res;
  }
};

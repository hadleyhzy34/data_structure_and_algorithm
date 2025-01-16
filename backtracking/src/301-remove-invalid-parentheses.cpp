#include <climits>
#include <iostream>
#include <string.h>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::string> removeInvalidParentheses(std::string s) {
    std::string cur = "";
    backTrack(s, 0, cur, 0, 0, 0);
    return res;
  }
  bool backTrack(const std::string &s, int sIdx, std::string &cur, int l, int r,
                 int moves) {
    if (sIdx == s.length()) {
      if (l == r) {
        if (moves < minMoves) {
          res = {cur};
          uset.insert(cur);
          minMoves = moves;
        } else if (moves == minMoves) {
          if (uset.find(cur) == uset.end()) {
            uset.insert(cur);
            res.push_back(cur);
          }
        }
        return true;
      } else {
        return false;
      }
    }

    if (l < r) {
      return false;
    }
    bool boolCur = false;

    if (s[sIdx] != '(' && s[sIdx] != ')') {
      cur.push_back(s[sIdx]);
      if (backTrack(s, sIdx + 1, cur, l, r, moves)) {
        boolCur = true;
      }
      cur.pop_back();
    } else {
      // keep current bracket
      cur.push_back(s[sIdx]);
      if (backTrack(s, sIdx + 1, cur, l + 1, r, moves)) {
        boolCur = true;
      }
      cur.pop_back();

      // remove current bracket
      if (backTrack(s, sIdx + 1, cur, l, r, moves + 1)) {
        boolCur = true;
      }
    }
    return boolCur;
  }

private:
  std::unordered_map<std::string, bool> umap;
  std::unordered_set<std::string> uset;
  int minMoves = INT_MAX;
  std::vector<std::string> res;
};

#include <iostream>
#include <unordered_set>
class Solution {
public:
  std::string removeDuplicateLetters(std::string s) {
    std::string res = "";
    std::unordered_map<char, std::queue<int>> sMap;
    std::unordered_set<char> resSet;
    for (auto i = 0; i < s.length(); i++) {
      sMap[s[i]].push(i);
    }
    for (auto i = 0; i < s.length(); i++) {
      if (resSet.count(s[i])) {
        continue;
      } else {
        if (!res.empty() && s[i] < res.back()) {
          while (!res.empty() && s[i] < res.back() &&
                 sMap[res.back()].size() >= 1) {
            resSet.erase(res.back());
            res.pop_back();
          }
          res.push_back(s[i]);
          sMap[s[i]].pop();
        } else {
          res.push_back(s[i]);
          sMap[s[i]].pop();
        }
        resSet.insert(s[i]);
      }
    }
    return res;
  }
};

int main() {
  // std::string s = "bcabc";
  std::string s = "bbcaac";
  Solution sol;
  sol.removeDuplicateLetters(s);
  return 0;
}

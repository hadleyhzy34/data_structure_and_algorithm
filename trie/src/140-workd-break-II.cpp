#include <iostream>

struct wordTree {
  bool isEnd;
  wordTree *children[26];
  wordTree() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class Solution {
public:
  wordTree *root = new wordTree();
  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string> &wordDict) {
    // build wordTree
    for (auto word : wordDict) {
      build(word, root);
    }
    int n = s.length();
    std::vector<int> visited(n, 0);
    res = dfs(s, root, 0, visited);
    return res;
  }

  void build(std::string word, wordTree *node) {
    for (auto i = 0; i < word.size(); i++) {
      int t = word[i] - 'a';
      if (!node->children[t]) {
        node->children[t] = new wordTree();
      }
      node = node->children[t];
    }
    node->isEnd = true;
  }

  std::vector<std::string> dfs(std::string s, wordTree *node, int idx,
                               std::vector<int> visited) {
    if (idx == s.length()) {
      return {};
    }
    if (visited[idx] == 1) {
      return {};
    }
    std::vector<std::string> cur;
    visited[idx] = 1;
    for (int i = idx; i < s.length(); i++) {
      int t = s[i] - 'a';
      if (!node->children[t]) {
        return cur;
      }
      node = node->children[t];
      if (node->isEnd) {
        std::vector<std::string> tmp = dfs(s, root, i + 1, visited);
        for (auto tmpp : tmp) {
          cur.push_back(s.substr(idx, i - idx + 1) + " " + tmpp);
        }
        if (i == s.length() - 1) {
          cur.push_back(s.substr(idx));
        }
      }
    }
    // visited[idx] = 0;
    return cur;
  }

private:
  std::vector<std::string> res;
};

int main() {
  Solution solution;

  // Test case
  std::string s = "catsanddog";
  std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};

  // Call the wordBreak method
  std::vector<std::string> result = solution.wordBreak(s, wordDict);

  // Output the results
  std::cout << "Possible sentences that can be formed:" << std::endl;
  for (const auto &sentence : result) {
    std::cout << sentence << std::endl;
  }

  return 0;
}

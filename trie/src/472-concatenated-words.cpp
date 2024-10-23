#include <iostream>
#include <string.h>
#include <vector>

struct wordTree {
  bool isEnd; // To mark the end of a word
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
  std::vector<std::string>
  findAllConcatenatedWordsInADict(std::vector<std::string> &words) {
    // // wordTree *root = new wordTree();
    // sort(words.begin(), words.end(),
    //      [&](const std::string &a, const std::string &b) {
    //        return a.size() < b.size();
    //      });

    // Build the trie
    for (const auto &word : words) {
    //   std::vector<int> visited(word.length(), 0);
    //   if (dfs(root, word, 0, visited)) {
    //     res.push_back(word);
    //   }
      buildTree(root, word);
    }

    // Check each word
    for (const auto &word : words) {
      std::vector<int> visited(word.length(), 0);
      if (dfs(word, 0, 0, visited)) {
        res.push_back(word);
      }
    }

    return res;
  }

private:
  std::vector<std::string> res;

  void buildTree(wordTree *node, const std::string &word) {
    wordTree *cur = node;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->children[idx]) {
        cur->children[idx] = new wordTree();
      }
      cur = cur->children[idx];
    }
    cur->isEnd = true; // Mark the end of the word
  }

  bool dfs(const std::string &word, int idx, int cnt, std::vector<int> &visited) {
    if (idx == word.length()) {
      if(cnt >= 2){
        return true;
      }else{
        return false;
      }
    }
    if (visited[idx] == 1) {
      return false;
    }
    visited[idx] = 1;

    wordTree* node = root;
    for (int i = idx; i < word.length(); ++i) {
      int j = word[i] - 'a';
      if (!node->children[j]) {
        return false;
      }
      node = node->children[j];
      if (node->isEnd) {
        if (dfs(word, i + 1, cnt + 1, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};

// int main() {
//   Solution solution;
//   std::vector<std::string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
//   std::vector<std::string> result = solution.findAllConcatenatedWordsInADict(words);
  
//   for (const std::string &word : result) {
//     std::cout << word << std::endl;
//   }

//   return 0;
// }
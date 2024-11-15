#include <iostream>
#include <string.h>
#include <vector>

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
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {
    for (auto word : words) {
      build(word, root);
    }
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        std::string cur = "";
        dfs(board, root, i, j, cur);
      }
    }
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

  void dfs(std::vector<std::vector<char>> &board, wordTree *node, int i, int j,
           std::string &cur) {
    if (board[i][j] == '#') {
      return;
    }
    int t = board[i][j] - 'a';
    if (!node->children[t]) {
      return;
    }
    char ch = board[i][j];
    board[i][j] = '#';

    cur += ch;

    if (node->children[t]->isEnd) {
      res.push_back(cur);
      node->children[t]->isEnd = false;
    }
    // left
    if (j >= 1) {
      dfs(board, node->children[t], i, j - 1, cur);
    }
    // right
    if (j < board[0].size() - 1) {
      dfs(board, node->children[t], i, j + 1, cur);
    }
    // up
    if (i >= 1) {
      dfs(board, node->children[t], i - 1, j, cur);
    }
    // down
    if (i < board.size() - 1) {
      dfs(board, node->children[t], i + 1, j, cur);
    }
    cur.pop_back();
    board[i][j] = ch;
    return;
  }

private:
  std::vector<std::string> res;
  // std::unordered_set<std::string> ust;
};

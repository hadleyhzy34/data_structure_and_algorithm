#include <iostream>
#include <string.h>
#include <unordered_set>
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
        dfs(board, root, i, j, "");
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
           std::string cur) {
    if (board[i][j] == '#') {
      return;
    }
    int t = board[i][j] - 'a';
    if (!node->children[t]) {
      return;
    }
    char ch = board[i][j];
    board[i][j] = '#';

    if (node->children[t]->isEnd) {
      res.push_back(cur + board[i][j]);
      node->children[t]->isEnd = false;
    }
    // left
    if (j >= 1) {
      dfs(board, node->children[t], i, j - 1, cur + board[i][j]);
    }
    // right
    if (j < board[0].size() - 1) {
      dfs(board, node->children[t], i, j + 1, cur + board[i][j]);
    }
    // up
    if (i >= 1) {
      dfs(board, node->children[t], i - 1, j, cur + board[i][j]);
    }
    // down
    if (i < board.size() - 1) {
      dfs(board, node->children[t], i + 1, j, cur + board[i][j]);
    }

    board[i][j] = ch;
    return;
  }

private:
  std::vector<std::string> res;
  // std::unordered_set<std::string> ust;
};

int main() {
  Solution solution;

  // Sample board
  // std::vector<std::vector<char>> board = {
  //     {'o', 'a', 'a', 'n'},
  //     {'e', 't', 'a', 'e'},
  //     {'i', 'h', 'k', 'r'},
  //     {'i', 'f', 'l', 'v'}
  // };

  // // Sample words
  // std::vector<std::string> words = {"oath", "pea", "eat", "rain"};

  std::vector<std::vector<char>> board = {{'a', 'b'}};
  std::vector<std::string> words = {"ba"};

  // Find words
  std::vector<std::string> foundWords = solution.findWords(board, words);

  // Print results
  std::cout << "Found words: ";
  for (const auto &word : foundWords) {
    std::cout << word << " ";
  }
  std::cout << std::endl;

  return 0;
}

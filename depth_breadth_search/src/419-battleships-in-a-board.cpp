#include <iostream>
#include <string.h>
#include <vector>

typedef std::vector<std::vector<int>> matrice;
matrice dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
  int countBattleships(std::vector<std::vector<char>> &board) {
    int res = 0;
    int m = board.size();
    int n = board[0].size();
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
      }
    }
  }

  void dfs(matrice &board, int i, int j, std::vector<int> dir) {
    board[i][j] = 'o';
  }
};

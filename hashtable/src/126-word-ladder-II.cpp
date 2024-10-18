#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  findLadders(std::string beginWord, std::string endWord,
              std::vector<std::string> &wordList) {
    int n = wordList.size();
    std::unordered_map<std::string, std::vector<std::string>> umap;
    std::unordered_map<std::string, int> visited;

    bool check = false;
    for (auto word : wordList) {
      for (int i = 0; i < word.length(); i++) {
        std::string tmp = word;
        tmp[i] = '*';
        umap[tmp].push_back(word);
        visited[word] = 0;
      }
      if (word == endWord) {
        check = true;
      }
    }

    if (!check) {
      return {};
    }

    // calculate depth
    std::queue<std::string> q;
    q.push(beginWord);
    if (visited.count(beginWord)) {
      visited[beginWord] = 1;
    }
    int steps = 1;
    while (!q.empty()) {
      int curLen = q.size();
      int i = 0;
      while (i < curLen) {
        std::string cString = q.front();
        q.pop();
        for (auto i = 0; i < cString.length(); i++) {
          std::string tmp = cString;
          tmp[i] = '*';
          if (umap.count(tmp)) {
            for (auto ct : umap[tmp]) {
              if (visited[ct] == 0) {
                if (ct == endWord) {
                  steps++;
                  break;
                }
                q.push(ct);
                visited[ct] = 1;
              }
            }
          }
        }
        i++;
      }
      steps++;
    }

    return {};
  }

  void backtrack(std::vector<std::vector<std::string>> &res,
                 std::vector<std::string> &path, int depth, int idx,
                 int curDepth, std::vector<int> &visited,
                 std::vector<std::string> wordList, std::string endWord) {
    std::string curString = wordList[idx];
  }
};

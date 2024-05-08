#include <iostream>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene,
                  std::vector<std::string> &bank) {
    for (int i = 0; i < bank.size(); i++) {
      umap[bank[i]] = i;
    }
    int n = bank.size();
    std::vector<int> visited(n, 0);
    return backtrack(startGene, endGene, bank, visited);
  }

  int backtrack(std::string startGene, std::string endGene,
                std::vector<std::string> &bank, std::vector<int> &visited) {
    if (startGene == endGene) {
      return 0;
    }

    int res = 1000;
    for (int i = 0; i < startGene.size(); i++) {
      char tmp = startGene[i];
      startGene[i] = 'A';
      if (umap.count(startGene) && visited[umap[startGene]] == 0) {
        visited[umap[startGene]] = 1;
        int steps = backtrack(startGene, endGene, bank, visited);
        res = std::min(res, steps + 1);
        visited[umap[startGene]] = 0;
      }
      startGene[i] = 'C';
      if (umap.count(startGene) && visited[umap[startGene]] == 0) {
        visited[umap[startGene]] = 1;
        int steps = backtrack(startGene, endGene, bank, visited);
        res = std::min(res, steps + 1);
        visited[umap[startGene]] = 0;
      }
      startGene[i] = 'G';
      if (umap.count(startGene) && visited[umap[startGene]] == 0) {
        visited[umap[startGene]] = 1;
        int steps = backtrack(startGene, endGene, bank, visited);
        res = std::min(res, steps + 1);
        visited[umap[startGene]] = 0;
      }
      startGene[i] = 'T';
      if (umap.count(startGene) && visited[umap[startGene]] == 0) {
        visited[umap[startGene]] = 1;
        int steps = backtrack(startGene, endGene, bank, visited);
        res = std::min(res, steps + 1);
        visited[umap[startGene]] = 0;
      }
      startGene[i] = tmp;
    }
    res = (res == 1000) ? res : -1;

    return res;
  }

private:
  std::unordered_map<std::string, int> umap;
  /* std::unordered_set<std::string> uset; */
};
/* class Solution { */
/* public: */
/*   int minMutation(std::string startGene, std::string endGene, */
/*                   std::vector<std::string> &bank) { */
/*     for (auto b : bank) { */
/*       umap[b] = -1; */
/*     } */
/*     return backtrack(startGene, endGene, bank, 0); */
/*   } */
/**/
/*   int backtrack(std::string startGene, std::string endGene, */
/*                 std::vector<std::string> &bank, int idx) { */
/*     if (startGene == endGene) { */
/*       return 0; */
/*     } */
/*     if (idx == endGene.length()) { */
/*       return -1; */
/*     } */
/*     if (umap.count(startGene) && umap[startGene] != -1) { */
/*       return umap[startGene]; */
/*     } */
/*     char tmp = startGene[idx]; */
/*     startGene[idx] = 'A'; */
/*     int a = backtrack(startGene, endGene, bank, idx + 1); */
/*     a = (a == -1) ? -1 : a + 1; */
/**/
/*     startGene[idx] = 'C'; */
/*     int c = 1 + backtrack(startGene, endGene, bank, idx + 1); */
/*     c = (c == -1) ? -1 : c + 1; */
/**/
/*     startGene[idx] = 'G'; */
/*     int g = 1 + backtrack(startGene, endGene, bank, idx + 1); */
/*     g = (g == -1) ? -1 : g + 1; */
/**/
/*     startGene[idx] = 'T'; */
/*     int t = 1 + backtrack(startGene, endGene, bank, idx + 1); */
/*     t = (t == -1) ? -1 : t + 1; */
/*     startGene[idx] = tmp; */
/**/
/*     int res = std::min(std::min(a, c), std::min(g, t)); */
/*     umap[startGene] = res; */
/*     return res; */
/*   } */
/**/
/* private: */
/*   std::unordered_map<std::string, int> umap; */
/* }; */

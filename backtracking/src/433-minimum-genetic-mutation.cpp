#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene,
                  std::vector<std::string> &bank) {
    for (auto b : bank) {
      umap[b] = -1;
    }
    return backtrack(startGene, endGene, bank, 0);
  }

  int backtrack(std::string startGene, std::string endGene,
                std::vector<std::string> &bank, int idx) {
    if (startGene == endGene) {
      return 0;
    }
    if (idx == endGene.length()) {
      return -1;
    }
    if (umap.count(startGene) && umap[startGene] != -1) {
      return umap[startGene];
    }
    char tmp = startGene[idx];
    startGene[idx] = 'A';
    int a = backtrack(startGene, endGene, bank, idx + 1);
    a = (a == -1) ? -1 : a + 1;

    startGene[idx] = 'C';
    int c = 1 + backtrack(startGene, endGene, bank, idx + 1);
    c = (c == -1) ? -1 : c + 1;

    startGene[idx] = 'G';
    int g = 1 + backtrack(startGene, endGene, bank, idx + 1);
    g = (g == -1) ? -1 : g + 1;

    startGene[idx] = 'T';
    int t = 1 + backtrack(startGene, endGene, bank, idx + 1);
    t = (t == -1) ? -1 : t + 1;
    startGene[idx] = tmp;

    int res = std::min(std::min(a, c), std::min(g, t));
    umap[startGene] = res;
    return res;
  }

private:
  std::unordered_map<std::string, int> umap;
};

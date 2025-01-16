#include <iostream>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// union based approach
typedef std::vector<std::vector<double>> matrice;

class Solution {
public:
  std::vector<double>
  calcEquation(std::vector<std::vector<std::string>> &equations,
               std::vector<double> &values,
               std::vector<std::vector<std::string>> &queries) {
    int i = 0;
    for (auto eq : equations) {
      for (auto s : eq) {
        if (um.find(s) == um.end()) {
          um[s] = (i++);
        }
      }
    }
    int n = um.size();
    // std::unordered_map<int, std::pair<int, double>> edge;
    std::vector<std::vector<double>> edge(n, std::vector<int>(n));
    for (int i = 0; i < values.size(); i++) {
      int nom = um[equations[i][0]];
      int dem = um[equations[i][1]];
      edge[nom][dem] = values[i];
      edge[dem][nom] = 1 / values[i];
    }
    std::vector<double> res;
    for (int i = 0; i < queries.size(); i++) {
      if (um.find(queries[i][0]) == um.end() ||
          um.find(queries[i][1]) == um.end()) {
        res.push_back(-1);
      } else {
        int nom = um[queries[i][0]];
        int dem = um[queries[i][1]];
        std::vector<int> unvisited(n, 0);
        res.push_back(dfs(edge, nom, dem, unvisited));
      }
    }
    return res;
  }
  double unionFind(matrice &edge, int nom, int dem,
                   std::unordered_map<int, double> nM,
                   std::unordered_map<int, double> dM,
                   std::vector<int> unvisited) {
    for (auto &[nkey, nval] : nM) {
      if (dM.count(nkey)) {
        edge[nom][dem] = nM[dem] * dM[dem];
        return edge[nom][dem];
      } else {
        if (unvisited[nkey] == 0) {
        }
      }
    }
  }
  double dfs(matrice &edge, int nom, int dem, std::vector<int> unvisited) {
    if (edge[nom][dem] != -1) {
      return edge[nom][dem];
    }
    for (int i = 0; i < edge[nom].size(); i++) {
      if (edge[nom][i] != -1 && unvisited[i] == 0) {
        unvisited[i] = 1;
        double cur = dfs(edge, i, dem, unvisited);
        unvisited[i] = 0;
        if (cur != -1) {
          // std::cout<<nom<<" "<<i<<" "<<edge[nom][i]<<" "<<cur<<std::endl;
          return edge[nom][i] * cur;
        } else {
          continue;
        }
      }
    }
    return -1;
  }

private:
  // string and its index
  std::unordered_map<std::string, int> um;
};

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

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
    matrice edge(n, std::vector<double>(n, -1));
    for (int i = 0; i < values.size(); i++) {
      int nom = um[equations[i][0]];
      int dem = um[equations[i][1]];
      std::cout<<edge.size()<<" "<<edge[nom].size()<<" "<<nom<<" "<<dem<<std::endl;
      edge[nom][dem] = values[i];
      edge[dem][nom] = 1 / values[i];
    }
    std::vector<double> res;
    for (int i = 0; i < queries.size(); i++) {
      int nom = um[queries[i][0]];
      int dem = um[queries[i][1]];
      std::vector<int> unvisited(n, 0);
      res.push_back(dfs(edge, nom, dem, unvisited));
    }
    return res;
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


int main() {
  Solution sol;

  std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}};
  std::vector<double> values = {2.0, 3.0};
  std::vector<std::vector<std::string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}};

  std::vector<double> results = sol.calcEquation(equations, values, queries);

  for (double result : results) {
    std::cout << result << " ";
  }
  std::cout << std::endl;

  return 0;
}

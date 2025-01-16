#include <iostream>
#include <numeric>

class Solution {
public:
  bool makesquare(std::vector<int> &matchsticks) {
    std::sort(matchsticks.rbegin(), matchsticks.rend());
    int totalLength =
        std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalLength % 4) {
      return false;
    }
    int Len = totalLength / 4;
    std::vector<int> edges(4, 0);
    return bt(matchsticks, Len, 0, edges);
  }

  bool bt(const std::vector<int> &matchsticks, int len, int idx,
          std::vector<int> &edges) {
    if (idx == matchsticks.size()) {
      // if (edges[0] == edges[1] == edges[2] == edges[3] == len) {
      //   return true;
      // } else {
      //   std::cout<<edges[0]<<" "<<edges[1]<<" "<<edges[2]<<" "<<edges[3]<<" "<<len<<std::endl;
      //   return false;
      // }
      return (edges[0]==len)&&(edges[1]==len)&&(edges[2]==len)&&(edges[3]==len);
    }
    for (int i = 0; i < 4; i++) {
      if (edges[i] + matchsticks[idx] <= len) {
        edges[i] += matchsticks[idx];
        if (bt(matchsticks, len, idx + 1, edges)) {
          return true;
        }
        edges[i] -= matchsticks[idx];
      }
    }
    return false;
  }
};


class Solution1 {
public:
  bool makesquare(std::vector<int> &matchsticks) {
    std::sort(matchsticks.begin(), matchsticks.end());
    int totalLength =
        std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalLength % 4) {
      return false;
    }
    int Len = totalLength / 4;
    int largest = matchsticks.back();
    std::vector<int> visited(matchsticks.size(), 0);
    return backTrack(matchsticks, totalLength, 0, 0, visited, 0);
  }

  bool backTrack(const std::vector<int> matchsticks, int len, int edx,
                 int curEdge, std::vector<int> &visited, int vCnt) {
    if (edx == 4) {
      if (vCnt == matchsticks.size()) {
        return true;
      } else {
        return false;
      }
    }

    for (int i = 0; i < matchsticks.size(); i++) {
      if (visited[i] == false) {
        visited[i] = true;
        if (curEdge + matchsticks[i] < len) {
          if (backTrack(matchsticks, len, edx, curEdge + matchsticks[i],
                        visited, vCnt + 1)) {
            return true;
          }
        } else if (curEdge + matchsticks[i] == len) {
          if (backTrack(matchsticks, len, edx + 1, 0, visited, vCnt + 1)) {
            return true;
          }
        }
        visited[i] = false;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  std::vector<int> matchSticks = {1, 1, 2, 2, 2};
  sol.makesquare(matchSticks);
}

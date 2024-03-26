#include <climits>
#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int shortestWordDistance(std::vector<std::string> &wordsDict,
                           std::string word1, std::string word2) {
    int i = -1;
    int j = -1;
    int dist = INT_MAX;
    for (auto k = 0; k < wordsDict.size(); k++) {
      if (word1 == wordsDict[k]) {
        if (word1 == word2) {
          if (i > j) {
            j = k;
          } else {
            i = k;
          }
        } else {
          i = k;
        }
        if (j != -1) {
          dist = std::min(dist, std::abs(i - j));
        }
      } else if (word2 == wordsDict[k]) {
        j = k;
        if (i != -1) {
          dist = std::min(dist, j - i);
        }
      }
    }
    return dist;
  }
};

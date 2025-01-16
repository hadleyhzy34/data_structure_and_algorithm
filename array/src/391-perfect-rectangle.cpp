#include <climits>
#include <iostream>
#include <istream>
#include <map>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  void fourCorners(std::vector<int> &rectangle) {
    std::string lb =
        std::to_string(rectangle[0]) + ":" + std::to_string(rectangle[1]);
    std::string rb =
        std::to_string(rectangle[2]) + ":" + std::to_string(rectangle[1]);
    std::string lt =
        std::to_string(rectangle[0]) + ":" + std::to_string(rectangle[2]);
    std::string rt =
        std::to_string(rectangle[2]) + ":" + std::to_string(rectangle[2]);

    if (umap.count(lb)) {
      umap.erase(lb);
    } else {
      umap.insert(lb);
    }
    if (umap.count(rb)) {
      umap.erase(rb);
    } else {
      umap.insert(rb);
    }
    if (umap.count(lt)) {
      umap.erase(lt);
    } else {
      umap.insert(lt);
    }
    if (umap.count(rt)) {
      umap.erase(rt);
    } else {
      umap.insert(rt);
    }
  }
  bool isRectangleCover(std::vector<std ::vector<int>> &rectangles) {
    int x1 = INT_MAX;
    int x2 = INT_MIN;
    int y1 = INT_MAX;
    int y2 = INT_MIN;

    long totalArea = 0;
    for (auto rectangle : rectangles) {
      x1 = std::min(x1, rectangle[0]);
      y1 = std::min(y1, rectangle[1]);
      x2 = std::max(x2, rectangle[2]);
      y2 = std::max(y2, rectangle[3]);
      totalArea += (long)(rectangle[3] - rectangle[1]) *
                   (long)(rectangle[2] - rectangle[0]);
      fourCorners(rectangle);
    }
    if ((long)(y2 - y1) * (long)(x2 - x1) != totalArea) {
      return false;
    }
    std::string lt = std::to_string(x1) + ":" + std::to_string(y2);
    std::string rt = std::to_string(x2) + ":" + std::to_string(y2);
    std::string lb = std::to_string(x1) + ":" + std::to_string(y1);
    std::string rb = std::to_string(x2) + ":" + std::to_string(y1);

    if (umap.size() != 4) {
      return false;
    }
    if (!umap.count(lt)) {
      return false;
    }
    if (!umap.count(rt)) {
      return false;
    }
    if (!umap.count(lb)) {
      return false;
    }
    if (!umap.count(rb)) {
      return false;
    }
    return true;
  }

private:
  std::unordered_set<std::string> umap;
};

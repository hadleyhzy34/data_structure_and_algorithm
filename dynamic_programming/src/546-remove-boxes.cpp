#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution{
public:
  int removeBoxes(std::vector<int> &boxes) {
    int n = boxes.size();
    //build state from l to r with k number of boxes same as boxes[l] on the left

  }
};

class Solution1 {
public:
  int removeBoxes(std::vector<int> &boxes) {
    int n = boxes.size();
    std::string state = std::string(n, '0');
    std::string rest = std::string(n, '0');
    return bt(boxes, state, rest);
  }

  int backTrack(std::string cur){
    if(cur.empty()){
      return 0;
    }
    if(umap.find(cur)!=umap.end()){
      return umap[cur];
    }
    int curMax = INT_MIN;

    for(int i = 0; i < cur.length(); i++){
      std::string tmp = cur;
      int t = 1;
      int l = i - 1;
      int r = i + 1;

      while (l >= 0 && (cur[i] == cur[l])) {
        t++;
        l--;
      }
      while (r <= cur.length() && (cur[i] == cur[r])) {
        t++;
        r++;
      }
      std::string l = (l>=0)?cur.substr(0,l):"";
      std::string r = (r<cur.length())?cur.substr(r):"";
      cur = l + r;
      curMax = std::max(curMax, t * t + bt(cur));
      cur = tmp;
    }
    umap[cur] = curMax;
    return curMax;
  }
  int bt(std::vector<int> &boxes, std::string &state, std::string &rest) {
    if (rest.empty()) {
      return 0;
    }
    if (umap.find(rest) != umap.end()) {
      return umap[rest];
    }
    int curMax = INT_MIN;
    int rIdx = 0;
    // std::string lr = "";
    // std::string rr = rest;
    for (int i = 0; i < boxes.size(); i++) {
      if (state[i] == '1') {
        continue;
      } else {
        std::string prevState = state;
        std::string prevRest = rest;
        state[i] = '1';
        int t = 1;
        // std::string lr = rest.substr(0, rIdx);
        // std::string rr = (rIdx < rest.size() - 1) ? rest.substr(rIdx + 1) :
        // "";
        int l = i - 1;
        int r = i + 1;
        // remove nearby if its the same
        int lr = rIdx - 1;
        int rr = rIdx + 1;
        while (lr >= 0 && (rest[rIdx] == rest[lr])) {
          t++;
          lr--;
          while (state[l] == '1') {
            l--;
          }
          state[l] = '1';
        }
        while (rr <= rest.size() && (rest[rIdx] == rest[rr])) {
          t++;
          rr++;
          while (state[r] == '1') {
            r++;
          }
          state[r] = '1';
        }
        rest = rest.substr(0, lr) + rest.substr(rr);
        curMax = std::max(curMax, t * t + bt(boxes, state, rest));
        state = prevState;
        rest = prevRest;
        rIdx++;
      }
    }
    umap[rest] = curMax;
    return curMax;
  }

private:
  std::unordered_map<std::string, int> umap;
};

int main() {
  Solution sol;
  std::vector<int> arr = {1, 1, 1};
  sol.removeBoxes(arr);
}

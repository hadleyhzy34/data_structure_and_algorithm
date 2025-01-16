#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCoins(std::vector<int> &nums) {
    int n = nums.size();
    std::string cur = "";
    for (auto num : nums) {
      cur += std::to_string(num);
      cur += ",";
    }
    cur.pop_back();
    return backTrack(cur);
  }
  int backTrack(std::string &cur) {
    if (cur.empty()) {
      return 0;
    }
    if (umap.find(cur) != umap.end()) {
      return umap[cur];
    }

    int prev = 1;
    int num = 1;
    int nxt = 0;

    std::string l = "";


    int i = 0;
    while(cur[i]!=','&&i<cur.length()){  
      nxt = nxt*10 + (cur[i]-'0');
      i++;
    }
    i++;

    int tmp = 0;
    std::string t = "";
    for (; i < cur.length(); i++) {
      prev = num;
      num = nxt;
      nxt = 0;

      std::string r = (i<cur.length()-1)?cur.substr(i):"";
      
      t = "";
      while(cur[i] != ',' && i < cur.length()){
        t += cur[i];
        nxt = nxt*10 + (cur[i]-'0');
        i++;
      }

      cur = l + r;
      l = (l.empty())?l : l + ",";
      l += t;

      nxt = (nxt==0)?1:nxt;

      int val = prev * num * nxt;

      tmp = std::max(tmp, backTrack(cur) + val);
    }

    tmp = std::max(tmp, backTrack(cur) + num * prev * 1);
    umap[cur] = tmp;
    return tmp;
  }

private:
  int res;
  std::unordered_map<std::string, int> umap;
};

int main() {
    Solution sol;
    vector<int> nums = {9,76};
    int result = sol.maxCoins(nums);
    cout << "Test 1 (Expected: 167) => " << result << endl;
    // assert(result == 167);
    return 0;
}
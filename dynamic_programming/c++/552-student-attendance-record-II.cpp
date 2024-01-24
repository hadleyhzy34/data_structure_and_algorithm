#include <iostream>
#include <vector>

class Solution {
public:
  int checkRecord(int n) {
    std::vector<long> oA_oL = {1};
    std::vector<long> oA_oneL = {1};
    std::vector<long> oA_twoL = {0};
    std::vector<long> wA_oL = {1};
    std::vector<long> wA_oneL = {0};
    std::vector<long> wA_twoL = {0};

    static constexpr int MOD = 1000000007;
    for (auto i = 2; i <= n; i++) {
      oA_oL.push_back((oA_oL[i - 2] + oA_oneL[i - 2] + oA_twoL[i - 2]) % MOD);
      oA_oneL.push_back(oA_oL[i - 2] % MOD);
      oA_twoL.push_back(oA_oneL[i - 2] % MOD);
      wA_oL.push_back((oA_oL[i - 2] + oA_oneL[i - 2] + oA_twoL[i - 2] +
                       wA_oL[i - 2] + wA_oneL[i - 2] + wA_twoL[i - 2]) %
                      MOD);
      wA_oneL.push_back(wA_oL[i - 2] % MOD);
      wA_twoL.push_back(wA_oneL[i - 2] % MOD);
      // std::cout<<oA_oL[i - 1]<<" "<<oA_oneL[i - 1]<<" "<<oA_twoL[i - 1]<<"
      // "<<wA_oL[i - 1]<<" "<<wA_oneL[i - 1]<<" "<<wA_twoL[i - 1]<<std::endl;
    }

    return (oA_oL.back() + oA_oneL.back() + oA_twoL.back() + wA_oL.back() +
            wA_oneL.back() + wA_twoL.back()) %
           MOD;
  }
  Solution();
  Solution(Solution &&) = default;
  Solution(const Solution &) = default;
  Solution &operator=(Solution &&) = default;
  Solution &operator=(const Solution &) = default;
  ~Solution();

private:
};

Solution::Solution() {}

Solution::~Solution() {}

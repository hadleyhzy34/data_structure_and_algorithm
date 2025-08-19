#include <iostream>
#include <vector>

class Solution {
public:
  int findNumberOfLIS(std::vector<int> &nums) {
    // longest lis ending at current position
    int n = nums.size();
    int lis[n];
    memset(lis, 0, sizeof(lis));
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int longest = 1;
    int res = 1;
    dp[0] = 1;
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
      dp[i] = 1;
      lis[i] = 1;
      if (lis[i] == longest) {
        res++;
      }
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (lis[i] == lis[j] + 1) {
            if (lis[i] == longest) {
              res += dp[j];
            }
            dp[i] += dp[j];
          } else if (lis[i] < lis[j] + 1) {
            lis[i] = lis[j] + 1;
            if (lis[i] > longest) {
              longest = lis[i];
              res = dp[j];
            } else if (lis[i] == longest) {
              res += dp[j];
            }
            dp[i] = dp[j];
          }
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;

  std::vector<int> nums0 = {2, 6, 4, 23, 7, 2, 8, 9, 2, 5, 1};
  int result0 = solution.findNumberOfLIS(nums0);
  std::cout << "Number of LIS for nums1: " << result0 << std::endl;

  std::vector<int> nums1 = {1, 3, 5, 4, 7};
  int result1 = solution.findNumberOfLIS(nums1);
  std::cout << "Number of LIS for nums1: " << result1 << std::endl;

  std::vector<int> nums2 = {2, 2, 2, 2, 2};
  int result2 = solution.findNumberOfLIS(nums2);
  std::cout << "Number of LIS for nums2: " << result2 << std::endl;

  return 0;
}

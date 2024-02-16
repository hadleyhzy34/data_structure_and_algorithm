/*
Given a set of distinct positive integers nums, return the largest subset answer
such that every pair (answer[i], answer[j]) of elements in this subset
satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

#include <iostream>
#include <string.h>
#include <vector>

int subset(std::vector<int> nums) {
  int res = 1;
  int n = nums.size();
  int dp[n];
  dp[0] = 1;
  for (auto i = 0; i < n; i++) {
    dp[i] = 1;
    for (auto j = 0; j < i; j++) {
      if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    res = std::max(res, dp[i]);
  }
  return res;
}

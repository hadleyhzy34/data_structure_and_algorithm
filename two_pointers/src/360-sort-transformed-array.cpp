/* 360. Sort Transformed Array */
/* Given a sorted integer array nums and three integers a, b and c, apply a
 * quadratic function of the form f(x) = ax2 + bx + c to each element nums[i] in
 * the array, and return the array in a sorted order. */
/**/
/**/
/**/
/* Example 1: */
/**/
/* Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5 */
/* Output: [3,9,15,33] */
/* Example 2: */
/**/
/* Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5 */
/* Output: [-23,-5,1,7] */
/**/
/**/
/* Constraints: */
/**/
/* 1 <= nums.length <= 200 */
/* -100 <= nums[i], a, b, c <= 100 */
/* nums is sorted in ascending order. */
/**/
/**/
/* Follow up: Could you solve it in O(n) time? */

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> sortTransformedArray(std::vector<int> &nums, int a, int b,
                                        int c) {
    // int n = nums.size();
    float opt = -(float)(b) / (2 * a);
    std::vector<int> res;

    int mid = 0;
    for (auto i = 0; i < nums.size(); i++) {
      if (nums[i] - opt == 0) {
        mid = i;
        break;
      } else if (nums[i] < opt) {
        mid++;
      } else if (nums[i] > opt) {
        break;
      }
    }

    int l = mid - 1;
    int r = mid;
    while (l >= 0 || r < nums.size()) {
      if (l < 0) {
        res.push_back(nums[r]);
        r++;
      } else if (r >= nums.size()) {
        res.push_back(nums[l]);
        l--;
      } else if (std::fabs(nums[l] - opt) < std::fabs(nums[r] - opt)) {
        res.push_back(nums[l]);
        l--;
      } else {
        res.push_back(nums[r]);
        r++;
      }
    }

    if (a < 0) {
      std::reverse(res.begin(), res.end());
    }

    for (auto i = 0; i < res.size(); i++) {
      res[i] = a * (res[i] * res[i]) + b * res[i] + c;
      // res.push_back(tmp);
    }

    return res;
  }
};

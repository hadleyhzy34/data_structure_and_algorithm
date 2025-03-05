#include <climits>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int l = 0, r = n1;

    while (l <= r) {
      // number of elements on left side, since partitionX could zero or all, so
      // r must be n1
      int partitionX = l + (r - l) / 2;
      // make sure left part of elements are equal or one size larger than right
      // part
      int partitionY = (n1 + n2 + 1) / 2 - partitionX;

      // handling cases where all elements of nums1 are on left or right side of
      // nums2
      int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
      int minRightX = (partitionX == n1) ? INT_MAX : nums1[partitionX];

      int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
      int minRightY = (partitionY == n2) ? INT_MAX : nums2[partitionY];

      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((n1 + n2) & 1) {
          return std::max(maxLeftX, maxLeftY);
        } else {
          return (std::max(maxLeftX, maxLeftY) +
                  std::min(minRightX, minRightY)) /
                 2.0;
        }
      } else if (maxLeftX > minRightY) {
        r = partitionX - 1;
      } else {
        l = partitionX + 1;
      }
    }
    return 0.0;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  std::vector<int> nums1 = {1, 3, 5};
  std::vector<int> nums2 = {2, 4, 6};
  sol.findMedianSortedArrays(nums1, nums2);
  return 0;
}

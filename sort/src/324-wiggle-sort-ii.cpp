class Solution {
public:
  void wiggleSort(std::vector<int> &nums) {
    int n = nums.size();
    int ndx = (n % 2 == 0) ? n / 2 - 1 : n / 2;
    int med = findMedian(nums, ndx, 0, n - 1);
    std::cout<<med<<std::endl;

    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      if (nums[nIndex(j, n)] > med) {
        // note that i<=j, nums[nIndex(i,n)] <= med
        std::swap(nums[nIndex(j, n)], nums[nIndex(i, n)]);
        i++;
        j++;
      } else if (nums[nIndex(j, n)] < med) {
        std::swap(nums[nIndex(j, n)], nums[nIndex(k, n)]);
        k--;
      } else {
        j++;
      }
    }
  }
  // find median using quickselect
  int findMedian(std::vector<int> &nums, int idx, int l, int r) {
    if (l == r) {
      return nums[l];
    }
    int n = nums.size();
    int rdx = rand() % (r - l + 1) + l;
    int pivot = nums[rdx];
    std::swap(nums[rdx], nums[r]);
    // partition
    int sdx = l;
    for (int i = l; i < r; i++) {
      if (nums[i] <= pivot) {
        std::swap(nums[i], nums[sdx++]);
      }
    }
    std::swap(nums[sdx], nums[r]);
    if (sdx == idx) {
      return pivot;
    } else if (sdx < idx) {
      return findMedian(nums, idx, sdx, r);
    } else {
      return findMedian(nums, idx, l, sdx -1);
    }
  }
  int nIndex(int i, int n) { return (1 + 2 * i) % (n | 1); }
};
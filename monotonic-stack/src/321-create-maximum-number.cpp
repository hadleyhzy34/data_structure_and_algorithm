#include <iostream>
#include <tuple>

class Solution {
public:
  std::vector<int> maxNumber(std::vector<int> &nums1, std::vector<int> &nums2,
                             int k) {
    std::string cur = "";
    std::vector<int> res;
    int n1 = nums1.size();
    int n2 = nums2.size();
    std::vector<int> digit1;
    std::vector<int> digit2;
    for (int i = 0; i <= n1; i++) {
      int j = k - i;
      removeDigits(nums1, n1 - i, digit1);
      removeDigits(nums2, n2 - j, digit2);
      std::string tmp = mergeSort(digit1, digit2);

      if (cur < tmp) {
        cur = tmp;
      }
    }
    for (int i = 0; i < cur.length(); i++) {
      res.push_back(cur[i] - '0');
    }
    return res;
  }

  void removeDigits(std::vector<int> &nums, int k, std::vector<int> &digits) {}

  std::string mergeSort(std::vector<int> &digit1, std::vector<int> &digit2) {
    std::string cur = "";
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = digit1.size();
    int n2 = digit2.size();
    std::vector<int> mergedDigits;
    while (i < digit1.size() || j < digit2.size()) {
      if (j >= n2 || digit1[i] >= digit2[j]) {
        mergedDigits[k++] = digit1[i];
        cur.push_back(digit1[i++] + '0');
      } else {
        mergedDigits[k++] = digit2[j++];
        cur.push_back(digit2[j] + '0');
      }
    }
    return cur;
  }

private:
};

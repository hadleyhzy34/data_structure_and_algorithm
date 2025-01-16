#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> &newInterval) {
    std::vector<std::vector<int>> res;
    int n = intervals.size();

    bool check = false;
    for (int i = 0; i < n; i++) {
      if (intervals[i][0] < newInterval[0]) {
        res.push_back(intervals[i]);
      } else {
        if (!check) {
          if (res.empty() || newInterval[0] > res.back()[1]) {
            res.push_back(newInterval);
          } else {
            res.back()[1] = std::max(res.back()[1], newInterval[1]);
          }
          check = true;
        }

        if (res.empty() || intervals[i][0] > res.back()[1]) {
          res.push_back(intervals[i]);
        } else {
          res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        }
      }
    }
    if (!check) {
      if (res.empty() || newInterval[0] > res.back()[1]) {
        res.push_back(newInterval);
      } else {
        res.back()[1] = std::max(res.back()[1], newInterval[1]);
      }
    }
    return res;
  }
};

// Main function to run the test
int main() {
  // Test case 1
  // vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
  // vector<int> newInterval1 = {2, 5};
  // cout << "Test Case 1:" << endl;
  // vector<vector<int>> result1 = insert(intervals1, newInterval1);
  // printIntervals(result1); // Expected: {{1, 5}, {6, 9}}

  // Test case 2
  vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval2 = {4, 8};
  cout << "\nTest Case 2:" << endl;
  vector<vector<int>> result2 = insert(intervals2, newInterval2);
  // printIntervals(result2); // Expected: {{1, 2}, {3, 10}, {12, 16}}

  // Test case 3 (new interval comes before all)
  vector<vector<int>> intervals3 = {{3, 5}, {6, 9}};
  vector<int> newInterval3 = {0, 1};
  cout << "\nTest Case 3:" << endl;
  vector<vector<int>> result3 = insert(intervals3, newInterval3);
  // printIntervals(result3); // Expected: {{0, 1}, {3, 5}, {6, 9}}

  // Test case 4 (new interval comes after all)
  vector<vector<int>> intervals4 = {{1, 2}, {3, 5}, {6, 7}};
  vector<int> newInterval4 = {8, 10};
  cout << "\nTest Case 4:" << endl;
  vector<vector<int>> result4 = insert(intervals4, newInterval4);
  // printIntervals(result4); // Expected: {{1, 2}, {3, 5}, {6, 7}, {8, 10}}

  // Test case 5 (new interval overlaps with all)
  vector<vector<int>> intervals5 = {{2, 3}, {4, 6}, {7, 9}};
  vector<int> newInterval5 = {1, 10};
  cout << "\nTest Case 5:" << endl;
  vector<vector<int>> result5 = insert(intervals5, newInterval5);
  // printIntervals(result5); // Expected: {{1, 10}}

  return 0;
}

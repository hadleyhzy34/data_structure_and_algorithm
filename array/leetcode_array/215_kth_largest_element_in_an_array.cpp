#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};

//max heap using priority queue
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

//min heap using priority queue
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        for(int i=nums.size();i!=k;i--){
            pq.pop();
        }
        return pq.top();
    }
};

//nth element
class Solution4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
        return nums[k-1];
    }
};

//partial sort
class Solution5 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin()+k,nums.end(),greater<int>());
        return nums[k-1];
    }
};
//
//  46_permutations.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    void permutations(vector<int>& nums, int l){
            for(int i=l;i<nums.size();i++){
                swap(nums[l],nums[i]);
                permutations(nums, l+1);
                if(l==nums.size()-1){
                    res.push_back(nums);
                }
                swap(nums[l],nums[i]);
            }
        }
    //recursion function could also be written like this, note that it passes by value so that num will not be changed after swap operation
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            // if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
        
        vector<vector<int>> permute(vector<int>& nums) {
            permutations(nums, 0);
            return res;
        }
    private:
        vector<vector<int>>res;
};


//input[1,2,3]
//output:
//pass by value:
//[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//pass by reference:
//[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]

//abcde
//pass by value at index=0:a->b,b->c,c->d,d->e
//pass by reference at index=0:a->b,a->c,a->d,a->e

//permutation, pass by value
class Solution1 {
public:
    void recursion(vector<int> num, int l, vector<vector<int> > &res) {
        if (l == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int i = l; i < num.size(); i++) {
            swap(num[i], num[l]);
            recursion(num, l+1, res);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};

//permutation, pass by reference
class Solution2 {
public:
    void recursion(vector<int> &num, int l, vector<vector<int> > &res) {
        if (l == num.size()-1) {
            res.push_back(num);
            return;
        }
        
        for (int i = l; i < num.size(); i++) {
            swap(num[i], num[l]);
            recursion(num, l+1, res);
            swap(num[i], num[l]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};

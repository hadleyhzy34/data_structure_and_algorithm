#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> generate(int rows){
        vector<vector<int>> res = {};
        res.push_back({1});
        for(int i=1;i<rows;i++){
            vector<int> temp = {};
            temp.push_back(1);
            int size = res[res.size()-1].size();
            if(size>1){
                for(int j=0;j<size-1;j++){
                    temp.push_back(res[size-1][j]+res[size-1][j+1]);
                }
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};

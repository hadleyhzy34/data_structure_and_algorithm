//
//  531_lonely_pixel_1.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<vector<int>> h(picture.size(),vector<int>(picture[0].size(),0));
        vector<vector<int>> v(picture.size(),vector<int>(picture[0].size(),0));
        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[i].size();j++){
                int count=0;
                if(picture[i][j]=='B')count++;
                if(i==0){
                    v[i][j]=count;
                }else{
                    v[i][j]=v[i-1][j]+count;
                }
                if(j==0){
                    h[i][j]=count;
                }else{
                    h[i][j]=h[i][j-1]+count;
                }
            }
        }
        
        int res=0;
        for(int i=picture.size()-1;i>=0;i--){
            for(int j=picture[i].size()-1;j>=0;j--){
                if(i<picture.size()-1)v[i][j]=v[i+1][j];
                if(j<picture[i].size()-1)h[i][j]=h[i][j+1];
                if(picture[i][j]=='B'&&v[i][j]==1&&h[i][j]==1)res++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int>col(picture[0].size());

        for(int j=0;j<picture[0].size();j++){
            int count=0;
            for(int i=0;i<picture.size();i++){
                if(picture[i][j]=='B')count++;
            }
            col[j]=count;
        }
        
        int res=0;
        for(int i=0;i<picture.size();i++){
            int count=0;
            for(int j=0;j<picture[i].size();j++){
                if(picture[i][j]=='B')count+=col[j];
            }
            if(count==2)res++;
        }
        return res;
    }
};

//
//  551_student_attendance_record_i.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<char, int>dict;
        for(int i=0;i<s.size();i++){
            dict[s[i]]++;
            if(s[i]=='A'&&dict[s[i]]>1)return false;
            if(s[i]=='L'&&dict[s[i]]==2){
                if(i<s.size()-1&&s[i+1]=='L'){
                    return false;
                }
            }
            if(s[i]!='L')dict['L']=0;
        }
        return true;
    }
};

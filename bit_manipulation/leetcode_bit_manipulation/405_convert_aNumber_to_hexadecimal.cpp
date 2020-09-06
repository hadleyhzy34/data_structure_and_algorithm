//
//  405_convert_aNumber_to_hexadecimal.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string output;
        int flag=0;
        if(num<0){
            flag++;
            num=-num;
        }
        int count=0;
        while(num>pow(16,count)){count++;}
        count--;
        while(count>=0){
            char temp;
            if(num/pow(16,count)>9){
                temp='a'+pow(16,count)-10;
            }else{
                temp=pow(16,count)+'0';
            }
            output=output+temp;
            int t=pow(16,count);
            num=num%t;
            count--;
        }
        return output;
    }
};

class Solution2 {
public:
    string toHex(int num) {
        string output;
        bool flag=false;
        for(int i=1;i<=8;i++){
            int temp=num>>(32-i*4)&15;
            if(temp){
                flag=true;
            }
            if(flag){
                char t;
                if(temp>9){
                    t='a'+temp-10;
                }else{
                    t=temp+'0';
                }
                output=output+t;
            }
        }
        if(output.empty()){return "0";}else{
            return output;
        }
    }
};


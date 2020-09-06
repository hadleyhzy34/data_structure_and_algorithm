//
//  223_rectangle_area.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

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
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
//        long v=0;
//        if(E>=C||A>=H){
//            v=0;
//        }else if(A<E&&E<C&&C<G){
//            v=C-E;
//        }else if(E<A&&A<G&&G<C){
//            v=G-A;
//        }else if(A<E&&G<C){
//            v=G-E;
//        }else if(E<A&&C<G){
//            v=C-A;
//        }
        
        long a=A,b=B,c=C,d=D,e=E,f=F,g=G,h=H;
//        long v=min(min(C-E,G-A),min(C-A,G-E));
        long verti=min(min(c-e,g-a),min(c-a,g-e));
        long hori=min(min(h-b,d-f),min(d-b,h-f));
        if(verti>0&&hori>0){
            return (c-a)*(d-b)+(g-e)*(h-f)-verti*hori;
        }else{
            return (c-a)*(d-b)+(g-e)*(h-f);
        }
    }
};

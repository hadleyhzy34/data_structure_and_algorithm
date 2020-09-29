//
//  main.cpp
//  leetcode_array
//
//  Created by Hadley on 16.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "1_two_sum.cpp"
#include "26_remove_duplicates_from_sorted_array.cpp"
#include "27_remove_element.cpp"
#include "35_search_insert_position.cpp"
#include "53_Maximum_subarray.cpp"
#include "88_merge_sorted_array.cpp"
#include "118_Pascal_triangle.cpp"
#include "119_pascal_triangle_2.cpp"
#include "121_best_time_buy_and_sell_stock.cpp"
#include "219_contains_duplicate_2.cpp"
#include "414_third_maximum_number.cpp"
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    //test1
//    Solution1 test1;
    vector<int> test={1,1,3,3,5,5,7,7,7};
    vector<int> data={1,1,1};
    vector<int> data1={0,0,1,1,1,2,2,3,3,4};
    vector<int> data2={1};
    vector<int> data3={3,2,2,3};
    vector<int> data4={1,3,5,6};
    vector<int> data5={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> data6={1,2,3,0,0,0};
    vector<int> data7={2,5,6};
    vector<int> data8={99,99};
    vector<int> data9={1,1,2};
//    for(int x:test1.twoSum(test, 8)){
//        cout<<x<<endl;
//    }
//    Solution26_3 test2;
//    cout<<test2.removeDuplicates(data1)<<endl;
//    for(int x:data1){
//        cout<<x<<endl;
//    }
    
//    Solution27 test1;
//    cout<<test1.removeElement(data3, 3)<<endl;
//    for(int x:data3){
//        cout<<x<<endl;
//    }
        
//    Solution35 test1;
//    cout<<test1.searchInsert(data4, 7);
    
//    Solution53 test1;
//    cout<<test1.maxSubArray(data5);
    
    //Test 88
//    Solution88 test1;
//    test1.merge(data6, 3, data7, 3);
    
    //test119
//    Solution119 test1;
//
//    for(int x:test1.getRow(3)){
//            cout<<x<<endl;
//        }
    
    //test121
    //test219
//    Solution219 test1;
//    test1.containsNearbyDuplicate(data8, 2);
    //test414
//    Solution414 test1;
//    cout<<test1.thirdMax(data9);
    
    //test min_element
//    vector<int> num={1,1};
//    auto min=*min_element(num.begin(), num.end());
//    cout<<min<<endl;
    
    return 0;
}

//
//  main.cpp
//  LeetCode_stack
//
//  Created by Hadley on 21.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "71_simplify_path.cpp"
#include "331_verify_preorder_serialization.cpp"
#include "402_remove_k_digits.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    Solution71 test1;
//    test1.simplifyPath("/a//b////c/d//././/..");
    
//    Solution331 test1;
//    test1.isValidSerialization("#,8,8,3,#,#,0,4,4,#,#,#,#,#,3,7,8,#,7,#,#");
    
    Solution402 test1;
    test1.removeKdigits("1432219", 3);
    return 0;
}

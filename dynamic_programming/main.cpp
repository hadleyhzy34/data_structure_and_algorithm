#include <stdio.h>
#include "src/174-dungeon-game.cpp"
#include "src/120-triangle.cpp"
#include "src/576-out-of-boundary-paths.cpp"
#include <vector>

int main(){
//    std::vector<std::vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
//    int res = calculateMinimumHP(dungeon);
    // std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    // int res = minimumTotal(triangle);
    int res = findPaths(2,2,2,0,0);
}
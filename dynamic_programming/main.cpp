#include <iostream>
#include <stdio.h>
/* #include "src/174-dungeon-game.cpp" */
/* #include "src/120-triangle.cpp" */
/* #include "src/576-out-of-boundary-paths.cpp" */
/* #include "src/313.Super Ugly Number.cpp" */
/* #include "src/292-nim-game.cpp" */
#include "src/131-palindrome-partitioning.cpp"
#include "src/576-out-of-boundary-paths.cpp"
#include <string>
#include <vector>

int main() {
  //    std::vector<std::vector<int>> dungeon =
  //    {{-2,-3,3},{-5,-10,1},{10,30,-5}}; int res =
  //    calculateMinimumHP(dungeon);
  // std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
  // int res = minimumTotal(triangle);
  // int res = findPaths(2,2,2,0,0);

  // 313.super ugly number
  //  std::vector<int> primes = {2,7,13,19};
  //  int res = nthSuperUglyNumber(12,primes);

  // nim game
  /* if(1348820612<INT_MAX){ */
  /*     std::cout<<"check"; */
  /* }else{ */
  /*     std::cout<<"large"; */
  /* } */
  /* int res = canWinNim(1348820612); */

  /* // palindrome partitioning */
  /* std::string s = "aab"; */
  /**/
  /* Solution sol = Solution(); */
  /* std::vector<std::vector<std::string>> res = sol.checkPartition(s); */
  /* sol.checkPartition(s); */

  // boundary check
  int m = 2;
  int n = 2;
  int startRow = 0;
  int startCol = 0;
  int maxMove = 2;
  BoundaryCheck solu = BoundaryCheck();
  int num = solu.findPaths(m, n, maxMove, startRow, startCol);
}

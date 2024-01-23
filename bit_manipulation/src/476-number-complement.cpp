class Solution {
public:
  int findComplement(int num) {
    int res = ~num;
    int count = 0;
    while (num) {
      num >>= 1;
      count = (count <<= 1) | 1;
    }
    return res & count;
  }

private:
};

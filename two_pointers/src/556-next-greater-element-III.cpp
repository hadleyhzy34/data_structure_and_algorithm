#include <iostream>
#include <string.h>
#include <vector>

class NextElement {
public:
  int nextGreaterElement(int n) {
    std::cout << n << std::endl;
    std::vector<int> num;
    bool check = true;
    int pre = 0;
    int cnt = 0;

    while (n) {
      num.push_back(n % 10);
      // std::cout<<pre<<" loop: "<<n%10<<std::endl;
      if (pre > (n % 10)) {
        check = false;
        cnt = num.size() - 1;
        // std::cout<<cnt<<" "<<num.size()<<std::endl;
        break;
      }

      pre = n % 10;
      n /= 10;
    }
    std::cout << cnt << " " << num.size() << std::endl;
    if (check) {
      return -1;
    }
    long res = 0;
    std::cout << "current cnt element: " << num[cnt] << " " << num[cnt - 1]
              << std::endl;
    std::swap(num[cnt], num[cnt - 1]);
    for (int i = num.size() - 1; i >= 0; --i) {
      res = res * 10 + num[i];
      std::cout << res << " " << i << " " << num[i] << std::endl;
    }
    std::cout << "current res: " << res << std::endl;
    res = 0;
    std::sort(num.rbegin(), num.rbegin() + cnt);
    for (int i = num.size() - 1; i >= 0; i--) {
      res = res * 10 + num[i];
    }
    return (res > INT_MAX) ? -1 : res;
  }
};

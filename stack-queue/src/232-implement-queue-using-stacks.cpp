#include <iostream>
#include <queue>
#include <stack>

class MySecondQueue {
public:
  MySecondQueue() { int size = 0; }

  void push(int x) {
    whi
        // s1.push(x);
        while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
    s1.push(x);

    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    // std::swap(s1, s2);
  }

  int pop() {
    int tmp = s2.top();
    s2.pop();
    return tmp;
  }

  int peek() { return s2.top(); }

  bool empty() { return s2.empty(); }

private:
  std::stack<int> s;
  int size;
};

class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    // s1.push(x);
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
    s1.push(x);

    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    // std::swap(s1, s2);
  }

  int pop() {
    int tmp = s2.top();
    s2.pop();
    return tmp;
  }

  int peek() { return s2.top(); }

  bool empty() { return s2.empty(); }

private:
  std::stack<int> s1;
  std::stack<int> s2;
};

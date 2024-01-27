#include <iostream>
#include <queue>
#include <stack>

class MyStack {
public:
  MyStack() {
    // std::queue<int> q;
  }

  void push(int x) { this->q.push(x); }

  int pop() {
    int cnt = 0;
    int n = this->q.size();
    while (cnt < n - 1) {
      int tmp = this->q.front();
      this->q.pop();
      cnt++;
      q.push(tmp);
    }
    int tmp = q.front();
    q.pop();
    return tmp;
    // return this->q.front();
  }

  int top() { return this->q.back(); }

  bool empty() { return this->q.empty(); }

private:
  std::queue<int> q;
};

class StackDoubleQ {
public:
  MyStack() {
    // std::queue<int> q;
  }

  void push(int x) {
    this->q2.push(x);
    while (!this->q1.empty()) {
      this->q2.push(q1.front());
      q1.pop();
    }
    std::swap(this->q1, this->q2);
  }

  int pop() { this->q2.pop(); }

  int top() { return this->q.front(); }

  bool empty() { return this->q.empty(); }

private:
  std::queue<int> q1;
  std::queue<int> q2;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

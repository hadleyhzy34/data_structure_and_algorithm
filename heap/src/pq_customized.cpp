#include <queue>
#include <vector>
#include <iostream>

struct Task {
  int priority;
  std::string description;

  // Constructor for easy initialization
  Task(int p, std::string desc)
      : priority(p), description(std::move(desc)) {}

  // bool operator<(const Task &other)const {
  //   return priority < other.priority;
  // }

  bool operator<(const Task &other)const{
    return priority < other.priority;
  }
};

template <typename T> void printPQ(std::priority_queue<T> &pq) {
  while(!pq.empty()){
    std::cout<<pq.top()<<" ";
    pq.pop();
  }
  std::cout<<std::endl;
}

int main() {
  // Default: max-heap (largest element has highest priority)
  std::priority_queue<int> pq;
  pq.push(3);
  pq.push(1);
  pq.push(4); // Top element: 4

  printPQ(pq);

  std::priority_queue<Task> pq0;

  pq0.emplace(3,"h priority");
  pq0.emplace(1,"low priority");
  pq0.emplace(2,"m priority");

  // Process tasks in priority order
  while (!pq0.empty()) {
      const Task& task = pq0.top();
      std::cout << "Processing: " << task.description 
                << " (Priority: " << task.priority << ")\n";
      pq0.pop();
  }

  return 0;
}

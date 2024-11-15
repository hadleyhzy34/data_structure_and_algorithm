#include "src/460-lfu-cache.cpp"
#include <iostream>

int main() {
  // Initialize LFUCache with a capacity of 2
  LFUCache cache(2);

  // Test inserting and accessing cache elements
  cache.put(1, 1); // Cache stores {1=1}
  cache.put(2, 2); // Cache stores {1=1, 2=2}
  std::cout << cache.get(1)
            << "\n"; // Returns 1 and increases frequency of key 1
  cache.put(3,
            3); // Removes key 2 (least frequently used) and stores {1=1, 3=3}
  std::cout << cache.get(2) << "\n"; // Returns -1 (not found)
  std::cout << cache.get(3) << "\n"; // Returns 3
  cache.put(4, 4);                   // Removes key 1 and stores {3=3, 4=4}
  std::cout << cache.get(1) << "\n"; // Returns -1 (not found)
  std::cout << cache.get(3) << "\n"; // Returns 3
  std::cout << cache.get(4) << "\n"; // Returns 4

  return 0;
}

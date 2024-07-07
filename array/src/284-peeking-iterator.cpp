#include <iostream>
#include <string.h>
#include <vector>

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const std::vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const std::vector<int> &nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (pre < 0) {
      pre = Iterator.next();
    }
    return pre;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    pre = Iterator.next();
    return pre;
  }

  bool hasNext() const { return Iterator.hasNext(); }

private:
  int pre = -1;
};

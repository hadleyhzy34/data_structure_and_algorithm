#include <iostream>
#include <set>
#include <cassert>

bool setsAreEqual(const std::set<int>& set1, const std::set<int>& set2) {
    return set1 == set2;
}

int main() {
    // Test case 1: Insert elements into the set
    std::set<int> mySet;
    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(7);

    assert(setsAreEqual(mySet, {3, 5, 7}));

    // Test case 2: Erase an element from the set
    mySet.erase(5);

    assert(setsAreEqual(mySet, {3, 7}));

    // Test case 3: Find an element in the set
    auto it = mySet.find(7);
    assert(it != mySet.end() && *it == 7);

    // Test case 4: Check if a non-existent element is found
    it = mySet.find(5);
    assert(it == mySet.end());

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}

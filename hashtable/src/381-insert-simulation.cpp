#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class RandomizedCollection {
private:
    std::vector<int> st;
    std::unordered_map<int, int> umap;
    std::unordered_map<int, std::set<int> > uvec;
    int len = 0;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool exist = umap.count(val);
        umap[val]++;
        if (st.size() == len) {
            st.push_back(val);
        } else {
            st[len] = val;
        }
        uvec[val].insert(len);
        len++;
        return !exist;
    }

bool remove(int val) {
    if (umap.count(val) && umap[val] > 0) {
        umap[val]--;  // Decrement the count
        if (umap[val] == 0) {
            umap.erase(val);  // Erase the key
            // Use find() to check if the key has been fully deleted
            if (umap.find(val) == umap.end()) {
                std::cout << "key has been deleted" << std::endl;
            } else {
                std::cout << "key has not been deleted yet" << std::endl;
            }
        }

        // Handle updating uvec and st
        int idx = *uvec[val].rbegin();
        std::swap(st[idx], st[len - 1]);
        uvec[val].erase(std::prev(uvec[val].end()));

        if (idx != len - 1) {
            uvec[st[idx]].erase(len - 1);
            uvec[st[idx]].insert(idx);
        }

        len--;

        return true;
    }
    return false;
}

    int getRandom() {
        if (len == 0) {
            throw std::runtime_error("Collection is empty");
        }
        int r = rand() % len;
        return st[r];
    }
};

int main() {
    RandomizedCollection solution = RandomizedCollection();
    solution.insert(10);
    solution.insert(10);
    solution.insert(20);
    solution.insert(20);
    solution.insert(30);
    solution.insert(30);
    solution.remove(10);
    solution.remove(20);
    solution.remove(20);
    solution.remove(10);
    solution.remove(30);
    solution.insert(40);
    solution.remove(30);
    solution.remove(30);

    for (int i = 0; i < 10; ++i) {
        std::cout << solution.getRandom() << std::endl;
    }
    return 0;
}
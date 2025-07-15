#include <functional> // For std::hash
#include <iostream>
#include <list>
#include <stdexcept> // For std::out_of_range
#include <string>    // For Key type
#include <vector>

// A simple Key-Value pair structure
struct KeyValuePair {
  std::string key;
  int value; // Assume int for simplicity
};

// Our bucket definition (a list of KeyValuePair)
typedef std::list<KeyValuePair> Bucket;

// Our simple hash table class
class MyHashTable {
private:
  std::vector<Bucket> buckets;
  std::size_t num_buckets;
  std::hash<std::string> hasher; // For hashing string keys

  // Helper to get the bucket index for a given key
  std::size_t get_bucket_index(const std::string &key) const {
    return hasher(key) % num_buckets;
  }

public:
  // Constructor: specify number of buckets
  MyHashTable(std::size_t size) : num_buckets(size), buckets(size) {
    if (size == 0) {
      throw std::invalid_argument("Number of buckets cannot be zero.");
    }
  }

  // --- Insert/Update Operation ---
  void add_or_update(const std::string &key, int value) {
    std::size_t index = get_bucket_index(key);
    Bucket &current_bucket =
        buckets[index]; // Get reference to the list in the bucket

    // Search for the key within this bucket's list
    for (auto &pair : current_bucket) {
      if (pair.key == key) {
        // Key found, update value
        pair.value = value;
        std::cout << "Updated key '" << key << "' to value " << value
                  << " in bucket " << index << "\n";
        return;
      }
    }

    // Key not found in this bucket's list, add new pair
    current_bucket.push_back({key, value});
    std::cout << "Added new key '" << key << "' with value " << value
              << " to bucket " << index << "\n";
  }

  // --- Lookup Operation ---
  int get(const std::string &key) const {
    std::size_t index = get_bucket_index(key);
    const Bucket &current_bucket =
        buckets[index]; // Get const reference to the list

    // Search for the key within this bucket's list
    for (const auto &pair : current_bucket) {
      if (pair.key == key) {
        std::cout << "Found key '" << key << "' with value " << pair.value
                  << " in bucket " << index << "\n";
        return pair.value;
      }
    }

    // Key not found
    std::cout << "Key '" << key << "' not found.\n";
    // throw std::out_of_range("Key not found in hash table");
  }

  // --- Remove Operation ---
  void remove(const std::string &key) {
    std::size_t index = get_bucket_index(key);
    Bucket &current_bucket = buckets[index]; // Get reference to the list

    // Use list's erase-remove idiom (or find and then erase)
    auto it = current_bucket.begin();
    while (it != current_bucket.end()) {
      if (it->key == key) {
        it = current_bucket.erase(it); // Erase returns iterator to next element
        std::cout << "Removed key '" << key << "' from bucket " << index
                  << "\n";
        return;
      } else {
        ++it;
      }
    }
    std::cout << "Attempted to remove key '" << key
              << "', but it was not found.\n";
  }

  // For demonstration: print bucket contents
  void print_buckets() const {
    std::cout << "\n--- Current Hash Table State ---\n";
    for (std::size_t i = 0; i < num_buckets; ++i) {
      std::cout << "Bucket " << i << ": ";
      if (buckets[i].empty()) {
        std::cout << "(empty)\n";
      } else {
        for (const auto &pair : buckets[i]) {
          std::cout << "('" << pair.key << "', " << pair.value << ") ";
        }
        std::cout << "\n";
      }
    }
    std::cout << "--------------------------------\n";
  }
};

int main() {
  MyHashTable myTable(5); // 5 buckets for demonstration

  myTable.add_or_update("apple", 10);
  myTable.add_or_update("banana", 20);
  myTable.add_or_update("cherry", 30);
  myTable.add_or_update("date", 40); // Will likely collide with another key
  myTable.add_or_update("elderberry", 50); // Another potential collision

  myTable.print_buckets();

  myTable.get("banana");
  myTable.get("grape"); // Not found

  myTable.add_or_update("apple", 100); // Update existing
  myTable.print_buckets();

  myTable.remove("cherry");
  myTable.remove("nonexistent");
  myTable.print_buckets();

  try {
    myTable.get("cherry"); // Should throw
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }

  return 0;
}

#include <iostream>
#include <unordered_map>

class Solution1 {
public:
  std::vector<std::vector<int>>
  palindromePairs(std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); i++) {
      umap[words[i]] = i;
    }
    for (auto word : words) {
      // empty prefix
      std::string prefix = "";
      std::string suffix = word;
      if (checkPalindrome(word)) {
        if (umap.count(prefix) && umap[prefix] != umap[word]) {
          res.push_back({umap[word], umap[prefix]});
        }
      }
      // prefix
      for (int i = 0; i < word.length(); i++) {
        std::string prefix = word.substr(0, i - 0 + 1);
        std::string suffix = word.substr(i + 1);
        std::reverse(suffix.begin(), suffix.end());
        if (checkPalindrome(prefix)) {
          if (umap.count(suffix) && umap[word] != umap[suffix]) {
            res.push_back({umap[suffix], umap[word]});
          }
        }
        std::reverse(suffix.begin(), suffix.end());
        if (checkPalindrome(suffix)) {
          std::reverse(prefix.begin(), prefix.end());
          if (umap.count(prefix) && umap[word] != umap[prefix]) {
            res.push_back({umap[word], umap[prefix]});
          }
        }
      }
    }
    return res;
  }
  bool checkPalindrome(std::string word) {
    int n = word.length();
    for (int i = 0; i < n / 2; i++) {
      if (word[i] == word[n - 1 - i]) {
        continue;
        ;
      } else {
        return false;
      }
    }
    return true;
  };

private:
  std::vector<std::vector<int>> res;
  std::unordered_map<std::string, int> umap;
};
class Solution {
public:
  std::vector<std::vector<int>>
  palindromePairs(std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); i++) {
      umap[words[i]] = i;
    }
    for (auto word : words) {
      // empty prefix
      std::string prefix = "";
      std::string suffix = word;
      if (checkPalindrome(word)) {
        if (umap.count(prefix) && umap[prefix] != umap[word]) {
          res.push_back({umap[word], umap[prefix]});
        }
      }
      // prefix
      for (int i = 0; i < word.length(); i++) {
        std::string prefix = word.substr(0, i - 0 + 1);
        std::string suffix = word.substr(i + 1);
        std::reverse(suffix.begin(), suffix.end());
        if (checkPalindrome(prefix)) {
          if (umap.count(suffix) && umap[word] != umap[suffix]) {
            res.push_back({umap[suffix], umap[word]});
          }
        }
        std::reverse(suffix.begin(), suffix.end());
        if (checkPalindrome(suffix)) {
          std::reverse(prefix.begin(), prefix.end());
          if (umap.count(prefix) && umap[word] != umap[prefix]) {
            res.push_back({umap[word], umap[prefix]});
          }
        }
      }
    }
    return res;
  }
  bool checkPalindrome(std::string word) {
    int n = word.length();
    for (int i = 0; i < n / 2; i++) {
      if (word[i] == word[n - 1 - i]) {
        continue;
        ;
      } else {
        return false;
      }
    }
    return true;
  };

private:
  std::vector<std::vector<int>> res;
  std::unordered_map<std::string, int> umap;
};

int main() {
  Solution solution;

  // // Test case 1
  // std::vector<std::string> words1 = {"bat", "tab", "cat"};
  // std::vector<std::vector<int>> result1 = solution.palindromePairs(words1);

  // std::cout << "Palindrome pairs for words {\"bat\", \"tab\", \"cat\"}:\n";
  // for (const auto &pair : result1) {
  //   std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
  // }
  // std::cout << "\n\n";

  // Test case 2
  std::vector<std::string> words2 = {"abcd", "dcba", "lls", "s", "sssll"};
  std::vector<std::vector<int>> result2 = solution.palindromePairs(words2);

  std::cout << "Palindrome pairs for words {\"abcd\", \"dcba\", \"lls\", "
               "\"s\", \"sssll\"}:\n";
  for (const auto &pair : result2) {
    std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
  }
  std::cout << "\n";

  return 0;
}

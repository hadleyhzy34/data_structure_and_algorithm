
/*A transformation sequence from word beginWord to word endWord using a
dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be
in wordList. sk == endWord Given two words, beginWord and endWord, and a
dictionary wordList, return the number of words in the shortest transformation
sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: One shortest
transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5
words long. Example 2:

Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is not
in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.*/

#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int oneDiff(std::string a, std::string b) {
    int cnt = 0;
    for (auto i = 0; i < a.length(); i++) {
      if (a[i] == b[i]) {
        continue;
      } else {
        cnt++;
      }
    }
    return cnt;
  }
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList) {
    int n = wordList.size();
    std::vector<int> be(n, 2);
    std::vector<int> en(n, 2);
    for (int i = 0; i < wordList.size(); i++) {
      if (oneDiff(wordList[i], beginWord) == 1) {
        be[i] = 1;
      }
      if (oneDiff(wordList[i], endWord) == 1) {
        en[i] = 1;
      }
    }
    int depth = 0;
    while (depth <= n) {
      for (auto i = 0; i < n; i++) {
      }
    }
    return depth;
  }
};

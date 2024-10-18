
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList) {
    int n = wordList.size();
    std::unordered_map<std::string, std::vector<std::string>> umap;
    std::unordered_map<std::string, int> visited;

    bool check = false;
    for (auto word : wordList) {
      for (int i = 0; i < word.length(); i++) {
        std::string tmp = word;
        tmp[i] = '*';
        umap[tmp].push_back(word);
        visited[word] = 0;
      }
      if (word == endWord) {
        check = true;
      }
    }

    if (!check) {
      return 0;
    }
    // std::unordered_set<std::string> us;
    // for (int i = 0; i < endWord.length(); i++) {
    //   std::string t = endWord;
    //   t[i] = '*';
    //   us.insert(t);
    // }
    std::queue<std::string> q;
    q.push(beginWord);
    if (visited.count(beginWord)) {
      visited[beginWord] = 1;
    }
    int steps = 1;
    while (!q.empty()) {
      int curLen = q.size();
      int i = 0;
      while (i < curLen) {
        std::string cString = q.front();
        q.pop();
        for (auto i = 0; i < cString.length(); i++) {
          std::string tmp = cString;
          tmp[i] = '*';
          //   if (us.count(tmp)) {
          //     return steps+1;
          //   }
          if (umap.count(tmp)) {
            for (auto ct : umap[tmp]) {
              if (visited[ct] == 0) {
                if (ct == endWord) {
                  return steps + 1;
                }
                q.push(ct);
                // std::cout<<steps<<" "<<cString<<" "<<ct<<std::endl;
                visited[ct] = 1;
              }
            }
          }
        }
        i++;
      }
      steps++;
    }
    return 0;
  }
};

//using hashmap and two pointers
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++){
        	map[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i=0,j=0,min_diff=INT_MAX;
        while(i<map[word1].size()&&j<map[word2].size()){
            min_diff=min(min_diff,abs(map[word1][i]-map[word2][j]));
            map[word1][i]<map[word2][j]?i++:j++;
        }
        return min_diff;
    }
private:
	unordered_map<string, vector<int>>map;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
//using hashmap and two pointers
class WordDistance {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for(int i=0;i<words.size();i++){
            map[words[i]].push_back(i);
        }

        if(word1==word2){
            int min_diff=INT_MAX;
            for(int i=0;i<map[word1].size()-1;i++){
                if(abs(map[word1][i]-map[word1][i+1])<min_diff){
                    min_diff=abs(map[word1][i]-map[word1][i+1]);
                }
            }
            return min_diff;
        }
        int i=0,j=0,min_diff=INT_MAX;
        while(i<map[word1].size&&j<map[word2]){
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

//two pointers
class WordDistance2 {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long dist=INT_MAX,i1=dist,i2=-dist;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){
                i1=i;
            }
            if(words[i]==word2){
                if(word1==word2){
                    i1=i2;
                }
                i2=i;
            }
            dist=min(dist,abs(i1-i2));
        }
        return dist;
    }
};
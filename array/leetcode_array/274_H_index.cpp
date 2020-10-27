class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());

        int hIndex=0;
        for(int i=0;i<citations.size();i++){
        	if(citations[i]>=(i+1)){
        		hIndex=i+1;
        	}
        }
        return hIndex;
    }
};


class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>papers(n+1,0);

        for(int c:citations){
        	if(c>=n){
        		papers[n]++;
        	}else{
        		papers[c]++;
        	}
        }

        int paper=0;
        for(int i=n;i>=0;i--){
        	paper+=hash[i];
        	if(paper>=i)return i;
        }
    }
};
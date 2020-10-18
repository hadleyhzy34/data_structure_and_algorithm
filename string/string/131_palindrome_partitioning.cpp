class Solution {
public:
    void checkPalindrome(string s, vector<vector<int>>&dp){
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            if(i<s.length()-1&&s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        for(int l=3;l<=s.length();l++){
            for(int i=0;i+l-1<s.length();i++){
                if(s[i]==s[i+l-1]&&dp[i+1][i+l-2]==1){
                    dp[i][i+l-1]=1;
                }
            }
        }
    }

    void checkPartition(string s,vector<string> &substring, vector<vector<string>>&res, int cur, vector<vector<int>>dp){
            if(cur==s.length()){
                res.push_back(substring);
                return;
            }
            for(int l=1;cur+l-1<s.length();l++){
                if(dp[cur][cur+l-1]==1){
                    substring.push_back(s.substr(cur,l));
                    checkPartition(s, substring,res,cur+l,dp);
                    substring.pop_back();
                }else{
                    continue;
                }
            }
        }

    vector<vector<string>> partition(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        checkPalindrome(s,dp);
        vector<vector<string>>res;
        vector<string>substring;
        checkPartition(s, substring, res, 0, dp);
        return res;
    }
};




class Solution2 {
public:
    bool checkPartition(string s){
        int n=s.size();
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }

    void partAll(vector<vector<string>> &res, vector<string> &subset, string s, int index){
        if(index==s.size()){
            res.push_back(subset);
            return;
        }
        int n=s.size();
        for(int i=index;i<n;i++){
            if(checkPartition(s.substr(index,i-index+1))){
                subset.push_back(s.substr(index,i-index+1));
                partAll(res,subset,s,i+1);
                subset.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        if(s.empty())return {};
        vector<vector<string>> res;
        vector<string> subset;
        partAll(res,subset,s,0);
        return res;
    }
};
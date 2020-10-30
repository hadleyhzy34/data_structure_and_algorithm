//string
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size()<=1)return s;
        unordered_map<char,int>map;
        int pos=0;
        for(auto ss:s){
            map[ss]++;
        }

        //key idea here is that return smallest char before first distinquished char that expired
        for(int i=0;i<s.length();i++){
            if(s[i]<s[pos])pos=i;
            if(--map[s[i]]==0)break;
        }
    
        char res=s[pos];
        string r=s.substr(pos+1);
        r.erase(std::remove(r.begin(),r.end(),res),r.end());
        // cout<<res<<" "<<pos<<" "<<s<<" "<<r<<endl;
        return s.length()==0?"":res+removeDuplicateLetters(r);
    }
};
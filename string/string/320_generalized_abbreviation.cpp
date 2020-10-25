//solution1, not meet requirements
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string>res;
        int n=word.size();
        for(int i=0;i<n;i++){
            for(int j=1;i+j-1<n;j++){
                string temp=word.substr(0,i);
                temp+=to_string(j);
                temp+=word.substr(i+j);
                cout<<word.substr(0,i)<<" "<<to_string(j)<<" "<<word.substr(i+j)<<endl;
                res.push_back(temp);
            }
        }
        return res;
    }
};


//
class Solution1 {
public:
    void gAbbreviations(vector<string>&res, string &temp, string word, int index){
        if(index>=word.size()){
            res.push_back(temp);
            return;
        }

        temp+=word[index];
        gAbbreviations(res,temp,word,index+1);
        temp=temp.substr(0,index);

        for(int i=1, index+i-1<word.size();i++){
            temp+=to_string(i);
            if(index+i<word.size()){
                temp+=word[index+i];
                gAbbreviations(res,temp,word,index+i+1);
                temp=temp.substr(0,temp.size()-1);
            }else{
                gAbbreviations(res,tmep,word,index+i);
                temp=temp.substr(0,temp.size()-1);
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string>res;
        int n=word.size();
        string temp;
        gAbbreviations(res,temp,word,0);
        return res;
    }
};
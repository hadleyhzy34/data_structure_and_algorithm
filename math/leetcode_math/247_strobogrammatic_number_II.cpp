class Solution {
public:
    vector<string> findString(int n,int m){
        if(n==1)return {"0","1","8"};
        if(n==2)return {"00","11","69","88","96"};
        vector<string> res;
        vector<string> r=findString(n-2,m);
        for(int i=0;i<r.size();i++){
            res.push_back("1"+r[i]+"1");
            res.push_back("8"+r[i]+"8");
            res.push_back("6"+r[i]+"9");
            res.push_back("9"+r[i]+"6");
            if(n<m)res.push_back("0"+r[i]+"0");
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        return findString(n, n);
    }
};

class Solution2 {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        vector<string>res_odd={"0","1","8"};
        vector<string>res_even={"11","69","88","96","00"};
        for(int i=3;i<=n;i++){
            if(i%2==0){
                int m=res_even.size();
                for(int j=0;j<m;j++){
                    res_even.push_back("1"+res_even[j]+"1");
                    res_even.push_back("8"+res_even[j]+"8");
                    res_even.push_back("6"+res_even[j]+"9");
                    if(i<n)res_even.push_back("0"+res_even[j]+"0");
                    res_even[j]="9"+res_even[j]+"6";
                }
            }else{
                int m=res_odd.size();
                for(int j=0;j<m;j++){
                    res_odd.push_back("1"+res_odd[j]+"1");
                    res_odd.push_back("8"+res_odd[j]+"8");
                    res_odd.push_back("6"+res_odd[j]+"9");
                    if(i<n)res_odd.push_back("0"+res_odd[j]+"0");
                    res_odd[j]="9"+res_odd[j]+"6";
                }
            }
        }
        return n%2==0?res_even:res_odd;
    }
};

//dp improved
class Solution3 {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        vector<string>res_odd={"0","1","8"};
        vector<string>res_even={"11","69","88","96","00"};
        int i=n%2==0?4:3;
        for(;i<=n;i+=2){
            if(i%2==0){
                int m=res_even.size();
                for(int j=0;j<m;j++){
                    res_even.push_back("1"+res_even[j]+"1");
                    res_even.push_back("8"+res_even[j]+"8");
                    res_even.push_back("6"+res_even[j]+"9");
                    if(i<n)res_even.push_back("0"+res_even[j]+"0");
                    res_even[j]="9"+res_even[j]+"6";
                }
            }else{
                int m=res_odd.size();
                for(int j=0;j<m;j++){
                    res_odd.push_back("1"+res_odd[j]+"1");
                    res_odd.push_back("8"+res_odd[j]+"8");
                    res_odd.push_back("6"+res_odd[j]+"9");
                    if(i<n)res_odd.push_back("0"+res_odd[j]+"0");
                    res_odd[j]="9"+res_odd[j]+"6";
                }
            }
        }
        return n%2==0?res_even:res_odd;
    }
};
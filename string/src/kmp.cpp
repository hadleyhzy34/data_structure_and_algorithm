#include <iostream>
#include <string>

void computeLPS(std::string pattern, int* lps)
{
    //length of previous of longest prefix and suffix
    int len = 0;
    int M = pattern.size();
    
    lps[0] = 0; //lps[0] is always 0
    int i = 1;
    while(i < M)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len==0){
                lps[i] = 0;
                i++;
            }else{
                len = lps[len-1];
            }
        }
    }
}

int kmp(std::string txt, std::string pat)
{
    int m = txt.size(); //length of text
    int n = pat.size(); //length of pattern

    int lps[n];
    computeLPS(pat,lps); //initialize longest prefix and suffix

    int i=0; //txt
    int j=0; //pat
    
    while(j<n)
    {
        if(txt[i] == pat[j])
        {
            j++;
            i++;
        }
        if(j == n){
            return i - j;
        }else{
            if(txt[i] != pat[j]){
                if(i == 0){
                    i++;
                }else{
                    computeLPS(pat,lps);
                }
            }
        }
    }
    return -1; //return -1 if tgt not matched src
}

int main(){

    return 0;
}

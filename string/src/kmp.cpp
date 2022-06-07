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

int kmp(std::string txt, std::string pat)
{
    int m = txt.size();
    int n = pat.size();

    int lps[n];
    computeLPS(pat,lps);

    int i=0; //txt
    int j=0; //pat
    while(i<m)
    {
        if(txt[i] == pat[j])
        {
            j++;
            i++;
        }
        if(i == m){
            return i - j;
        }else if(){

        }
    }
    return -1; //return -1 if tgt not matched src
}

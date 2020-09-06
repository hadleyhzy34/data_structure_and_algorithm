//
//  main.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 20.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::ofstream myfile;
//    myfile.open("fitness coach.html");
//    myfile<<"<body style=\"background-color:black;\">";
//    myfile<<std::endl;
//    for(int i=1;i<=255;i++){
//        myfile<<"<img src=\"fitness coach/hhh";
//        myfile<<i;
//        myfile<<".jpg\" alt=\"Girl in a jacket\" width=\"1250\">";
//        myfile<<std::endl;
//    }
//
//    std::ofstream myfile1;
//    myfile1.open("beautyleg.html");
//    myfile1<<"<body style=\"background-color:black;\">";
//    myfile1<<std::endl;
//    for(int i=1;i<=275;i++){
//        myfile1<<"<img src=\"beautyleg/hhh";
//        myfile1<<i;
//        myfile1<<".jpg\" alt=\"Girl in a jacket\" width=\"1250\">";
//        myfile1<<std::endl;
//    }
//
//    std::ofstream myfile3;
//    myfile3.open("sexroom.html");
//    myfile3<<"<body style=\"background-color:black;\">"<<std::endl;
//    for(int i=1;i<=186;i++){
//        myfile3<<"<img src=\"sexroom/hhh"<<i<<".jpg\" alt=\"Girl in a jacket\" width=\"1250\">"<<std::endl;
//    }
//
//    std::ofstream myfile4;
//    myfile4.open("weak.html");
//    myfile4<<"<body style=\"background-color:black;\">"<<std::endl;
//    for(int i=1;i<=449;i++){
//        myfile4<<"<img src=\"weak/hhh"<<i<<".jpg\" alt=\"Girl in a jacket\" width=\"1250\">"<<std::endl;
//    }
//
//    std::ofstream myfile5;
//    myfile5.open("houseteacher.html");
//    myfile5<<"<body style=\"background-color:black;\">"<<std::endl;
//    for(int i=1;i<=161;i++){
//        myfile5<<"<img src=\"houseteacher/hhh"<<i<<".jpg\" alt=\"Girl in a jacket\" width=\"1250\">"<<std::endl;
//    }
    
    vector<string>filename;
    vector<pair<string,int>>myfile;
    
    DIR *dir;
    struct dirent *ent;
    const char* t="/Users/hadley/Pictures/hhh";
    if ((dir = opendir (t)) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
          filename.push_back(ent->d_name);
//        printf ("%s\n", ent->d_name);
      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }
    
    for(auto x:filename){
        string st;
        int it=0;
        for(int i=0;i<x.length();i++){
            if(isdigit(x[i])){
                it=it*10+(x[i]-'0');
//                cout<<it<<endl;
            }else{
                st.push_back(x[i]);
            }
        }
        if(it>0&&!st.empty())myfile.push_back(make_pair(st, it));
    }
//    cout<<filename.size()<<endl;
    
    for(int i=0;i<myfile.size();i++){
        cout<<i<<" "<<myfile[i].first<<" "<<myfile[i].second<<endl;
    }
//    cout<<myfile.size()<<endl;
    
    vector<ofstream>outputFile(myfile.size());
    for(int i=0;i<myfile.size();i++){
        string temp=myfile[i].first+".html";
        outputFile[i].open(temp);
        outputFile[i]<<"<body style=\"background-color:black;\">"<<std::endl;
        outputFile[i]<<"<style>p{text-align: center;}</style><p>"<<std::endl;
        for(int j=1;j<=myfile[i].second;j++){
//            outputFile[i]<<"<img src=\"hhh/"<<myfile[i].first<<myfile[i].second<<"/"<<j<<".jpg\" alt=\"Girl in a jacket\" width=\"625\" class=\"center\">"<<std::endl;
            outputFile[i]<<"<img src=\"hhh/"<<myfile[i].first<<myfile[i].second<<"/"<<j<<".jpg\" alt=\"Girl in a jacket\" class=\"center\">"<<std::endl;
        }
        outputFile[i]<<"</p>"<<endl;
    }
    
    return 0;
}

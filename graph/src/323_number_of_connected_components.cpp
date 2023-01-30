#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

void checkCycle(int idx, int n, std::vector<std::vector<int>> &isConnected, std::vector<bool>& visited){
    visited[idx] = true;
    for(int i = 0; i < n; i++){
        // std::cout<<"idx: "<<idx<<"adj "<<i<<"connected status: "<<isConnected[idx][i]<<"visited status: "<<visited[i]<<std::endl;
        // if(i == idx)continue;
        if(visited[i]||!isConnected[idx][i])continue;
        checkCycle(i, n, isConnected, visited);
    }
}

int countComponents(int n, std::vector<std::vector<int>>& edges){
    std::vector<std::vector<int>> isConnected(n,std::vector<int>(n,0));
    for(int i = 0; i < edges.size();i++){
        isConnected[edges[i][0]][edges[i][1]] = 1;
        isConnected[edges[i][1]][edges[i][0]] = 1;
    }

    int numCities = isConnected.size();

    std::vector<bool> visited(numCities, false);
    
    int res = 0;
    for(int i = 0; i < numCities; i++){
        if(visited[i])continue;
        checkCycle(i, numCities, isConnected, visited);
        res++;
        std::cout<<i<<" new province is added"<<std::endl;
    }
    return res;
}

void checkGraph(int idx, int n, std::map<int, std::vector<int>> &p, std::vector<bool>& visited){
    visited[idx] = true;
    for(int i = 0; i < p[idx].size(); i++){
        if(visited[i])continue;
        checkGraph(p[idx][i], n, p, visited);
    }
}

int countComponents_v0(int n, std::vector<std::vector<int>>& edges){
    //std::vector<std::vector<int>> isConnected(n,std::vector<int>(n,0));
    std::set<int> check;
    std::map<int, std::vector<int>> pa;

    for(int i = 0; i < edges.size();i++){
        pa[edges[i][0]].push_back(edges[i][1]);
        pa[edges[i][1]].push_back(edges[i][0]);
    }

    std::vector<bool> visited(n, false);
    
    int res = 0;
    for(int i = 0; i < n; i++){
        if(visited[i])continue;
        checkGraph(i, n, pa, visited);
        res++;
        //std::cout<<i<<" new province is added"<<std::endl;
    }
    return res;
}

void checkGraph(int idx, int n, std::map<int, std::vector<int>> &p, std::set<int>& check){
    check.insert(idx);
    for(int i = 0; i < p[idx].size(); i++){
        if(check.find(p[idx][i])==check.end()){
            checkGraph(p[idx][i], n, p, check);
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>>& edges){
    //std::vector<std::vector<int>> isConnected(n,std::vector<int>(n,0));
    std::set<int> check;
    std::map<int, std::vector<int>> pa;

    for(int i = 0; i < edges.size();i++){
        pa[edges[i][0]].push_back(edges[i][1]);
        pa[edges[i][1]].push_back(edges[i][0]);
    }

    //std::vector<bool> visited(n, false);
    
    int res = 0;
    for(int i = 0; i < n; i++){
        if(check.find(i)==check.end()){
            checkGraph(i, n, pa, check);
            res++;
        }
    }
    return res;
}

#include <iostream>
#include <vector>
#include <queue>

void checkCycle(int idx, int n, std::vector<std::vector<int>> &isConnected, std::vector<bool>& visited){
    visited[idx] = true;
    for(int i = 0; i < n; i++){
        // std::cout<<"idx: "<<idx<<"adj "<<i<<"connected status: "<<isConnected[idx][i]<<"visited status: "<<visited[i]<<std::endl;
        // if(i == idx)continue;
        if(visited[i]||!isConnected[idx][i])continue;
        checkCycle(i, n, isConnected, visited);
    }
}

int findCircleNum(std::vector<std::vector<int>>& isConnected){
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

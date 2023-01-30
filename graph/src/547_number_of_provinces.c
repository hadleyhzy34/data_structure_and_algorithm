#include <stdlib.h>

void checkCycle(int idx, int n, int** isConnected, int* visited){
    visited[idx] = 1;
    for(int i = 0; i < n; i++){
        // std::cout<<"idx: "<<idx<<"adj "<<i<<"connected status: "<<isConnected[idx][i]<<"visited status: "<<visited[i]<<std::endl;
        // if(i == idx)continue;
        if(visited[i]||!isConnected[idx][i])continue;
        checkCycle(i, n, isConnected, visited);
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int res = 0;
    for(int i = 0; i < isConnectedSize; i++){
        if(isConnectedColSize[i])continue;
        checkCycle(i, isConnectedSize, isConnected, isConnectedColSize);
        res++;
    }
    return res;
}

#include <stdlib.h>
#include <stdbool.h>

bool checkCycle(int curCourses, int** adj, int adjSize, int* adjColSize, int* visited){
    if(visited[curCourses]==1){
        return true;
    }
    if(visited[curCourses]==0){
        visited[curCourses] = 1;
        for(int i = 0; i < adjColSize[curCourses]; i++){
            // if(visited[adj[curCourses][i]]==2)continue;
            if(checkCycle(adj[curCourses][i], adj, adjSize, adjColSize, visited))return true;
        }
    }

    visited[curCourses] = 2;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int* visited = (int*)malloc(numCourses*sizeof(int));
    // int visited[numCourses];
    for(int i=0;i<numCourses;i++){
        visited[i] = 0;
    }

    int* adj[numCourses];
    int adjSize = numCourses;
    int* adjColSize = (int*)calloc(numCourses, sizeof(int));
    
    for(int i = 0; i < prerequisitesSize; i++){
        adjColSize[prerequisites[i][0]]++;
    }
    //dynamically allocate space of each node's prerequisites
    for(int i = 0; i < numCourses; i++){
        adj[i] = (int*)malloc(adjColSize[i]*sizeof(int));
    }
    //dynamically assign graph edge
    int* curColSize = (int*)calloc(numCourses, sizeof(int));
    for(int i = 0; i < prerequisitesSize; i++){
        adj[prerequisites[i][0]][curColSize[prerequisites[i][0]]] = prerequisites[i][1];
        curColSize[prerequisites[i][0]]++;
    }
    //check each node
    for(int i = 0; i < numCourses; i++){
        if(checkCycle(i, adj, adjSize, adjColSize, visited))return false;
    }
    return true;
}

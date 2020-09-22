//
//  Graph.cpp
//  Graph
//
//  Created by Hadley on 10.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include "Graph.hpp"


void Graph2::DFSUtil(int v , bool visited[]) {
    visited[v] = true;
    std::cout<<v<<" ";
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

void Graph2::DFS(){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    //run DFS from all unvisited nodes including disconnected graph
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFSUtil(i, visited);
}

void Graph2::BFS(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        for (auto it = adj[q.front()].begin(); it != adj[q.front()].end(); ++it) {
            if (!visited[*it]) {
                q.push(*it);
                cout<<*it<<" ";
                visited[*it]=true;
            }
        }
        q.pop();
    }
}

bool Graph2::iscycle(){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    //run DFS from all unvisited nodes including disconnected graph
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            if(cycleUtil(i, visited, -1))return true;
        }
    }
    return false;
}

bool Graph2::cycleUtil(int v, bool visited[], int parent){
    visited[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            if(cycleUtil(*it, visited, v)){
                return true;
            }
        }else if(*it!=parent){
            return true;
        }
    }
    return false;
}

//detect cycle using bfs
bool Graph2::checkCycle(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    
    //initialize parents of all vertices to be -1
    vector<int> parent(V, -1);

    q.push(0);
    visited[0]=true;
    
    while(!q.empty()){
        for (auto it = adj[q.front()].begin(); it != adj[q.front()].end(); ++it) {
            if (!visited[*it]) {
                q.push(*it);
                visited[*it]=true;
                parent[*it]=q.front();
            }else if(parent[q.front()]!=*it){  //if parent node of current node is not visited it, then there must be a cycle
                return true;
            }
        }
        q.pop();
    }
    return false;
}

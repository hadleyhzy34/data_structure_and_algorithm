//
//  Graph.hpp
//  Graph
//
//  Created by Hadley on 10.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


//using vector for graph representation
class Graph1
{
public:
    int V; //No. of vertices
    //vector of vector representing edges
    vector<vector<int>> adj;
    //adding edges
    void addEdge(int v, int w)
    {
        if(v>=adj.size()||w>=adj.size()){
            return;
        }else{
            adj[v].push_back(w); // Add w to v’s list.
        }
    }
};

//using list for graph representation
class Graph2{
public:
    int V; //No. of vertices
    //vector of vector representing edges
    list<int> *adj;
    //adding edges
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }
    
    void DFSUtil(int v, bool visited[]);
    void DFS(); //dfs approach to print graph nodes
    void BFS(); //bfs approach to print graph nodes
    queue<int> q; //queue to store temporary vertics for bfs approach
    
    //detect cycle using dfs
    bool iscycle();
    bool cycleUtil(int v, bool visited[], int parent);
    
    //detect cycle using bfs
    bool checkCycle();
};

//using vector for graph node representation
class Node{
public:
    int val; //node's value
    vector<Node*> neighbors; //adjacent nodes that connected to this node
};

#endif /* Graph_hpp */

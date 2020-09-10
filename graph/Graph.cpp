//
//  Graph.cpp
//  
//
//  Created by Hadley on 10.09.20.
//

#include <stdio.h>
#include <vector>
#include <list>
using namespace std;


//using vector for graph representation
class Graph
{
    int V; //No. of vertices
    //vector of vector representing edges
    vector<vector<int>> adj(V);
    //adding edges
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }
}

//using list for graph representation
class graph
{
    int V; //No. of vertices
    //vector of vector representing edges
    list<adj> *adj;
    //adding edges
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }
}

//using vector for graph node representation
class Node{
public:
    int val; //node's value
    vector<Node*> neighbors; //adjacent nodes that connected to this node
}

int main(){
    list<int> test;
    test.push_back(1);
    test[0].next
    return 0;
}

# Graph
## Graph Representation
### using vector for graph representation
```c++
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
```
### using STL list for graph representation
```c++
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
```

### using vector for graph node representation
```c++
class Node{
public:
    int val; //node's value
    vector<Node*> neighbors; //adjacent nodes that connected to this node
}
```



## Depth First Search for a Graph

## Breadth First Search for a Graph


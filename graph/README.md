# Graph
## Topic
* [Graph Representation](https://github.com/hadleyhzy34/data_structure_and_algorithm/tree/master/graph#graph-representation)
* [DFS and BFS](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/DFS%20and%20BFS.md)
* [Detect Cycle](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/Detect%20Cycle.md)
* [Topological Sort](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/Topological%20Sort.md)
* [Shortest Paths](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/Shortest%20Paths.md)
* [Max Flow](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/Max%20Flow.md)

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


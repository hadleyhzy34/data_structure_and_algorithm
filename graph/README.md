# Graph
## Topic
* [Graph Representation](#graph-representation)
* [DFS and BFS](#dfs-and-bfs)
* [Detect Cycle](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/content/Detect%20Cycle.md)
* [Topological Sort](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/content/Topological%20Sort.md)
* [Shortest Paths](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/content/Shortest%20Paths.md)
* [Max Flow](https://github.com/hadleyhzy34/data_structure_and_algorithm/blob/master/graph/content/Max%20Flow.md)

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

## DFS and BFS
### Depth First Search for a Graph
```c++
void Graph::DFSUtil(int v , bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

void Graph::DFS(){
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    //run DFS from all unvisited nodes including disconnected graph
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFSUtil(i, visited);
}
```


### Breadth First Search for a Graph
```c++
void Graph::BFS(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        for (auto it = adj[q.top()].begin(); it != adj[q.top()].end(); ++it) {
            if (!visited[*it]) {
                q.push(*it);
                cout<<*it<<" ";
                visited[*it]=true;
            }
        }
        q.pop();
    }
}
```
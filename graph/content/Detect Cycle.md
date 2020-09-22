## Detect Cycle in an unDirected Graph
### DFS
approach: visit every nodes of graph by using DFS, For every visited vertex v, when we have found any adjacent vertex u, such that u is already visited, and u is not the parent of vertex v. Then one cycle is detected. 
```c++
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
        	//recur for unvisited node
            if(cycleUtil(*it, visited, v)){
                return true;
            }
        }else if(*it!=parent){     //if an adjacent is visited and it's not parent node
            return true;
        }
    }
    return false;
}
```
### BFS approach
```c++
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
```


## Detect Cycle in a Directed Graph
### DFS approach using three colors

### BFS approach

### Topological Sort

#include <iostream>
#include <vector>
#include <queue>>

bool checkCycle(int curCourses, std::vector<std::vector<int>> &adj, std::vector<bool>& visited){
    visited[curCourses] = true;
    for(int i = 0; i < adj[curCourses].size(); i++){
        if(visited[adj[curCourses][i]])return true;
        if(checkCycle(adj[curCourses][i], adj, visited))return true;
    }
    visited[curCourses] = false;
    return false;
}

bool canFinish_v0(int numCourses, std::vector<std::vector<int>>& prerequisites){
    std::vector<bool> visited(numCourses, false);
    std::vector<std::vector<int>> adj(numCourses);

    for(auto pre:prerequisites){
        adj[pre[0]].push_back(pre[1]);
    }

    for(int i = 0; i < numCourses; i++){
        if(checkCycle(i, adj, visited))return false;
    }
    return true;
}

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){
    std::vector<bool> visited(numCourses, false);
    std::vector<std::vector<int>> adj(numCourses);
    std::queue<int> nodes;
    std::vector<int> degrees(numCourses);
    int visited_nodes = 0;

    for(auto pre:prerequisites){
        adj[pre[1]].push_back(pre[0]);  //id of courses that can be taken only after taking this course
        ++degrees[pre[0]];  //number of prerequisites to be taken before taking this course
    }
    
    //push courses without prerequisites to queue
    for(int i = 0; i < numCourses; i++){
        if(degrees[i]==0){
            nodes.push(i);
        }
    }
    
    while(!nodes.empty()){
        int cur = nodes.front();
        nodes.pop();
        visited[cur] = true;
        visited_nodes++;

        std::cout<<"courses visited: "<<cur<<std::endl;
        for(int i = 0; i < adj[cur].size(); i++){
            degrees[adj[cur][i]]--;
            if(visited[adj[cur][i]]){
                return false;
            }
            if(degrees[adj[cur][i]]==0){
                nodes.push(adj[cur][i]);
            }
        }
    }

    return visited_nodes == numCourses?true:false;
}

int main()
{
    std::vector<std::vector<int>> prerequisites = {{0,1},{2,3},{3,4},{0,3}};
    bool res = canFinish(5,prerequisites);
    std::cout<<"can finished all courses"<<res<<std::endl;

    prerequisites = {{0,1},{3,2},{4,3},{0,3},{2,4}};
    res = canFinish(5,prerequisites);
    std::cout<<"can finished all courses"<<res<<std::endl;

    prerequisites = {{2,3},{3,2}};
    res = canFinish(4,prerequisites);
    std::cout<<"can finished all courses"<<res<<std::endl;
 
    return 0;
}

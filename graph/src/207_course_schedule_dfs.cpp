#include <iostream>
#include <vector>

class Solution {
public:
    bool checkCycle(int curCourses, std::vector<std::vector<int>> &adj, std::vector<int>& visited){
        visited[curCourses] = 1;
        for(int i = 0; i < adj[curCourses].size(); i++){
            if(visited[adj[curCourses][i]] == 2)continue;
            if(visited[adj[curCourses][i]] == 1)return true;
            if(checkCycle(adj[curCourses][i], adj, visited))return true;
        }
        visited[curCourses] = 2;  //mark current node visited, no cycles starting from this node
        return false;
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){
        std::vector<int> visited(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);
        
        //prerequisites for each course
        for(auto pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(checkCycle(i, adj, visited))return false;
        }
        return true;
    
    }
};

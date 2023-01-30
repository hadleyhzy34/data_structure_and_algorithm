#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){
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
            visited_nodes++;

            for(int i = 0; i < adj[cur].size(); i++){
                degrees[adj[cur][i]]--;
                if(degrees[adj[cur][i]]==0){
                    nodes.push(adj[cur][i]);
                }
            }
        }

        return visited_nodes == numCourses;
    }
};

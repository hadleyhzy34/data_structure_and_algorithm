
//topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>> edges(numCourses,vector<int>());
        queue<int> nodes;
        vector<int> indegrees(numCourses,0);
        vector<int> res;
        //x[0] courses to be taken, x[1] courses taken before x[0]
        for(auto x:prerequisites){
        	edges[x[1]].push_back(x[0]);
        	++indegrees[x[0]];
        }

        for(int i=0;i<indegrees.size();i++){
        	if(indegrees[i]==0){
        		nodes.push(i);
        	}
        }

        int visit_node=0;
        while(!nodes.empty()){
        	int index=nodes.front();
        	nodes.pop();
        	visit_node++;

        	res.push_back(index);
        	for(auto i:edges[index]){
        		indegrees[i]--;
        		if(indegrees[i]==0){
        			nodes.push(i);
        		}
        	}
        }
        // if(visit_node==numCourses){
        //     return res;
        // }else{
        //     return {};
        // }
        return visit_node==numCourses?res:vector<int>();
    }
};
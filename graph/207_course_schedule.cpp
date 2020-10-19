class Solution {
public:
	bool detectCycle(vector<vector<int>>&edges, ){
		
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n,vector<int>(n));
        for(auto x:prerequisites){
        	edges[x[0]].push_back(x[1]);
        }
    }
};
class Solution {
public:
	void countC(vector<vector<int>>&graph, int index, vector<bool> &visited){
		for(int i=0;i<graph[index].size();i++){
			if(visited[graph[index][i]]==true)continue;
			visited[graph[index][i]]=true;
			countC(graph,graph[index][i],visited);
		}
	}

    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
    	std::vector<vector<int>> graph(n);
    	for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
    	}
    	vector<bool> visited(n,false);
    	for(int i=0;i<graph.size();i++){
    		if(visited[i]==false){
    			countC(graph,i,visited);
                count++;
    		}
    	}
    	return count;
    }
};
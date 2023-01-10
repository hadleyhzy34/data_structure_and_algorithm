class Solution {
public:
	bool checkCycle(vector<vector<int>> &graph, int index, vector<bool> &visited, int parent){
		visited[index]=true;
		for(int i=0;i<graph[index].size();i++){
			if(visited[graph[index][i]]!=true){
				if(checkCycle(graph,graph[index][i],visited,index)){
					return true;
				}
			}else{
				if(graph[index][i]!=parent){
					return true;
				}
			}
		}
		return false;
	}

    bool validTree(int n, vector<vector<int>>& edges) {
    	vector<vector<int>> graph(n);
    	for(int i=0;i<edges.size();i++){
    		graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
    	}

    	vector<bool>visited(n,false);
    	if(!checkCycle(graph,0,visited,-1)){
            for(auto x:visited){
                if(x==false){
                    cout<<x<<endl;
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto e:edges){
        	graph[e[0]].insert(e[1]);
        	graph[e[1]].insert(e[0]);
        }

        vector<int>h;

        if(n==1){
        	return {0};
        }


        //create first layer
        for(int i=0;i<n;i++){
        	if(graph[i].size()==1){
        		h.push_back(i);
        	}
        }

        //bfs
        while(true){
        	vector<int>temp;
        	for(auto n:h){
        		for(auto g:graph[n]){
        			graph[g].erase(n);
        			if(graph[g].size()==1)temp.push_back(g);
        		}
        	}
            // for(auto hh:h){
            //     cout<<hh<<" ";
            // }
        	if(temp.empty())return h;
            h=temp;
        }  
    }
};
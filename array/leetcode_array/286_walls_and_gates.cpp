class Solution {
public:
	void dfs(vector<vector<int>> &rooms, int i, int j, int distance){
		if(i<0||i>=rooms.size()||j<0||j>=rooms[i].size()){
			return;
		}

		if(rooms[i][j]==-1){
			return;
		}

		if(distance<=rooms[i][j]){
			rooms[i][j]=distance;
			dfs(rooms,i-1,j,distance+1);
			dfs(rooms,i+1,j,distance+1);
			dfs(rooms,i,j-1,distance+1);
			dfs(rooms,i,j+1,distance+1);
		}
	}

    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()||rooms[0].empty())return;
    	int m=rooms.size(), n=rooms[0].size();

        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		if(rooms[i][j]==0){
        			dfs(rooms,i,j,0);
        		}
        	}
        }
    }
};
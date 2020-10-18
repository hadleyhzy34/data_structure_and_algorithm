class Solution {
public:
    void countIslands(vector<vector<char>>& grid, int i, int j){
        if(i<0||j<0||i>grid.size()-1||j>grid[i].size()-1)return;
        if(grid[i][j]=='1'){
            grid[i][j]=count+'0';
            countIslands(grid, i-1, j);
            countIslands(grid, i, j-1);
            countIslands(grid, i+1, j);
            countIslands(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        count=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    countIslands(grid, i, j);
                    count++;
                    // for(auto x:grid){
                    //     for(auto y:x){
                    //         cout<<y<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                }
            }
        }
        return count-2;
    }
private:
    int count;
};

class Solution2 {
public:
    void countIslands(std::vector<vector<char>> &grid, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j]='x';
            countIslands(grid,i,j+1);
            countIslands(grid,i,j-1);
            countIslands(grid,i-1,j);
            countIslands(grid,i+1,j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    countIslands(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    int count=0;
};
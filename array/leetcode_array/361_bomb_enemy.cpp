class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty())return 0;
        auto row=grid.size();
        auto col=grid[0].size();
        
        int rV[row][col];
        memset(rV, 0, sizeof(rV));
        
        int cV[row][col];
        memset(cV, 0, sizeof(cV));
        
        //accumulate enemies for each row
        for(int i=0;i<row;i++){
            if(grid[i][0]=='E')rV[i][0]=1;
            for(int j=1;j<col;j++){
                if(grid[i][j]=='0'){
                    rV[i][j]=rV[i][j-1];
                }
                if(grid[i][j]=='E'){
                    rV[i][j]=rV[i][j-1]+1;
                }
                if(grid[i][j]=='W'){
                    rV[i][j]=0;
                }
            }
        }
        
        //accumulate enemies for each col
        for(int j=0;j<col;j++){
            if(grid[0][j]=='E')cV[0][j]=1;
            for(int i=1;i<row;i++){
                if(grid[i][j]=='0'){
                    cV[i][j]=cV[i-1][j];
                }
                if(grid[i][j]=='E'){
                    cV[i][j]=cV[i-1][j]+1;
                }
                if(grid[i][j]=='W'){
                    cV[i][j]=0;
                }
            }
        }
        
        //adjust number of enemies for each row
        for(int i=row-1;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                // cout<<i<<" "<<j<<" "<<rV[i][j]<<" "<<rV[i][j+1]<<endl;
                if(grid[i][j]=='W'){
                    rV[i][j]=0;
                }else if(grid[i][j+1]!='W'){
                    rV[i][j]=rV[i][j+1];
                }
            }
        }
        
        cout<<endl;
        
        //adjust number of enemies for each col
        for(int j=col-1;j>=0;j--){
            for(int i=row-2;i>=0;i--){
                // cout<<i<<" "<<j<<" "<<cV[i][j]<<" "<<cV[i+1][j]<<endl;
                if(grid[i][j]=='W'){
                    cV[i][j]=0;
                }else if(grid[i+1][j]!='W'){
                    cV[i][j]=cV[i+1][j];
                }
            }
        }
        
        int maxKill=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='0'){
                    // cout<<i<<" "<<j<<" "<<cV[i][j]<<" "<<rV[i][j]<<endl;
                    maxKill=max((cV[i][j]+rV[i][j]),maxKill);
                }
            }
        }
        
        return maxKill;
    }
};
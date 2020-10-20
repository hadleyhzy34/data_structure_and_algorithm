class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return;
        dp.resize(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
        	for(int j=0;j<matrix[i].size();j++){
        		if(i==0&&j==0){
        			dp[i][j]=matrix[i][j];
        		}else if(j==0){
        			dp[i][j]=dp[i-1][j]+matrix[i][j];
        		}else if(i==0){
        			dp[i][j]=dp[i][j-1]+matrix[i][j];
        		}else{
        			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
        		}
        	}
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0&&col1==0){
        	return dp[row2][col2];
        }else if(row1==0){
        	return dp[row2][col2]-dp[row2][col1-1];
        }else if(col1==0){
        	return dp[row2][col2]-dp[row1-1][col2];
        }else{
        	return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
        }
    }
private:
	vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
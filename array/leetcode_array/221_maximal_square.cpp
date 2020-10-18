class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        
        auto row=matrix.size();
        auto col=matrix[0].size();
        int matrix_size[row][col];
        memset(matrix_size,0,sizeof(matrix_size));
        
        int maxArea=0;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0||j==0){
                    matrix_size[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'
                       &&matrix[i][j]==matrix[i-1][j]
                       &&matrix[i-1][j]==matrix[i][j-1]
                       &&matrix[i][j-1]==matrix[i-1][j-1]){
                        int temp=min(matrix_size[i-1][j],matrix_size[i][j-1]);
                        matrix_size[i][j]=min(temp, matrix_size[i-1][j-1])+1;
                    }else{
                        matrix_size[i][j]=matrix[i][j]-'0';
                    }
                }
                maxArea=max(maxArea,matrix_size[i][j]);
            }
        }
        return maxArea*maxArea;
    }
};

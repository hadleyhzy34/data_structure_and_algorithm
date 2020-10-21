class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size(), n=A[0].size(),p=B[0].size();

        vector<vector<int>> b(p,vector<int>(n));

        for(int i=0;i<n;i++){
        	for(int j=0;j<p;j++){
        		b[j][i]=B[i][j];
        	}
        }

        vector<vector<int>> res(m,vector<int>(p,0));
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		for(int k=0;k<p;k++){
        			res[i][k]+=A[i][j]*b[k][j];
        		}
        	}
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size(), n=A[0].size(),p=B[0].size();

        // vector<vector<int>> b(p,vector<int>(n));

        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<p;j++){
        // 		b[j][i]=B[i][j];
        // 	}
        // }

        vector<vector<int>> res(m,vector<int>(p,0));
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		if(A[i][j]==0)continue;
        		for(int k=0;k<p;k++){
        			res[i][k]+=A[i][j]*b[j][k];
        		}
        	}
        }
        return res;
    }
};
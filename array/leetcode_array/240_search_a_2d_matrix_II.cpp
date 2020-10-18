class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1])return false;
        
        int start_l=0,end_l=m-1;
        int start_r=0,end_r=m-1;
        
        while(start_l<end_l){
            int m=start_l+(end_l-start_l)/2;
            if(matrix[m][0]==target){
                return true;
            }else if(matrix[m][0]<target){
                if(matrix[m+1][0]>target){
                    end_l=m;
                    break;
                }else{
                    start_l=m+1;
                }
            }else{
                end_l=m-1;
            }
        }
        
        
        while(start_r<end_r){
            int m=start_r+(end_r-start_r)/2;
            if(matrix[m][n-1]==target){
                return true;
            }else if(matrix[m][n-1]<target){
                if(matrix[m+1][n-1]>=target){
                    start_r=m+1;
                    break;
                }else{
                    start_r=m+1;
                }
            }else{
                end_r=m-1;
            }
        }
        
        // cout<<end_l<<" "<<start_r<<endl;
        
        
        int l=max(start_r,0);
        int r=min(m-1,end_l);
        
        if(l>r)return false;
        for(int i=l;i<=r;i++){
            int ll=0,rr=n-1;
            while(ll<=rr){
                int mid=ll+(rr-ll)/2;
                // cout<<matrix[i][mid]<<endl;
                if(matrix[i][mid]==target){
                    return true;
                }else if(matrix[i][mid]<target){
                    ll=mid+1;
                }else{
                    rr=mid-1;
                }
            }
        }
        return false; 
    }
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int i=m-1,j=0;
        while(i>=0&&j<=n-1){
                if(matrix[i][j]==target){
                    return true;
                }else if(matrix[i][j]>target){
                    i=i-1;
                }else if(matrix[i][j]<target){
                    j=j+1;
                }
        }
        return false;
    }
};


//binary search
class Solution3 {
public:
    bool binarySearch(vector<int>matrix, int target){
        int n=matrix.size();
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[mid]==target){
                return true;
            }else if(matrix[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        int m=matrix.size();

        for(int i=0;i<m;i++){
            if(target<matrix[i][0]||target>matrix[i][matrix[i].size()-1])continue;
            if(binarySearch(matrix[i],target)){
                return true;
            }
        }
        
        return false;
    }
};

//divide and conquer
class Solution4 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        int m=matrix.size();

        for(int i=0;i<m;i++){
            if(target<matrix[i][0]||target>matrix[i][matrix[i].size()-1])continue;
            if(binarySearch(matrix[i],target)){
                return true;
            }
        } 
        return false;
    }
};